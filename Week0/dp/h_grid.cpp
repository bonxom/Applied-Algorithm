// https://atcoder.jp/contests/dp/tasks/dp_h
#include<bits/stdc++.h>
using namespace std;

int h, w;
const int N = 1005;
char a[N][N];
int res = 0;
const int MOD = 1e9 + 7;

// int dx[] = {1, 0};
// int dy[] = {0, 1};

// void loang(int i, int j){
//     a[i][j] = '#';
//     for (int k = 0; k < 2; k++){
//         int i1 = i + dy[k];
//         int j1 = j + dx[k];
//         if (i1 <= h && i1 >= 1 && j1 <= w && j1 >= 1 && a[i1][j1] == '.'){
//             loang(i1, j1);
//             if (i1 == h && j1 == w) res++;
//             res %= MOD;
//         }
//     }
//     a[i][j] = '.';
// }

// int main(){
//     cin >> h >> w;
//     for (int i = 1; i <= h; i++){
//         for (int j = 1; j <= w; j++){
//             cin >> a[i][j];
//         }
//     }
//     loang(1, 1);
//     cout << res << endl;
// }

int dp[N][N];
int dx[] = {0, -1};
int dy[] = {-1, 0};

int main(){
    cin >> h >> w;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            cin >> a[i][j];
        }
    }
    // dp[i][j] = sum(dp[i - dy[k]][j - dx[k]])
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            for (int k = 0; k < 2; k++){
                int i1 = i + dy[k];
                int j1 = j + dx[k];
                if (i1 >= 1 && i1 <= h && j1 >= 1 && j1 <= w && a[i1][j1] == '.'){
                    dp[i][j] += dp[i1][j1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    // for (int i = 1; i <= h; i++){
    //     for (int j = 1; j <= w; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[h][w] << endl;
}