//https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6;
const int MAX_INT = 1e8;
int n, h[N];
ll dp[N];


int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }

    //dp(i) = miN(dp(i), dp(i - 1) + h(i, i - 1), dp(i - 2) + h(i, i - 2)
    dp[1] = 0;
    // memset(dp, MAX_INT, n + 1);
    dp[2] = dp[1] + abs(h[1] - h[2]);
    for (int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2] + abs(h[i - 2] - h[i]));
    }

    cout << dp[n] << endl;
}