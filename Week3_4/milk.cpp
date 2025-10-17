#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100];
bool used[100];
int currentSum = 0;
int res = 0;

int path[100];
set<int> se;

void sol(){
    int i = 1;
    while (path[i] != 0) cout << a[path[i++]] << " ";
    cout << endl;
}

bool check(int i, int k){
    if (used[i]) return false;
    if (currentSum == 0 && se.find(i) != se.end()) return false;
    if (a[i] < a[path[k - 1]]) return false;
    return true;
}

void Try(int k){
    for (int i = k; i <= n; i++){
        if (check(i, k)){
            if (currentSum == 0) {
                // cout << "insert " << i << endl;
                se.insert(i);
            }
            path[k] = i;
            currentSum += a[i];
            used[i] = true;

            if (currentSum >= m){
                res++;
                // sol();
            }
            if (k < n) Try(k + 1);

            path[i] = 0;
            currentSum -= a[i];
            used[i] = false;
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;
    sort(a + 1, a + n + 1);
    Try(1);
    cout << res << endl;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, K;
//     if (!(cin >> n)) return 0;
//     vector<int> v(n);
//     for (int i = 0; i < n; ++i) cin >> v[i];
//     cin >> K;
//     int cnt = 0;
//     for (int mask = 0; mask < (1 << n); ++mask) {
//         int sum = 0;
//         for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += v[i];
//         if (sum >= K) ++cnt;
//     }
//     cout << cnt << endl;
//     return 0;
// }

 