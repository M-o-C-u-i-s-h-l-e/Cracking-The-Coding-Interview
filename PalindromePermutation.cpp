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





// Another Method
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    vector<int> v(26, 0);
    int odd = 0;
    for (int i = 0; i < str.size(); i++)
        (++v[str[i] - 'a'] & 1) ? odd++ : odd--;
    (odd > 1) ? cout << "False\n" : cout << "True\n";
}





// Another Method
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    long long odd = 0;
    for (int i = 0; i < str.size(); i++)
        odd ^= (1 << (str[i] - 'a'));
    (__builtin_popcount(odd) > 1) ? cout << "False\n" : cout << "True\n";
}
