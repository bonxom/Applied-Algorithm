#include <bits/stdc++.h>
using namespace std;

//query max between (i, j)
int n, m;
int a[100006];
int tree[100006];
const int INF = -100006;

void construct(int l, int r, int id){
    if (l == r){
        tree[id] = a[l]; 
        return;
    }
    int mid = (l + r) / 2;
    
    construct(l, mid, id * 2 + 1);
    construct(mid + 1, r, id * 2 + 2);

    tree[id] = max(tree[id * 2 + 1], tree[id * 2 + 2]);
}

void update(int pos, int val, int l, int r, int id){
    if (l == r){
        tree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(pos, val, l, mid, id * 2 + 1);
    else update (pos,val, mid + 1, r, id * 2 + 2);
    tree[id] = max(tree[id * 2 + 1], tree[id * 2 + 2]);
}

int query(int qL, int qR, int l, int r, int id){
    //total overlap
    if (qL <= l && qR >= r){
        return tree[id];
    }
    //no overlap
    if (qL > r || qR < l){
        return INF;
    }
    //partial overlap
    int mid = (l + r) / 2;
    return max(query(qL, qR, l, mid, id * 2 + 1),
                query(qL, qR, mid + 1, r, id * 2 + 2));
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    construct(0, n - 1, 0);
    // for (int i = 0; i < 2 * n - 1; i++){
    //     cout << tree[i] << " ";
    // }
    // cout << endl;
    cin >> m; 
    while (m--){
        string s; cin >> s;
        if (s == "get-max"){
            int i, j; cin >> i >> j;
            i--; j--;
            cout << query(i, j, 0, n - 1, 0) << endl; 
        }
        else if (s == "update"){
            int i, val; cin >> i >> val;
            update(i, val, 0, n - 1, 0);
        }
    }
}