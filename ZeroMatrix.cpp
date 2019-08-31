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





// Another Method
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void nullifyRow(vector<vector<int>> &v, int r) {
	for (int i = 0; i < v[0].size(); i++)
		v[r][i] = 0;
}

void nullifyCol(vector<vector<int>> &v, int c) {
	for (int i = 0; i < v.size(); i++)
		v[i][c] = 0;
}

void setZero(vector<vector<int>> &v) {
	bool firstRow = false, firstCol = false;
	for (int i = 0; i < v[0].size(); i++)
		if (v[0][i] == 0) {
			firstRow = true;
			break;
		}
	for (int i = 0; i < v.size(); i++)
		if (v[i][0] == 0) {
			firstCol = true;
			break;
		}
	for (int i = 1; i < v.size(); i++)
		for (int j = 1; j < v[0].size(); j++)
			if (v[i][j] == 0)
				v[i][0] = 0, v[0][j] = 0;
	for (vector<int> i : v) {
		for (int j : i)
			cout << j << ' ';
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i < v.size(); i++)
		if (v[i][0] == 0)
			nullifyRow(v, i);
	for (int i = 1; i < v[0].size(); i++)
		if (v[0][i] == 0)
			nullifyCol(v, i);
	if (firstRow)
		nullifyRow(v, 0);
	if (firstCol)
		nullifyCol(v, 0);
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
