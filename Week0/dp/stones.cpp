// https://atcoder.jp/contests/dp/tasks/dp_k
#include<bits/stdc++.h>
using namespace std;

int n, k;
const int N = 105, K = 1e5 + 5;
int a[N];
int dp[K];

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= n; j++){
            int x = a[j];
            if (x <= i && dp[i - x] == false){
                dp[i] = true;
                break;
            }
        }
    }

    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
}
