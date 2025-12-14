#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
const int N = 1e7 + 5;
int a[N];
const ll MOD = 1e9 + 7;
int tmp[N];
ll cnt = 0;

void mergeSortAndCount(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    
    mergeSortAndCount(l, m);
    mergeSortAndCount(m + 1, r);
    
    int i = l, j = m + 1;
    int idx = l;
    while (i <= m && j <= r) {
        if (a[i] > a[j]){
            cnt = (cnt + (m - i + 1)) % MOD;
            tmp[idx++] = a[j++];
        } else {
            tmp[idx++] = a[i++];
        }
    }

    while (i <= m) {tmp[idx++] = a[i++];}
    while (j <= r) {tmp[idx++] = a[j++];}

    for (int i = l; i <= r; i++){
        a[i] = tmp[i];
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    mergeSortAndCount(1, n);
    cout << cnt << endl;
}