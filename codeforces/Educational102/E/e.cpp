#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int> > > g;

void sparse_dijkstra(int src, long long dist[][2][2], int n) {
	set<pair<long long, pair<int, pair<int, int> > > > q;
	q.insert(make_pair(0, make_pair(src, make_pair(0,0))));
	dist[src][0][0] = 0;
	while(!q.empty()){
		pair<int, pair<int, int> > t = q.begin()->second;
		int v = t.first;
		int m = t.second.first;
		int M = t.second.second;
		q.erase(q.begin());
		for(int j = 0; j<g[v].size(); j++){
			int to = g[v][j].first;
			long long w = g[v][j].second;
			for(int mn = 0; mn<2-m; mn++){
				for(int mx = 0; mx<2-M; mx++){
					if (dist[v][m][M]+w*(1-mx+mn) < dist[to][mn|m][mx|M]){
						q.erase(make_pair(dist[to][mn|m][mx|M], make_pair(to, make_pair(mn|m,mx|M))));
						dist[to][mn|m][mx|M] = dist[v][m][M]+w*(1-mx+mn);
						q.insert(make_pair(dist[to][mn|m][mx|M], make_pair(to, make_pair(mn|m,mx|M))));
					}
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	g = vector<vector<pair<int, int> > >(n);
	for(int i = 0; i<m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
	long long dist[n][2][2];
	for(int i = 0; i<n; i++) for(int j = 0; j<2; j++) for(int k = 0; k<2; k++) dist[i][j][k] = (long long)1e18;
	sparse_dijkstra(0, dist, n);
	for(int i = 1; i<n; i++){
		cout << dist[i][1][1] << " ";
	}
	cout << endl;
	return 0;
}
