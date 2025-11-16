#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k1, k2; cin >> n >> k1 >> k2;

    int s0[n + 1], s1[n + 1]; //s0[i]: nums sol if day i off
                            //  s1[i]: nums sol if day i work
    memset(s0, 0, sizeof(s0));
    memset(s1, 0, sizeof(s1));
    s1[0] = 1;
    s0[0] = 1; // allow first day to be off
    for (int i = 1; i <= n; i++){
        s0[i] = s1[i - 1]; // i off => i-1 must work
        for (int j = k1; j <= k2; j++){
            if (i - j >= 0)
                s1[i] += s0[i - j]; // i work => last stop work at i - j
        }
    }

    cout << s0[n] + s1[n] << endl;
}
