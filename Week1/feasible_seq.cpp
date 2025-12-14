#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
const int N = 1e7 + 5;
int a[N];
ll pre[N];
ll sum = 0;
int maxLen = -1;

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        pre[i] = sum;
    }

    for (int i = 0; i <= n; i++){
        ll target = (ll)q + pre[i];
        if (target < 0) continue;
        int pos = upper_bound(pre + i, pre + n + 1, target) - (pre + 1);
        int len = pos - i;
        maxLen = max(maxLen, len);
    }

    cout << maxLen << endl;
}