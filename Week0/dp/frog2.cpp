// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6;
const ll MAX_INT = LONG_LONG_MAX;
int n, k, h[N];
ll dp[N];


int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }

    //dp(i) = miN(dp(i), dp(i - 1) + h(i, i - 1), dp(i - 2) + h(i, i - 2),...
    fill(dp + 1, dp + n + 1, MAX_INT);
    dp[1] = 0;

    for (int i = 2; i <= n; i++){
        for (int j = max(1, i - k); j < i; j++){
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n] << endl;
}