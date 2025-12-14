#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n;
int a[N];
int dp[N]; // max sum streak start from 1 ... i and end at a[i]

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = a[i]; // init all sum start at a[i]
    }
    
    for (int i = 2; i <= n; i++){
        dp[i] = max(dp[i], a[i] + dp[i - 1]);
    }

    cout << *max_element(dp + 1, dp + n + 1);

}