// Với hai chuỗi cơ sở S1, S2, chuỗiFibonaci (Fibonaci string) 
// là một chuỗi vô tận được định nghĩa bằng FibStr(n) khi n tiến đến vô cùng, 
// trong đó FibStr(n) được định nghĩa bằng quan hệ quy nạp như sau:
// - FibStr(1) = S1   //len S1 = 1
// - FibStr(2) = S2
// - FibStr(n) = FibStr(n-1) + FibStr(n-2)
// o Với n > 2
// o “+” là toán tử nối hai chuỗi
// Cho trước S1, S2 và một số nguyên k, Hãy xác định ký tự nằm ở vị trí k trên chuỗi Fibonaci.
// Input
// Dòng 1: chuỗi     S1 (gồm các chữ cái, độ dài không quá 100 ký tự)
// Dòng 2: chuỗi     S2 (gồm các chữ cái, độ dài không quá 100 ký tự)
// Dòng      3: Một số nguyên k ( k < 1018)
// Output
// Chữ cái nằm ở vị trí k (chỉ số tính từ 0)


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string s1, s2;
ll k;
ll fibo[100];

char solve(int n, ll i){
    if (n == 1) return s1[i];
    if (n == 2) return s2[i];

    if (i < fibo[n-1]){
        return solve(n-1, i);
    } else {
        return solve(n-2, i - fibo[n-1]);
    }
}

int main(){
    cin >> s1 >> s2;
    cin >> k;

    fibo[1] = s1.size(); fibo[2] = s2.size();
    int n = 2;
    while (fibo[n] < k){
        n++;
        fibo[n] = fibo[n - 1] + fibo[n - 2];
    }
    cout << solve(n, k);
}