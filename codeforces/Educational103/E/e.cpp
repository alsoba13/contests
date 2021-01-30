#include <bits/stdc++.h>
using namespace std;

int N = 1e5+10;
vector<int> sol;
vector<vector<int> > g(N);
vector<int> visited(N, false);
void dfs(int node){
	visited[node] = 1;
	for(int i = 0; i<g[node].size(); i++){
		if(visited[g[node][i]] == 1){
			cout << "NO" << endl;
			exit(0);
		}else{
			if(visited[g[node][i]] == 0){
				dfs(g[node][i]);
			}
		}
	}
	visited[node] = 2;
	sol.push_back(node);
}

void slv() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> p(n), s(m);
	vector<int> mt(m);
	map<string, int> t;
	for(int i = 0; i<n; i++){
		cin >> p[i];
		t[p[i]] = i;
	}
	for(int i = 0; i<m; i++){
		cin >> s[i] >> mt[i];
		mt[i]--;
	}
	for(int i = 0; i<m; i++){
		vector<int> matches;
		for(int j = 0; j<(1<<k); j++){
			string x = s[i];
			for(int jj = 0; jj<k; jj++){
				if (((j>>jj)&1) == 1) x[jj]='_';
			}
			if(t.find(x)!=t.end()) matches.push_back(t[x]);
		}
		bool ok = false;
		for(int match = 0; match<matches.size(); match++){
			if(matches[match] == mt[i]) ok = true;
			else g[matches[match]].push_back(mt[i]);
		}
		if (!ok) {
			cout << "NO" << endl;
			return;
		}
	}
	for(int i = 0; i<n; i++){
		if(visited[i] == 0){
			dfs(i);
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i<n; i++) cout << sol[i]+1 << " "; cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	slv();
	return 0;
}
