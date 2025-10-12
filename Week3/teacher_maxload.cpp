#include <bits/stdc++.h>
using namespace std;

int n, m;
vector< set<int> > canTeach; //what subject teacher j can teach
int z;
vector< pair<int,int> > constrain;
int curTeach[10000]; //how many subjects belong to teacher
int visited[10000]; //what teacher teach this subject
int best = INT_MAX;

bool check(int i, int k){//check if teacher i can teach subj k
    if (visited[k] != -1) return false;
    if (canTeach[i].find(k) == canTeach[i].end()) return false;
    for (auto x : constrain){
        if (x.first == k && visited[x.second] == i) return false;
        if (x.second == k && visited[x.first] == i) return false; 
    }

    return true;
}

void Try(int k){
    for (int i = 0; i < m; i++){
        if (check(i, k)){
            visited[k] = i;
            curTeach[i]++;
            
            if (k == n-1) {
                best = min(best, *max_element(curTeach, curTeach + m));
            } else {
                if (*max_element(curTeach, curTeach + m) > best){
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
    memset(visited, -1, 10000);
    for (int i = 0; i < m; i++){
        int N; cin >> N;
        set<int> v;
        for (int j = 0; j < N; j++){
            int x; cin >> x;
            v.insert(x-1);
        }
        canTeach.push_back(v);
    }

    cin >> z;
    for (int i = 0; i < z; i++){
        int x, y; cin >> x >> y;
        constrain.push_back(pair(x-1, y-1));
    }

    Try(0);
    cout << best << endl;
}