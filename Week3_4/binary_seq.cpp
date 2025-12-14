#include <bits/stdc++.h>
using namespace std;

int n;
string s;
string cur = "";
int res = 0;

bool check(int i){
    string tmp = cur + to_string(i);
    if (tmp.length() < s.length()) return true;
    
    string sub = tmp.substr(tmp.length() - s.length(), s.length());
    if (sub == s) return false;
    
    return true;
}

void Try(int k){
    for (int i = 0; i <= 1; i++){
        if (check(i)) {
            string tmp = cur;
            cur = cur + to_string(i);

            if (k == n) res++;
            else Try(k + 1);
            cur = tmp;
        }
    }
}

int main(){
    cin >> n >> s;
    Try(1);

    cout << res << endl;
}