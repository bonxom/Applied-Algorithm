#include <bits/stdc++.h>
using namespace std;

int n, K, Q;
int d[100];
int c[100][100], cmin = INT_MAX;
int y[100]; //y[i] is first client of truck i (y[i] = 0 mean not use this truck)
int x[100]; //x[i] is next client after client i
//constraint: y[k] <= y[k + 1] (avoid repeat)
bool visited[100];
int load[100];
int f = 0, fopt = INT_MAX;
int nbr = 0; //nums of truck used
int segment = 0; //path => segment = n(#client) + nbr -> stop

bool checkX(int v, int k){
    if (v > 0 && visited[v]) return false;
    if (v > 0 && load[k] + d[v] > Q) return false;
    return true;
}

void Try_X(int s, int k){
    if (s == 0) { //if this truck has not used, try to use another one that has already used
        if (k < K) Try_X(y[k + 1], k + 1);
        return;
    }

    for (int v = 0; v <= n; v++){
        if (checkX(v, k)){
            x[s] = v;
            if (v > 0){
                visited[v] = true;
                load[k] += d[v];
            }
            f += c[s][v];
            segment++;
            
            if (v > 0) { //is not start point
                if (f + (n - (segment - nbr))*cmin < fopt) Try_X(v, k);
            } else {
                if (k == K){ //use all truck
                    if (segment == n + nbr) fopt = min(fopt, f);
                } else {
                    if (f + (n - (nbr + segment))*cmin < fopt) Try_X(y[k + 1], k + 1);
                }
            }

            segment--;
            f -= c[s][v];
            if (v > 0){
                load[k] -= d[v];
                visited[v] = false;
            }
        }
    }
}

bool checkY(int v, int k){
    if (v == 0) return true;
    if (visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

void Try_Y(int k){
    int s = 0;
    if (y[k - 1] > 0) {
        s = y[k - 1] + 1;
    }

    for (int v = s; v <= n; v++){
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0){
                visited[v] = true;
                load[k] += d[v];
                f += c[0][v];  
                segment++;     
            }

            if (k < K) {
                Try_Y(k + 1);   
            } else {
                nbr = segment;  
                Try_X(y[1], 1);  
            }

            if (v > 0){
                segment--;
                f -= c[0][v];
                load[k] -= d[v];
                visited[v] = false;
            }
            y[k] = 0;
        }
    }
}


int main(){
    cin >> n >> K >> Q;

    for (int i = 1; i <= n; i++) cin >> d[i];

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            cin >> c[i][j];
            if (i != j) cmin = min(c[i][j], cmin);
        }
    }


    y[0] = 0;
    Try_Y(1);
    cout << fopt << endl;
}
