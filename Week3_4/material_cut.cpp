#include <bits/stdc++.h>
using namespace std;
 
int H, W, n;
vector<pair<int,int>> rects;       
vector<int> used;                  
vector<vector<int>> grid;        
 
bool first_empty(int &r, int &c) {
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (grid[i][j] == 0) { r = i; c = j; return true; }
    return false;
}
 
bool can_place(int r, int c, int h, int w) {
    if (r + h > H || c + w > W) return false;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (grid[r + i][c + j]) return false;
    return true;
}
 
void place(int r, int c, int h, int w, int val) {
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            grid[r + i][c + j] = val;
}
 
bool dfs(int placed) {
    if (placed == n) return true;           
 
    int r, c;
    if (!first_empty(r, c)) return true;    
 
    for (int i = 0; i < n; ++i) if (!used[i]) {
        int h = rects[i].first, w = rects[i].second;
 
        if (can_place(r, c, h, w)) {
            used[i] = 1;
            place(r, c, h, w, 1);
            if (dfs(placed + 1)) return true;
            place(r, c, h, w, 0);
            used[i] = 0;
        }
 
        if (h != w && can_place(r, c, w, h)) {
            used[i] = 1;
            place(r, c, w, h, 1);
            if (dfs(placed + 1)) return true;
            place(r, c, w, h, 0);
            used[i] = 0;
        }
    }
 
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    if (!(cin >> H >> W)) return 0;
    cin >> n;
    rects.resize(n);
    long long sumArea = 0;
    for (int i = 0; i < n; ++i) {
        int h, w; cin >> h >> w;
        rects[i] = {h, w};
        sumArea += 1LL * h * w;
    }
 
    if (sumArea > 1LL * H * W) {
        cout << 0 << "\n";
        return 0;
    }
 
    sort(rects.begin(), rects.end(), [](auto &A, auto &B){
        return 1LL*A.first*A.second > 1LL*B.first*B.second;
    });
 
    used.assign(n, 0);
    grid.assign(H, vector<int>(W, 0));
 
    cout << (dfs(0) ? 1 : 0) << "\n";
    return 0;
}