#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1005;
int c[N][N];
int path[N];
int bestPath[N];
int f = 0, fopt = INT_MAX, cmin = INT_MAX;
bool visited[N];

void copyPath(){
    for (int i = 1; i <= n; i++){
        bestPath[i] = path[i];
    }
}

void Try(int k){
    vector<int> cand;
    cand.reserve(n);
    for (int city = 2; city <= n; city++) {
        if (!visited[city]) cand.push_back(city);
    }

    sort(cand.begin(), cand.end(), [&](int a, int b){
        return c[path[k-1]][a] < c[path[k-1]][b];
    });

    
    for (int i : cand) {
        if (!visited[i]){
            visited[i] = true;
            f += c[i][path[k-1]];
            path[k] = i;

            if (k == n){
                int f_last = f + c[path[n]][1];
                if (f_last < fopt){
                    fopt = f_last;
                    copyPath();
                }
            } else {
                int g = cmin * (n - k + 1) + f;
                if (g < fopt) Try(k + 1);
            }

            visited[i] = false;
            f -= c[i][path[k - 1]];
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

    cout << fopt << endl;
    for (int i = 1; i <= n; i++){
        cout << bestPath[i] << " ";
    }
}