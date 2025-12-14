#include <bits/stdc++.h>
using namespace std;

int n, m, D;
const int N = 25;
int c[N][N], cmin = INT_MAX;
int assignTo[N];
int f_opt = INT_MAX, f = 0;
int load[N];

bool check(int staff, int task){
    if (assignTo[task]) return false;
    
    if (load[staff] + 1 > D) return false;
    
    if (f + c[staff][task] >= f_opt) return false; //bound
    int left = n - task;
    if (f + left * cmin + c[staff][task] >= f_opt) return false; 

    return true;
}

void Try(int k) { // k: task, i: staff
    for (int i = 1; i <= m; i++){
        if (check(i, k)) {
            assignTo[k] = i;
            load[i]++;
            f += c[i][k];
            
            // cout << k << endl;
            if (k == n) {
                // cout << "hello\n";
                f_opt = min(f_opt, f);
            } else Try(k + 1);
            
            assignTo[k] = 0;
            load[i]--;
            f -= c[i][k];
        }
    }
}

int main(){
    cin >> m >> n >> D;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }

    Try(1);

    if (f_opt == INT_MAX) cout << "-1" << endl;
    else cout << f_opt << endl; 
}