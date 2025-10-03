#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1];
    int S[n + 1][m + 1];
    for (int i = 0; i <= n; i++){
        S[i][0] = 0;
    }
    for (int i = 0; i <= m; i++){
        S[0][i] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j];
        }
    }

    int q; cin >> q;
    while (q--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int res = S[r2][c2] - S[r2][c1-1] - S[r1-1][c2] + S[r1-1][c1-1];
        cout << res << endl;
    }
}
