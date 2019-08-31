#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool oneEditReplace(string s1, string s2) {
	bool foundDiff = false;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) {
			if (foundDiff)
				return false;
			foundDiff = true;
		}
	}
	return true;
}

bool oneEditInsert(string s1, string s2) {
	int idx1 = 0, idx2 = 0;
	while (idx1 < s1.size() && idx2 < s2.size()) {
		if (s1[idx1] != s2[idx2]) {
			if (idx1 != idx2)
				return false;
			idx2++;
		} else {
			idx1++, idx2++;
		}
	}
	return true;
}

bool oneEditAway(string s1, string s2) {
	if (s1.size() == s2.size())
		return oneEditReplace(s1, s2);
	else if (s1.size() + 1 == s2.size())
		return oneEditInsert(s1, s2);
	else if (s1.size() - 1 == s2.size())
		return oneEditInsert(s2, s1);
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s1, s2;
	cin >> s1 >> s2;
	(oneEditAway(s1, s2)) ? cout << "True\n" : cout << "False\n";
}
