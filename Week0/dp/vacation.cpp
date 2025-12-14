// https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int gift[N][4];
int n;
int dp[N][4]; //i -> day, j -> activity

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 3; j++) {
            cin >> gift[i][j];
        }
    }

    //dp[i][j] = max(dp[i - 1][k] + gift[i][j])   k != j

    dp[1][1] = gift[1][1];
    dp[1][2] = gift[1][2];
    dp[1][3] = gift[1][3];

    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= 3; j++){
            for (int k = 1; k <= 3; k++){
                if (k != j) {
                    dp[i][j] = max(dp[i - 1][k] + gift[i][j], dp[i][j]);
                }
            }
        }
    }

    cout << *max_element(dp[n] + 1, dp[n] + 4);
}
