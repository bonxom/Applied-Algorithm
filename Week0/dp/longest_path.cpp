// https://atcoder.jp/contests/dp/tasks/dp_g
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 5;
vector<int> adj[N];
int dp[N]; // đường đi dài nhất kết thúc tại v
int degree[N]; //bậc của đỉnh

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);

        degree[v]++;
    }

    //topo sort: nghĩa là sắp xếp để u->v thì u phải được xử lý trước khi xử lý v
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (degree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);

        for (int &v : adj[u]) {
            degree[v]--; // giả sử bỏ u ra khỏi đồ thị
            if (degree[v] == 0) q.push(v);
        }
    }
    // dp
    for (int &i : topo){
        for (int &v : adj[i]){
            dp[v] = max(dp[v], dp[i] + 1);
        }
    }

    cout << *max_element(dp + 1, dp + n + 1);
}
