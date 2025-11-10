#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int cnt = 0;
vector< pii> revenue;
map<string, int> shopRevenue;
map<string, int> cusShopRevenue;
int totalRevenue = 0;

int timeToInt(string time){
    // cout <<  time.substr(0, 2) <<  time.substr(3, 2) <<  time.substr(6, 2) << endl;
    int hh = stoi( time.substr(0, 2) );
    int mm = stoi( time.substr(3, 2) );
    int ss = stoi( time.substr(6, 2) );

    return hh * 3600 + mm * 60 + ss;
}

bool cmp(const pii &a, const pii &b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    string cusID, prodID, shopID, time;
    int price;

    while (cin >> cusID && cusID != "#"){
        cin >> prodID >> price >> shopID >> time;
        int timeInt = timeToInt(time);
        cnt++;
        totalRevenue += price;
        revenue.push_back(pii(timeInt, price));

        if (shopRevenue.find(shopID) != shopRevenue.end()) {
            shopRevenue[shopID] += price;
        } else {
            shopRevenue[shopID] = price;
        }

        string cusShop = cusID + shopID;
        if (cusShopRevenue.find(cusShop) != cusShopRevenue.end()) {
            cusShopRevenue[cusShop] += price;
        } else {
            cusShopRevenue[cusShop] = price;
        }
    }

    string s;
    sort(revenue.begin(), revenue.end(), cmp);
    vector<int> times;
    vector<long long> pref(revenue.size() + 1, 0);
    times.reserve(revenue.size());

    for (int i = 0; i < (int)revenue.size(); i++) {
        times.push_back(revenue[i].first);
        pref[i + 1] = pref[i] + revenue[i].second;
    }

    while (cin >> s && s != "#"){
        if (s == "?total_number_orders") {
            cout << cnt << endl;
        } else if (s == "?total_revenue") {
            cout << totalRevenue << endl;
        } else if (s == "?revenue_of_shop") {
            cin >> shopID;
            cout << shopRevenue[shopID] << endl;
        } else if (s == "?total_consume_of_customer_shop") {
            cin >> cusID >> shopID;
            cout << cusShopRevenue[cusID + shopID] << endl;
        } else if (s == "?total_revenue_in_period") {
            string time1, time2;
            cin >> time1 >> time2;
            int time1_ = timeToInt(time1);
            int time2_ = timeToInt(time2);
            int l = lower_bound(times.begin(), times.end(), time1_) - times.begin();           
            int r = upper_bound(times.begin(), times.end(), time2_) - times.begin();

            long long res = 0;
            if (l < r) res = pref[r] - pref[l];
            cout << res << endl;
        }
    }
}
