#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e6 + 5;
int a[N];
int dp[N];

// int main(){
//     cin >> n;
//     for (int i = 1; i <= n; i++){
//         cin >> a[i];
//         dp[i] = 1;
//     }

//     for (int i = 2; i <= n; i++){
//         for (int j = 1; j < i; j++){
//             if (a[i] > a[j]){
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }

//     cout << *max_element(dp + 1, dp + n + 1) << endl;
// }

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> tail; // tail[i] = x -> dãy con tăng dài nhất có độ dài i kết thúc nhỏ nhất là x

    for (int i = 1; i <= n; i++){
        int pos = lower_bound(tail.begin(), tail.end(), a[i]) - tail.begin();
        if (pos == tail.size()) tail.push_back(a[i]);
        else tail[pos] = a[i];
    }

    cout << tail.size();
}