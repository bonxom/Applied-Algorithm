// https://atcoder.jp/contests/dp/tasks/dp_i

#include<bits/stdc++.h>
using namespace std;
using lb = long double;

int n;
lb ans = 0;
const int N = 3005;
lb p[N], dp[N][N]; 
// dp[i][j]: xác suất tại đồng xu i có đúng j đồng xu ngửa

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    
    dp[1][1] = p[1];
    dp[1][0] = 1 - p[1];
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= i; j++){
            dp[i][j] = dp[i-1][j] * (1-p[i]); // ko pick xu i
            if (j > 0) dp[i][j] += dp[i-1][j-1] * p[i]; //pick xu i
        }
    }

    for (int j = n/2+1; j <= n; j++){
        ans += dp[n][j];
    }

    cout << fixed << setprecision(10) << ans << endl;
}