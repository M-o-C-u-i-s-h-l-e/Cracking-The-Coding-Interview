#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool rotate(vector<vector<int>> &v) {
	if (v.size() == 0 || v.size() != v[0].size())
		return false;
	for (int layer = 0, n = v.size(); layer < (n >> 1); layer++) {
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first; i < last; i++) {
			int offset = i - first, top = v[first][i];
			v[first][i] = v[last - offset][first];
			v[last - offset][first] = v[last][last - offset];
			v[last][last - offset] = v[i][last];
			v[i][last] = top;
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	if (rotate(v)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << v[i][j] << ' ';
			cout << endl;
		}
	} else {
		cout << "Can't Be Rotated\n";
	}
}
