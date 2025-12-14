#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
const int N = 1e6 + 5;
int a[N];
ll pre[N];
ll sum = 0;
ll minOdd = INT_MAX, minEven = 0; // dãy chẵn bắt đầu từ 0
ll best = 0;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        pre[i] = sum;
    }

    for (int i = 1; i <= n; i++){
        if (pre[i] % 2 == 0) {
            if (pre[i] < minEven) {
                minEven = pre[i];
            } else {
                best = max(best, pre[i] - minEven);
            }
        } else {
            if (pre[i] < minOdd) {
                minOdd = pre[i];
            } else {
                best = max(best, pre[i] - minOdd);
            }
        }
    }


    cout << best << endl;
}