#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

//Để các Wj cân bằng, ta luôn nên nhét item tiếp theo vào subset hiện có tổng nhỏ nhất.
//Để giảm nguy cơ lệch, ta nên xử lý item nặng trước (vì quyết định với item to quan trọng hơn item nhỏ).

bool cmp(const pii &a, const pii &b){
    return a.first > b.first;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];

    // pair: (weight, index)
    vector<pii> items;
    items.reserve(n);
    for (int i = 1; i <= n; i++) {
        items.push_back({w[i], i});
    }

    sort(items.begin(), items.end(), cmp);

    // current_sum nhỏ hơn -> ưu tiên
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int j = 1; j <= m; j++) {
        pq.push({0, j});
    }

    vector<int> x(n + 1);
    vector<long long> sum(m + 1, 0);

    // Gán từng item nặng trước
    for (auto [wt, idx] : items) {
        auto [curSum, id] = pq.top();
        pq.pop();

        x[idx] = id;                 // item idx -> subset id
        curSum += wt;
        sum[id] = curSum;

        pq.push({curSum, id});
    }

    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}