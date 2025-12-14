#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll a, b;
const ll MOD = 1e9 + 7;

ll myPower(ll a, ll b) {
    if (b == 0) return 1;
    ll res = 1;
    
    a %= MOD;
    if (b % 2 == 0) {
        a = a * a % MOD;
        res = res * myPower(a, b / 2);
    } else {
        res = a * myPower(a, b - 1);
    }
    res %= MOD;
    return res;
}

int main(){
    cin >> a >> b;

    cout << myPower(a, b) << endl;
}