#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    sort(str.begin(), str.end());
    bool flag = true;
    for (int i = 0; i < str.size()-1; i++)
        if (str[i] == str[i+1]) {
            flag = false;
            break;
        }
    (flag) ? cout << "Unique\n" : cout << "Not Unique\n";
}
