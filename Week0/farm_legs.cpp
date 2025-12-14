// https://rb.vebo8.hair/truc-tiep/barcelona-vs-osasuna-RmmdPTa?fid=ywsq2kp&u=5
#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    cin >> t;
    while (t--){
        cin >> n;
        if (n % 2 != 0) cout << "0" << endl;
        else cout << n /4 + 1 << endl;
    }
}