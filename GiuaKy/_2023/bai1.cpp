#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1005;
int a[N];

int main(){
    cin >> n;
    int max_ = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        max_ = max(max_, a[i]); 
    }

    cout << max_ << endl;
}