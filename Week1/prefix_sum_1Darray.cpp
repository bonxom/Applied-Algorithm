#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    int sum = 0;
    int prefix_sum[n + 1];
    prefix_sum[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        prefix_sum[i + 1] = sum;
    }
    int q; cin >> q;
    
    while (q--){
        int start, end;
        cin >> start >> end;
        start--;
        end;
        // cout << "-------\n";
        // cout << prefix_sum[end] << " " << prefix_sum[start] << endl;
        cout << prefix_sum[end] - prefix_sum[start] << endl;

    }
}
