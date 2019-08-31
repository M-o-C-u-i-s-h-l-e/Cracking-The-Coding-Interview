#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    (s1 == s2) ? cout << "Yes\n" : cout << "No\n";
}





// Another Method
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> m1, m2;
    for (int i = 0; i < s1.size(); i++)
        m1[s1[i]]++;
    for (int i = 0; i < s2.size(); i++)
        m2[s2[i]]++;
    (m1 == m2) ? cout << "Yes\n" : cout << "No\n";
}
