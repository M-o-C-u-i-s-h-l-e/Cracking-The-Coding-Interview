// N -> No. of vertices
// 0 -> Not visited, 1 -> Visiting, 2 -> Visited

bool dfs(int cur, vector<vector<int>> &adj, vector<int> &visited, vector<int> &res) {
	if (visited[cur] == 1)
		return false;
	if (visited[cur] == 0) {
		visited[cur] = 1;
		for (int i: adj[cur])
			if (!dfs(i, adj, visited, res))
				return false;
		visited[cur] = 2;
		res.push_back(cur);
	}
	return true;
}

vector<int> findBuildOrder(vector<vector<int>> &adj) {
	vector<int> res, visited(N+1, 0);
	for (int i = 1; i <= N; ++i)
		if (visited[i] == 0)
			if (!dfs(i, adj, visited, res))
				return {};
	return res;
}
