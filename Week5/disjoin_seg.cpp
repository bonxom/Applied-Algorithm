#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n;
pii a[100005];
int res = 1;


bool cmp(const pii &x, const pii &y){
    if (x.second != y.second) {
        return x.second < y.second;
    }
    return x.first > y.first;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        a[i] = pii(x, y);
    }    

    sort(a, a + n, cmp);
    int prev = a[0].second;
    // cout << " (" << a[0].first << " ," << a[0].second << ")";

    for (int i = 1; i < n; i++) {
        if (prev < a[i].first) {
            prev = a[i].second;
            res++;
            // cout << " -> (" << a[i].first << " ," << a[i].second << ")";
        }
    }

    cout << res << endl;
}