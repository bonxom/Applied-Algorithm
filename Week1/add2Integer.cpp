#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a, b; cin >> a >> b;
    unsigned long long a_1 = a % 10; a/= 10;
    unsigned long long b_1 = b % 10; b/= 10;
    unsigned long long res_1 = a_1 + b_1;
    
    unsigned long long res = a + b;
    if (res_1 >= 10){
        res += 1;
        res_1 %= 10;
    }
    if (res > 0) cout << res;
    cout << res_1;
}
