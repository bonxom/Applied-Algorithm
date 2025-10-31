#include <bits/stdc++.h>
using namespace std;
 
int n, c;
const int N = 1e6 + 5;
int a[N];
int res = 0;
 
bool check(int d){
    int cnt = 1;
    int l = a[0];
    for (int i = 1; i < n; i++){ //check with dis = d, can we choose c position
        if (a[i] - l >= d){
            l = a[i];
            cnt++;
        }
 
        if (c <= cnt) return true;
    }
 
    return false;
}
 
void solve(){
    sort(a, a + n);
    int l = 0, r = a[n - 1] - a[0];
 
    while (l < r){
        int mid = (l + r) / 2;
        if (check(mid)) { //if sastify dis = mid -> find a higher dis (in the right)
            res = mid;
            l = mid + 1;
        } else { //else find a smaller dis (in the left)
            r = mid;
        }
    }
 
    cout << res << endl;
}
 
int main() {
    int t; cin >> t;
    while (t--){
        cin >> n >> c;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
 
        solve();
    }
 
}