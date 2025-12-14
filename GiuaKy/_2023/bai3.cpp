#include <bits/stdc++.h>
using namespace std;

int n, m, K;
const int N = 100, MAX = 1e9;
int tin[N];
int lb[N];
bool constrain[N][N];
bool curTeach[N][N];
bool teached[N];
unordered_set<int> canTeach[N];
int numClass[N];
int work[N];
int f = 0, f_opt = MAX;

bool check(int g, int s){
    if (teached[s]) return false; // alread teach
    
    if (canTeach[g].find(s) == canTeach[g].end()) return false;

    for (int i = 1; i <= n; i++){
        if (i != s && curTeach[g][i] && constrain[i][s]) return false; //conflig sub
    }
    if (work[g] + tin[s] > f_opt) return false; // bound

    return true;
}

//thử gán từng môn cho moi giáo viên
void Try(int k){
    for (int i = 1; i <= m; i++){
        if (check(i, k)) {
            teached[k] = true;
            work[i] += tin[k];
            curTeach[i][k] = true;
            numClass[i]++;

            if (k == n){
                bool flag = true;
                for (int i = 1; i <= m; i++){
                    if (numClass[i] < lb[i]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    int best = *max_element(work + 1, work + m + 1);
                    f_opt = min(f_opt, best);
                }
            } else Try(k + 1);
            teached[k] = false;
            work[i] -= tin[k];
            curTeach[i][k] = false;
            numClass[i]--;
        }
    }
}

int main(){
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        int p; cin >> p;
        for (int j = 1; j <= p; j++){
            int x; cin >> x;
            canTeach[i].insert(x);
        }
    }

    for (int i = 1; i <= n; i++){
        cin >> tin[i];
    }

    for (int i = 1; i <= m; i++){
        cin >> lb[i];
    }
    
    cin >> K;
    for (int i = 1; i <= K; i++){
        int p, q; cin >> p >> q;
        constrain[p][q] = true;
        constrain[q][p] = true;
    }

    Try(1);
    if (f_opt == MAX) cout << "-1" << endl;
    else cout << f_opt << endl;
}