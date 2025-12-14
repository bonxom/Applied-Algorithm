#include <bits/stdc++.h>
using namespace std;

int n;
const string str = "11";
string cur = "";

bool check(string s) {
    for (int i = 0; i <= n - str.length(); i++){
        if (s[i] - '0' == 1){
            string tmp = s.substr(i, str.length());
            // cout << i <<" " << tmp<< " sos: " << s << endl;
            if (tmp == str) {
                // cout << i << " : " << s << endl;
                return false;
            }
        }
    }

    return true;
}

void Try(int k){
    for (int i = 0; i <= 1; i++){
        string tmp = cur;
        cur = cur + to_string(i);

        if (k == n) {
            if (check(cur)) cout << cur << endl;
        } else Try(k + 1);
        cur = tmp;
    }
}

int main(){
    cin >> n;
    Try(1);
}