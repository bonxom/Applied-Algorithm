#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[100];
int X[100];
int currentSum = 0;
int res = 0;


void printSol(){
    for (int i = 1; i <= n; i++){
        cout << X[i];
        if (i != n) cout << " + ";
    }
    
    cout << endl;
}

void Try(int k){
    int lim = (m - n + k - currentSum) / a[k];
    for (int i = 1; i <= lim; i++){
        X[k] = i;
        currentSum += X[k] * a[k];

        if (k == n){
            if (currentSum == m) {
                res++;
                printSol();
            }
        } else {
            Try(k + 1);
        }

        currentSum -= X[k] * a[k];
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    Try(1);
    cout << res << endl;
}