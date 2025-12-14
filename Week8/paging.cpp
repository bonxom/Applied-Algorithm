// Given an array arr[] and an integer k, where arr[i] denotes the number of pages of a book and k denotes total number of students. 
// All the books need to be allocated to k students in contiguous manner, with each student getting at least one book. The task is to minimize the maximum number of pages allocated to a student. If it is not possible to allocate books to all students, return -1.
// Input
// Line 1: An array arr, elements are separated by a space
// Line 2: The number of student k
// Output
// One integer that is maximum number of pages allocated to a student
// Example
// Input
// 12 34 67 90
// 2
// Output
// 113

#include <bits/stdc++.h>
using namespace std;

bool canAllocate(const vector<int>& arr, int k, int maxPages) {
    int students = 1, sum = 0;
    for (int pages : arr) {
        if (pages > maxPages) return false;
        if (sum + pages > maxPages) {
            students++;
            sum = pages;
            if (students > k) return false;
        } else {
            sum += pages;
        }
    }
    return true;
}

int main() {
    string line;
    getline(cin, line);
    while (line.size() == 0) getline(cin, line);
    vector<int> arr;
    stringstream ss(line);
    int x;
    while (ss >> x) arr.push_back(x);
    int k;
    cin >> k;
    int n = arr.size();
    if (k > n) { cout << -1; return 0; }
    int low = arr[0], high = 0;
    for (int v : arr) { low = max(low, v); high += v; }
    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canAllocate(arr, k, mid)) { result = mid; high = mid - 1; }
        else low = mid + 1;
    }
    cout << result;
    return 0;
}
