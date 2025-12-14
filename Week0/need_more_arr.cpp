// https://codeforces.com/problemset/problem/2114/C
#include <bits/stdc++.h>
using namespace std;

int t, n;
const int N = 1e6;
int a[N];

int main(){
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int last = a[1];
        int cnt = 1;
        int i = 2;
        while (i <= n) {
            if (a[i] > last + 1) {
                last = a[i];
                cnt++;
                // cout << a[i] << endl;
            }
            i++;
        }

        cout << cnt << endl;
    }
}