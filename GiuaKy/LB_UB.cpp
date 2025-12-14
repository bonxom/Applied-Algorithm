#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 30;
int a[N];
int lb, ub;
int cnt = 0;
bool visited[N];
int curSum = 0;

void Try(int k){
    for (int i = k; i <= n; i++){
        if (!visited[i]){
            visited[i] = true;
            curSum += a[i];

            if (curSum <= ub && curSum >= lb) cnt++;
            if (k < n) Try(k + 1);
            visited[i] = false;
            curSum -= a[i];
        }
    }    
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> lb >> ub;

    visited[1] = true;
    Try(1);

    cout << cnt << endl;
}