#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    string s;
    while (cin >> s && s != "#"){
        if (s == "PUSH"){
            int x; cin >> x;
            st.push(x);
        }
        else {
            if (st.empty()) cout << "NULL\n";
            else{
                cout << st.top() << endl;
                st.pop();
            }
        }
    }
}
