// https://codeforces.com/problemset/problem/2126/B
#include<bits/stdc++.h>
using namespace std;

int t, n, k;
const int N = 1e5 + 5;
int a[N];

int main(){
    cin >> t;
    while (t--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int res = 0;
        int cur = 0;
        bool hiking = true;
        for (int i = 1; i <= n; i++) {
            if (hiking) {
                if (!a[i]) {
                    cur++;
                    if (cur == k) {
                        res++;
                        cur = 0;
                        hiking = false;
                    }
                } else {
                    cur = 0;
                }           
            } else {
                hiking = true;
            }
        }
        cout << res << endl;
    }
}