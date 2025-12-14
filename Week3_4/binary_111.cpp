#include <bits/stdc++.h>
using namespace std;

int n; 
const string str = "111";
string cur = "";

bool check (string s) {
    // cout << "checck \n";
    for (int i = 0; i <= s.length() - 3; i++){
        if (s[i] - '0' == 1) {
            // cout << "hello" << endl;
            string tmp = s.substr(i, str.length());
            if (tmp == str) return true;
        }
    }
    return false;
}

void Try(int k) {
    for (int i = 0; i <= 1; i++){
        string tmp = cur;
        cur = cur + to_string(i);

        if (k == n){
            if (check(cur)) cout << cur << endl;
        } else Try(k + 1);

        cur = tmp;
    }
}

int main(){
    cin >> n;
    Try(1);

}