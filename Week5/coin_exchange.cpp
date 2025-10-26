#include<bits/stdc++.h>
using namespace std;

int n, x;
int D[1000];
int dp[1006];
const int MAX = 10000;


void sol(){
    for (int i = 0; i < n; i++){
        dp[D[i]] = 1;
    }
    dp[0] = 0;

    for (int i = 1; i <= x; i += 1){
        for (int j = 0; j < n; j++){
            if (i - D[j] >= 0 && dp[i - D[j]] != MAX){
                dp[i] = min(dp[i - 1] + 1, dp[i - D[j]] + 1);
            }
        }
    }
}

int main(){
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> D[i];
    }
    
    fill(dp, dp + 1006, MAX);
    sort(D, D + n);
    sol();
    if (dp[x] != MAX)cout << dp[x] << endl;
    else cout << "-1" << endl;
}