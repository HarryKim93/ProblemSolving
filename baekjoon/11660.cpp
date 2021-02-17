#include <iostream>
#include <vector>

#define MAX_SIZE 1025

using namespace std;

int N, M;
int stRow, stCol, edRow, edCol;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> mat(MAX_SIZE, vector<int>(MAX_SIZE, 0));
    vector<vector<int>> cache(MAX_SIZE, vector<int>(MAX_SIZE, 0));    
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
            cache[i][j] = mat[i][j];
            if (i >= 1 && i < N) cache[i][j] += cache[i - 1][j];
            if (j >= 1 && j < N) cache[i][j] += cache[i][j - 1];
            if (((i >= 1 && i < N)) && (j >= 1 && j < N)) cache[i][j] -= cache[i - 1][j - 1];
        }
    }

    int ans = 0;

    for (int i = 0; i < M; i++) {
        cin >> stRow >> stCol >> edRow >> edCol;
        stCol--; stRow--; edCol--; edRow--;
        int minusCol = stCol - 1, minusRow = stRow - 1;
        ans = cache[edRow][edCol];

        if (minusCol >= 0) ans -= cache[edRow][minusCol];
        if (minusRow >= 0) ans -= cache[minusRow][edCol];
        if (minusCol >= 0 && minusRow >= 0) ans += cache[minusRow][minusCol];
        
        cout << ans << "\n";
    }

    return 0;
}