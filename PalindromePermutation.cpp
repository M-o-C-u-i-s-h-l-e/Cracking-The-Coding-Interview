#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    map<char, int> m;
    for (int i = 0; i < str.size(); i++)
        m[str[i]]++;
    int val = 0;
    for (auto itr = m.begin(); itr != m.end(); itr++)
        if (itr->second & 1)
            val++;
    (val > 1) ? cout << "False\n" : cout << "True\n";
}
