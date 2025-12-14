#include <bits/stdc++.h>
using namespace std;

int n, c;
const int N = 1e7;
int x[N];
int res = 0;

bool check(int d){
    int last = x[1];
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (x[i] - last >= d) {
            cnt++;
            last = x[i];
        }
        if (cnt >= c) return true; 
    }
    return false;
}

void solve(){
    sort(x + 1, x + n + 1);

    int l = x[1], r = x[n] - x[0];
    while (l < r) { // binary search tìm khoảng cách thỏa mãn
        int m = (l + r) / 2;
        if (check(m)) {
            res = m;
            l = m + 1; //tăng khoảng cách lên
        } else {
            r = m; //giảm khoảng cách xuống
        }
    }

    cout << res << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        cin >> n >> c;
        for (int i = 1; i <= n; i++){
            cin >> x[i];
        }    

        solve();
    }

}