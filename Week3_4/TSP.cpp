#include<bits/stdc++.h>
using namespace std;

int n;
const int N = 25;
int c[N][N];
int f_opt = INT_MAX, f = 0;
bool visited[N];
int cmin = INT_MAX;
int path[N];

void Try(int k){
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            visited[i] = true;
            f += c[path[k - 1]][i];
            path[k] = i;

            if (k == n){
                f_opt = min(f_opt, f + c[path[n]][1]);
            } else {
                int g = f + cmin * (n - k + 1);
                if (g < f_opt) Try(k + 1);
            }

            visited[i] = false;
            f -= c[path[k - 1]][i];
        }
    }    
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> c[i][j];
            if (i != j) cmin = min(cmin, c[i][j]);
        }
    }

    visited[1] = true;
    path[1] = 1;
    Try(2);

    cout << f_opt << endl;
}