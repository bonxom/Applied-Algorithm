#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e7;
int a[N], b[N];
multiset<int> se;
int res = 0;

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        se.insert(a[i]);
    }

    for (int i = 0; i < m; i++){
        cin >> b[i];
        if (se.find(b[i]) != se.end()) {
            se.erase(b[i]);
            res++;
        }
    }

    cout << res << endl;
}