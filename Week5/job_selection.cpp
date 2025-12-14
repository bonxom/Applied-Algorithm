#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n;
const int N = 1e6;
pii a[N];
ll sum = 0;

bool cmp(const pii &a, const pii &b){
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

struct Compare{
    bool operator()(pii a, pii b) {
        if (a.second != b.second) return a.second > b.second; // ngược
        return a.first < b.first;
    }
};


int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x, y; cin >> x >> y; 
        a[i] = pii(x, y);
    }

    sort(a + 1, a + n + 1, cmp);

    priority_queue<pii, vector<pii>, Compare > q; 
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (cnt < a[i].first) {
            q.push(a[i]);
            cnt++;
        }
        else if (!q.empty()){
            pii u = q.top();
            if (u.second < a[i].second) {
                q.pop(); 
                q.push(a[i]);
            }
        }
    }

    while (!q.empty()){
        pii u = q.top();
        sum += u.second;
        q.pop();
    }

    cout << sum << endl;
}