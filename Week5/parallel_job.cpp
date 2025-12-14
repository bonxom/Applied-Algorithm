#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e6 + 6;
int d[N];
int t = 0;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> d[i];
    }
    sort(d + 1, d + n + 1, greater<int>());

    for (int i = 1; i <= n; i++) {
        t = max(i + d[i], t);
    }

    cout << t - 1 << endl;
}