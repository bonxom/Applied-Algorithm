// https://atcoder.jp/contests/dp/tasks/dp_f
#include<bits/stdc++.h>
using namespace std;

string s, t;
const int N = 3005;
int dp[N][N];

int main(){
    cin >> s >> t;

    for (int i = 1; i <= s.length(); i++) {
        dp[i][0] = 0; // nếu xâu t rỗng thì LCS = 0
    } 
    for (int j = 1; j <= t.length(); j++) {
        dp[0][j] = 0; //nếu xâu s rỗng
    }

    for (int i = 1; i <= s.length(); i++){
        for (int j = 1; j <= t.length(); j++){
            if (s[i - 1] == t[j - 1]){ // tang LCS
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // cout << dp[s.length()][t.length()] << endl;
    string res = "";
    int i = s.length(), j = t.length();
    while (i > 0 && j > 0){
        if (s[i - 1] == t[j - 1]) {
            res = res + s[i - 1];
            i--; j--;
        } else {
            if (dp[i - 1][j] >= dp[i][j - 1]) i--;
            else j--;
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

}