#include <bits/stdc++.h>
using namespace std;

int n, K;
int c[1000][1000];
bool visited[1000];
int cmin = INT_MAX;
int load = 0;
int path[1000];
int f = 0, fopt = INT_MAX;

bool check(int v){
    if (visited[v]) return false;
    if (v > n){ //return point
        if (!visited[v - n]) return false; //pick point not visit yet
    }
    else{
        if (load + 1 > K) return false;
    }
    return true;
}

void Try(int k){
    for (int i = 1; i <= 2 * n; i++){
        if (check(i)){
            path[k] = i;
            visited[i] = true;
            f += c[path[k-1]][i];

            if (i <= n) load += 1;
            else load -= 1;
            if (k == 2*n){
                if (f + c[i][0] < fopt){
                    fopt = f + c[i][0];
                }
            }
            else{
                if (f + cmin * (2*n+1-k) < fopt){
                    Try(k + 1);
                }
            }

            if (i <= n) load -= 1;
            else load += 1;
            f -= c[path[k-1]][i];
            visited[i] = false;
        }
    }
}

int main(){
    path[0] = 0;
    visited[0] = true;
    cin >> n >> K;
    for (int i = 0; i <= 2 * n; i++){
        for (int j = 0; j <= 2 * n; j++){
            cin >> c[i][j];
            if (i != j) cmin = min(cmin, c[i][j]);
        }
    }
    Try(1);

    cout << fopt << endl;
}