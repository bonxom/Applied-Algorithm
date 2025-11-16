#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l1, l2;
    cin >> n >> l1 >> l2;

    vector<long long> a(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = a[i];
    }

    for (int i = 1; i <= n; i++){
        int l = max(1, i - l2);
        int r = i - l1;
        // find max sum for dp[i]
        for (int j = l; j <= r; j++){
            dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }

    cout << *max_element(dp.begin() + 1, dp.end()) << endl;
}


    // deque<int> dq; // indices with decreasing dp values within [i - l2, i - l1]
    // long long ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     // remove indices that are too far (distance > l2)
    //     while (!dq.empty() && dq.front() < i - l2) dq.pop_front();

    //     int entering = i - l1;
    //     if (entering >= 0) {
    //         // maintain deque as decreasing by dp value
    //         while (!dq.empty() && dp[dq.back()] <= dp[entering]) dq.pop_back();
    //         dq.push_back(entering);
    //     }

    //     if (!dq.empty()) dp[i] = a[i] + dp[dq.front()];
    //     ans = max(ans, dp[i]);
    // }

    // cout << ans;