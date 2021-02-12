#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
int adj[2001][2001];
set<int> nb[20001];
int n;
int walk(int root) {
	vector<int> d(n+1, INF);
	set<pair<int, int> > q;
	for(set<int>::iterator i = nb[root].begin(); i!=nb[root].end(); i++){
		q.insert(make_pair(adj[root][*i], *i));
		d[*i]=adj[root][*i];
	}
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
        for (set<int>::iterator is=nb[v].begin(); is!=nb[v].end(); is++) {
            int to = *is;
            int len = adj[v][*is];
			if (d[v] + len < d[to]) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                q.insert(make_pair(d[to], to));
            }
        }
	}
	if(d[root]==INF) return -1;
	return d[root];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m;
	cin >> n >> m;
	for(int i = 1; i<=n; i++) for(int j = 1; j<=n; j++) adj[i][j] = INF;
	for(int i = 0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
		nb[a].insert(b);
	}
	for(int i = 1; i<=n; i++){
		cout << walk(i) << '\n';
	}
	return 0;
}
