#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    string s;
    while (1){
        cin >> s;
        if (s == "#") break;
        else if (s == "PUSH"){
            int x; cin >> x;
            q.push(x);
        }
        else if (s == "POP"){
            if (q.empty()) cout << "NULL\n";
            else{
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
}
