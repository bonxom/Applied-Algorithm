#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int total = 0;
map<string, int> mp; //acc - transfer money
map<string, set<string> > adj;
set<string> se;
set<string> visited;

int timeToInt(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));

    return h * 3600 + m * 60 + s;
}

bool isCycleK(string bank, string current, int depth, int k) {
    // cout << current << ": " << k << endl;
    if (k == depth) {
        // cout << "ok\n";
        auto it = adj.find(current);
        if (it == adj.end()) return false;
        return it->second.find(bank) != it->second.end();
    }

    auto it = adj.find(current);
    if (it == adj.end()) return false;

    for (auto &x : it->second) {
        if (visited.count(x)) continue;
        visited.insert(x);
        if (isCycleK(bank, x, depth + 1, k)) return true;
        visited.erase(x);
    }

    return false;
}

int main(){
    string from, to, time_point, atm;
    int time, money;

    while (cin >> from && from != "#") {
        cin >> to >> money >> time_point >> atm;
        time = timeToInt(time_point);
        cnt++; total += money;

        se.insert(from); se.insert(to);
        mp[from] += money;          // default 0 if not exist
        adj[from].insert(to); 
    
    }

    string s;
    while (cin >> s && s != "#") {
        if (s == "?number_transactions") {
            cout << cnt << endl;
        } else if (s == "?total_money_transaction") {
            cout << total << endl;
        } else if (s == "?list_sorted_accounts") {
            for (auto &x : se) {
                cout << x << " ";
            }
            cout << endl;
        } else if (s == "?total_money_transaction_from") {
            cin >> from;
            cout << mp[from] << endl;
        } else if (s == "?inspect_cycle") {
            string bank;
            int k;
            cin >> bank >> k;
            visited.clear();
            visited.insert(bank);
            
            cout << (isCycleK(bank, bank, 1, k) ? 1 : 0) << endl;
        }
    }
}