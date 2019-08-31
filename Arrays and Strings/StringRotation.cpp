#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool isRotated(string s1, string s2) {
	if (s1.size() != s2.size())
		return false;
	s1 += s1;
	for (int i = 0; i <= s1.size() - s2.size(); i++) {
		bool flag = true;
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i+j] != s2[j]) {
				flag = false;
				break;
			}
		}
		if (flag)
			return true;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s1, s2;
	cin >> s1 >> s2;
	(isRotated(s1, s2)) ? cout << "True\n" : cout << "False\n";
}
