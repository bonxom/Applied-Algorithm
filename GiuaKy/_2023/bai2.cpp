#include<bits/stdc++.h>
using namespace std;

int n, D;
const int N = 1005;
int a[N];
int presum[N];
int Q = 0;

int main(){
    cin >> n >> D;
    int sum = 0;
    
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        presum[i] = sum;
    }

    for (int i = 0; i < n; i++){
        // for (int j = i + 1; j <= n; j++){
        //     if (presum[j] - presum[i] >= D) Q++;
        // }
        int target = presum[i] + D;
        int pos = lower_bound(presum + 1, presum + n + 1, target) - presum;
        Q += (n - pos + 1);
    }

    cout << Q << endl;
}