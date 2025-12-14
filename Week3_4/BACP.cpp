#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 20;
vector<int> pre[N];
vector<int> adj[N];
int load[N];
int credit[N];
int learnAt[N];
int f_opt = INT_MAX;
vector<int> order;
int degree[N]; // bậc ở đỉnh để topo sort

bool check(int period, int course) {
    // cout << "check" << endl;
    if (learnAt[course]) {
        // cout << "1\n";
        return false; 
    } // đã học ở kỳ khác

    for (int &c : pre[course]) {  // chưa học môn tiên quyết hoặc môn tiên quyết hc sau
        if (!learnAt[c] || learnAt[c] >= period) {
            // cout << "2\n";
            return false; 
        }
    }
    
    if (load[period] + credit[course] > f_opt) {
        // cout << "3\n";
        return false; 
    } // ngắt sớm, load vượt tối ưu hiện tại

    return true;
}

void Try(int k){ // lặp từng khóa học thử gán cho từng period
    int course = order[k];

    for (int i = 1; i <= m; i++){
        if (check(i, course)) {
            // cout << "222333" << endl;
            load[i] += credit[course];
            learnAt[course] = i;

            if (k == n - 1) {
                int best = *max_element(load + 1, load + m + 1);
                f_opt = min(f_opt, best);
            } else Try(k + 1);
            
            load[i] -= credit[course];
            learnAt[course] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> credit[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (x) {
                pre[j].push_back(i);
                degree[j]++;
                adj[i].push_back(j);
            }
        }
    }

    // topo sort
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (degree[i] == 0){ 
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int &v : adj[u]) {
            degree[v]--;
            if (degree[v] == 0) q.push(v);
        }
    }

    Try(0);

    cout << f_opt << endl;
}