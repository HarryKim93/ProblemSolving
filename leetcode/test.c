#include <stdio.h>
#include <string.h>

#define PREFIX_MAX_DEPTH 2

int main() {
    int i = 0;
    char prefix_delimiter = ':';
    char *token = NULL;
    char keys[4][100];
    char key[100] = "hello:world:IamFind";
    
    int nkey = strlen(key);
    int prefix_depth = 0;

    while ((token = memchr(key + i + 1, prefix_delimiter, nkey - i - 1)) != NULL) {
        i = token - key;        
        prefix_depth++;

        printf("%d\n", i);

        if (prefix_depth >= PREFIX_MAX_DEPTH) {
            break;
        }
    }

    printf("%d %d\n", prefix_depth, strlen(key) - i);

    return 0;
}