#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int n, L;
pii a[100];
int currentL = 0;
bool visited[100];
int path[100];
int res = 0;

inline int dist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}   

bool check(int i, int k){
    if (visited[i]) return false;
    if (currentL + dist(a[i], a[path[k - 1]]) > L) return false;
    return true;
}

void Try(int k){
    for (int i = 1; i <= n; i++){
        if (check(i, k)){
            visited[i] = true;
            int dis = dist(a[i], a[path[k - 1]]);
            currentL += dis;
            path[k] = i;

            if (k == n) {
                if (currentL + dist(a[path[n]], a[path[1]]) <= L) res++;
            }
            else Try(k + 1);
            visited[i] = false;
            currentL -= dis;
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x, y; cin >>  x >> y;
        a[i] = {x, y};
    }
    cin >>  L;

    path[1] = 1;
    visited[1] =true;
    Try(2);
    cout << res << endl;
}