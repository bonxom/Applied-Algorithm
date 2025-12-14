#include<bits/stdc++.h>
using namespace std;

vector<string> order;
unordered_map<string, int> mp;

int main(){
    string s;
    while (cin >> s && s != "#") {
        string time; cin >> time;
        mp[time]++;
        order.push_back(time);
    }

    sort(order.begin(), order.end());

    while (cin >> s && s != "###") {
        if (s == "?number_orders") {
            cout << order.size() << endl;
        } else if (s == "?number_orders_in_period") {
            string start, end; cin >> start >> end;
            int pos1 = lower_bound(order.begin(), order.end(), start) - order.begin();
            int pos2 = upper_bound(order.begin(), order.end(), end) - order.begin() - 1;
            cout << pos2 - pos1 + 1 << endl;
        } else if (s == "?number_orders_at_time") {
            string time; cin >> time;
            cout << mp[time] << endl;
        }
    }
}