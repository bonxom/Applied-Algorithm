#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e4 + 5;
int x[N], y[N];
int dp[N][N]; //max len khi xét tại x[i], y[j]

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> x[i];
    }
    for (int j = 1; j <= m; j++){
        cin >> y[j];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (x[i] == y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;
}