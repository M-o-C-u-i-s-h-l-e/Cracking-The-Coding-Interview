#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string solve(string str) {
	string s = "";
	int Count = 0;
	char c = str[0];
	for (int i = 0; i < str.size(); i++) {
		if (c == str[i]) {
			Count++;
		} else {
			s += c + to_string(Count);
			c = str[i];
			Count = 1;
		}
	}
	return (s.size() < str.size()) ? s : str;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string str;
	cin >> str;
	cout << solve(str) << endl;
}
