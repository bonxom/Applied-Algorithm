// https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll best = 0;
int n, W;
const int N = 105;
ll w[N], v[N];
const int MAX_INT = 1e5 + 5;
ll dp[N][MAX_INT]; //max score can achive at pos i

int main(){
    cin >> n >> W;
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++){
        if (w[i] <= W)
            dp[i][w[i]] = v[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= W; j++){
            // not pick item i  
            dp[i][j] = dp[i - 1][j];
            //considet pick i
            if (j >= w[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    
    cout << *max_element(dp[n] + 1, dp[n] + W + 1) << endl;
}