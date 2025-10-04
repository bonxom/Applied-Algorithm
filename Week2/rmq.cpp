#include <bits/stdc++.h>
using namespace std;

int n, m;
int M[1000][100006], a[100006];

void preprocessing(){
    for (int j = 0; j < n; j++){
        M[0][j] = j;
    }

    for (int i = 1; (1 << i) <= n; i++){
        int ii = 1 << i;
        for (int j = 0; j + ii - 1 < n; j++){
            int iii = 1 << (i-1);
            if (a[M[i-1][j]] < a[M[i - 1][j + iii]]){
                M[i][j] = M[i-1][j];
            }
            else{
                M[i][j] = M[i-1][j + iii];
            }
        }
    }
}

void solve(){
    cin >> m;
    int i, j;
    int Q = 0;
    for (int t = 0; t < m; t++){
        cin >> i >> j;
        int k = log2(j - i + 1);
        if (a[M[k][i]] > a[M[k][j - (1 << k) + 1]]){
            Q += a[M[k][j - (1 << k) + 1]];
        } else Q += a[M[k][i]];
    }
    cout << Q << endl;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    preprocessing();
    // for (int  i =0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << M[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    solve();

}