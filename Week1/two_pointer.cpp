#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int res = 0;
    int left = 0, right = n-1;
    while (left < right){
        int sum = a[left] + a[right];
        if (sum == m) {
            res++;
            left++;
            right--;
        } else if (sum > m) {
            right--;
        } else {
            left++;
        }
    }
    cout << res;
}
