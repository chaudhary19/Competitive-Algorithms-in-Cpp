vector<int> Centroid(const vector< vector<int> >& adj) {
	int n = adj.size();
	vector<int> centroid;
	vector<int> sz(n, 0);
	function<int(int, int)> dfs = [&] (int u, int p) {
		bool is_centroid = true;
		sz[u] = 1;
		for(int v : adj[u]) {
			if(v != p) {
				sz[u] += dfs(v, u);
				if(sz[v] > n / 2) is_centroid = false;
			}
		}
		if(n - sz[u] > n / 2) is_centroid = false;
		if(is_centroid) centroid.push_back(u);
		return sz[u];
	};
	dfs(0, -1);
	return centroid;
}
