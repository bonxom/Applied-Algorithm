#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    multiset<int> se;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        se.insert(x);
    }
    
    string s;
    while (cin >> s && s != "#"){
        if (s == "insert"){
            int x; cin >> x;
            se.insert(x);
        }
        else if (s == "remove"){
            int x; cin >> x;
            se.erase(x);
        }
        else if (s == "min_greater"){
            int x; cin >> x;
            auto it = se.upper_bound(x);
            if (it == se.end()) cout << "NULL\n";
            else cout << *it << endl;
        }
        else{
            int x; cin >> x;
            auto it = se.lower_bound(x);
            if (it == se.end()) cout << "NULL\n";
            else cout << *it << endl;
        }
    }
}
