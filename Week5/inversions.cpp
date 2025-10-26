#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e6 + 6;
int a[N];
int tmp[N];
int cnt = 0;
const int MOD = 1e9 + 7;

void mergeSortAndCount(int left, int right){
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSortAndCount(left, mid);
    mergeSortAndCount(mid + 1, right);

    int k = left, i = left, j = mid + 1; //2 sorted array (left, mid) and (mid + 1, right)
    while (i <= mid && j <= right){
        if (a[i] > a[j]) {
            tmp[k++] = a[j++];
            cnt += mid - i + 1; // a[i] -> a[mid] is always bigger than a[j]
            cnt %= MOD;
        } else {
            tmp[k++] = a[i++];
        }
    }

    while (i <= mid) tmp[k++] = a[i++];
    while (j <= right) tmp[k++] = a[j++];

    for (int i = left; i <= right; i++){
        a[i] = tmp[i];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    mergeSortAndCount(0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    cout << cnt << endl;
}