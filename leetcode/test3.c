#include <stdio.h>
#include <string.h>

int main()
{
    char s1[10] = "aac";
    char s2[10] = "aaba";

    printf("strncmp : %d\n", strncmp(s1,s2,3)); //strncmp

    return 0;
}