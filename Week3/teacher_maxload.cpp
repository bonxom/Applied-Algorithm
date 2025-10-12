#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> canTeach[1000]; //what subject teacher j can teach
int z;
vector< pair<int,int> > constrain;
int curTeach[1000]; //how many subjects belong to teacher
int visited[1000]; //what teacher teach this subject
int best = INT_MAX;

bool check(int i, int k){//check if teacher i can teach subj k
    if (visited[k] != -1) return false;
    if (canTeach[i].find(k) == canTeach[i].end()) return false;
    for (auto &x : constrain){
        if (x.first == k && visited[x.second] == i) return false;
        if (x.second == k && visited[x.first] == i) return false; 
    }

    return true;
}

void Try(int k){
    for (int i = 1; i <= m; i++){
        if (check(i, k)){
            visited[k] = i;
            curTeach[i]++;
            
            int load = *max_element(curTeach + 1, curTeach + m + 1);
            if (k == n) {
                best = min(best, load);
            } else {
                if (load > best){
                    visited[k] = -1;
                    curTeach[i]--;
                    continue;
                }
                Try (k + 1);
            }

            visited[k] = -1;
            curTeach[i]--;
        }
    }
}

int main(){
    //m: teachers, n: subjecs
    cin >> m >> n;
    memset(visited, -1, 1000);
    for (int i = 1; i <= m; i++){
        int N; cin >> N;
        set<int> v;
        for (int j = 0; j < N; j++){
            int x; cin >> x;
            v.insert(x);
        }
        canTeach[i] = v;
    }

    cin >> z;
    for (int i = 0; i < z; i++){
        int x, y; cin >> x >> y;
        constrain.push_back(pair(x, y));
    }

    Try(1);
    if (best != INT_MAX) cout << best << endl;
    else cout << "-1" << endl;
}