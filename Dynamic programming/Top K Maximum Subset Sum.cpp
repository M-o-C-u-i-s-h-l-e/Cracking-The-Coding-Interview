// I have an array of numbers say [1,2,3,1,1000], now I want to get all possible combinations of this 
// array and calculate its sum. Combinations are valid such that two combinations have different subset 
// of elements. Then order all the sum values in descending order and get the top k elements.

// Sample Input:
// 3         -> n
// 3 5 -2    -> array
// 5         -> k

// Sample Output:
// 8 6 5 3 3
  
// Constraints:
// Array size n = 1 to 10^5
// Array elements -10^9 to 10^9
// k ranges from 1 to 2000





#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * k * log(k))
vector<long> bestCombo(vector<int> popularity, int k) {
    long n = popularity.size(), maxSum = 0;
    vector<int> positive, negative;
    for (int i = 0; i < n; ++i) {
        if (popularity[i] >= 0)
            maxSum += popularity[i];
        (popularity[i] >= 0) ? positive.push_back(popularity[i]) : negative.push_back(popularity[i]);
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
    multiset<long, greater<long>> sums;
    sums.insert(maxSum);
    int previous = INT_MIN;
    vector<long> prevAddedSum, sumsToIterate;
    for (int i = 0; i < positive.size(); ++i) {
        if (positive[i] == previous) {
            sumsToIterate = prevAddedSum;
        } else {
            sumsToIterate.assign(sums.begin(), sums.end());
        }
        prevAddedSum = {};
        for (int j = 0; j < sumsToIterate.size(); ++j) {
            long newSum = sumsToIterate[j] - positive[i];
            sums.insert(newSum);
            prevAddedSum.push_back(newSum);
            while (sums.size() > k)
                sums.erase(--(sums.end()));
        }
        previous = positive[i];
    }
    previous = INT_MAX;
    for (int i = negative.size()-1; i >= 0; --i) {
        if (negative[i] == previous) {
            sumsToIterate = prevAddedSum;
        } else {
            sumsToIterate.assign(sums.begin(), sums.end());
        }
        prevAddedSum = {};
        for (int j = 0; j < sumsToIterate.size(); ++j) {
            long newSum = sumsToIterate[j] + negative[i];
            sums.insert(newSum);
            prevAddedSum.push_back(newSum);
            while (sums.size() > k)
                sums.erase(--(sums.end()));
        }
        previous = negative[i];
    }
    vector<long> result(sums.begin(), sums.end());
    return result;
}

// // Brute Force Approach
// // Time Complexity: O(2 ^ n)
// vector<long> bestCombo(vector<int> popularity, int k) {
//     int n = popularity.size();
//     vector<long> v;
//     long total = pow(2l, n);
//     for (int i = 0; i < total; ++i) {
//         long sum = 0;
//         for (int j = 0; j < n; ++j)
//             if (i & (1 << j))
//                 sum += popularity[j];
//         v.push_back(sum);
//     }
//     sort(v.begin(), v.end(), greater<long>());
//     v.erase(v.begin()+k, v.end());
//     return v;
// }

int main(void) {
    int n, k;
    cin >> n;
    vector<int> popularity(n);
    for (int i = 0; i < n; ++i)
        cin >> popularity[i];
    cin >> k;
    vector<long> result = bestCombo(popularity, k);
    for (int i: result)
        cout << i << ' ';
    cout << endl;
}
