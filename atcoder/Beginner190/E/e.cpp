#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;
const int inf = 1e9;
const int MAXK = 17;
vector<vector<int> > adj;
int dist[MAX][MAXK];
int n, m, k;

void dfs(int idx, int from){
	queue<int> q;
	q.push(from);
	dist[from][idx] = 0;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(int i = 0; i<adj[node].size(); i++) {
			int child = adj[node][i];
			if (dist[child][idx] == inf){
				dist[child][idx] = dist[node][idx] + 1;
				q.push(child);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	adj = vector<vector<int> >(n);
	for(int i = 0; i<m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> k;
	vector<int> c(k);
	for(int i = 0; i<k; i++) 
		cin >> c[i];
	for(int i = 0; i<n; i++) 
		for(int j = 0; j<k; j++) 
			dist[i][j] = inf;
	for(int i = 0; i<k; i++)
		dfs(i, c[i]);
	for(int i = 0; i<k; i++){
		if(dist[c[0]][i] == inf){
			cout << -1 << '\n';
			return 0;
		}
	}
	int dp[k][1<<k];
	for(int i = 0; i<k; i++) {
		
	}
	
	
	
	/*
	for(int i = 0; i<k; i++){
		printf("Dist from %d\n", c[i]);
		for(int j = 0; j<n; j++){
			cout << dist[j][i] << " ";
		}
		cout << endl;
	}*/
	return 0;
}
