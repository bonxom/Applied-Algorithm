#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e6 + 5;
int a[N];
int tmp[N];

void mergeSort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);

    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] < a[j]){
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }

    while (i <= m) {
        tmp[k++] = a[i++];
    }
    while (j <= r){
        tmp[k++] = a[j++];
    }

    for (int k = l; k <= r; k++) {
        a[k] = tmp[k];
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; 
    }

    mergeSort(1, n);
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
}