#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1005;
int a[N];

int main(){
    cin >> n;
    int odd = 0, even = 0;
    int curOdd = 0, curEven = 0;
    int lastOdd = -1, lastEven = -1;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        if (a[i] % 2 != 0){
            // cout << a[i] << " ";
            if (lastOdd == -1) {
                curOdd++;
                // cout << "1\n";
            } else if (a[i] > a[lastOdd]) {
                curOdd++;
                // cout << "2\n";
            } else {
                odd = max(odd, curOdd);
                curOdd = 1;
                // cout << "3\n";
            }
            lastOdd = i;
            // cout << "max odd: " << odd << endl;
        } else {
            if (lastEven == -1){
                curEven++;
            } else if (a[i] > a[lastEven]) {
                curEven++;
            } else {
                even = max(even, curEven);
                curEven = 1;
            }
            lastEven = i;

        }
        if (i == n-1){
            odd = max(odd, curOdd);
            even = max(even, curEven);
        }
    }

    // cout << odd << " " << even << endl;
    cout << max(even, odd) << endl;
}