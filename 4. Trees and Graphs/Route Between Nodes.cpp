// N -> No. of vertices
// 0 -> Not visited, 1 -> Visiting, 2 -> Visited

bool search(vector<vector<int>> adj, int start, int end) {
	if (start == end)
		return true;

	queue<int> q;
	vector<int> visited(N+1, 0);
	visited[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int cur = q.first();
		q.pop();
		for (int i: adj[cur]) {
			if (visited[i] == 0) {
				if (i == end) {
					return true;
				} else {
					visited[i] = 1;
					q.push(i);
				}
			}
		}
		visited[cur] = 2;
	}
	return false;
}
