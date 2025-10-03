#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for (int &x : a){
        cin >> x;
    }

    string s;
    sort(a, a + n);
    while (cin >> s && s != "#"){
        int x; cin >> x;
        auto it = upper_bound(a, a + n, x);
        if (it == a + n) cout << "-1" << endl;
        else cout << *it << endl;
    }
}
