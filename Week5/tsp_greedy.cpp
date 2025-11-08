#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
int n;
int c[N][N];
bool used[N];
int order1[N];
vector<int> order2;
vector<ll> sum;

bool cmp(int a, int b){
    if (sum[a] != sum[b]) return sum[a] < sum[b];
    return a < b;
}

int solve1(){
    int cost = 0;
    int cur = 1;
    used[1] = true;
    order1[0] = 1;

    for (int k = 1; k < n; k++) {
        int nxt = -1;
        int best = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!used[j] && c[cur][j] < best) {
                best = c[cur][j];
                cost += best;
                nxt = j;
            }
        }

        used[nxt] = true;
        order1[k] = nxt;
        cur = nxt;
    }
    return cost;
}

int solve2(){
    sum.resize(n + 1, 0); //tong khoang cach tung tpho
    for (int i = 1; i <= n; i++) {
        long long s = 0;
        for (int j = 1; j <= n; j++) s += c[i][j];
        sum[i] = s;
    }

    // Giữ x1 = 1, sort các city còn lại theo sum tăng dần
    order2.reserve(n);
    order2.push_back(1);


    for (int i = 2; i <= n; i++) order2.push_back(i);

    sort(order2.begin() + 1, order2.end(), cmp);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    if (solve1() < solve2()){   
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << order1[i] << (i + 1 == n ? '\n' : ' ');
        }
    } else {
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << order2[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
}

