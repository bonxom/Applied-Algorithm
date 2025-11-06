#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1005;
int c[N][N];
vector<ll> sum;

bool cmp(int a, int b){
    if (sum[a] != sum[b]) return sum[a] < sum[b];
    return a < b;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    sum.resize(n + 1, 0); //tong khoang cach tung tpho
    for (int i = 1; i <= n; i++) {
        long long s = 0;
        for (int j = 1; j <= n; j++) s += c[i][j];
        sum[i] = s;
    }

    // Giữ x1 = 1, sort các city còn lại theo sum tăng dần
    vector<int> order;
    order.reserve(n);
    order.push_back(1);


    for (int i = 2; i <= n; i++) order.push_back(i);

    sort(order.begin() + 1, order.end(), cmp);

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << order[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
