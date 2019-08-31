#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void setZero(vector<vector<int>> &v) {
	vector<bool> row(v.size(), false), col(v[0].size(), false);
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[0].size(); j++)
			if (v[i][j] == 0)
				row[i] = true, col[j] = true;
	for (int i = 0; i < row.size(); i++)
		if (row[i])
			for (int j = 0; j < v[0].size(); j++)
				v[i][j] = 0;
	for (int i = 0; i < col.size(); i++)
		if (col[i])
			for (int j = 0; j < v.size(); j++)
				v[j][i] = 0;
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
	setZero(v);
	for (vector<int> i : v) {
		for (int j : i)
			cout << j << ' ';
		cout << endl;
	}
}
