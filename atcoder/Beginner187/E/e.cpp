#include <bits/stdc++.h>
using namespace std;

long long sol[200000];
bool visited[200000];
map<int, map<int, long long> > sums;
vector<vector<int> > v;

long long dfs(int node, long long coming) {
	visited[node] = true;
	sol[node] = coming;
	long long offset = 0;
	for(int i = 0; i<v[node].size(); i++) {
		int going_to = v[node][i];
		if (!visited[going_to]) {
			offset += dfs(v[node][i], coming+sums[node][going_to]-sums[going_to][node]) + sums[going_to][node];
		}
	}
	return offset;
}

int main() {
	int n, Q;
	cin >> n;
	v = vector<vector<int> >(n);
	vector<pair<int, int> > e(n-1);
	for(int i = 0; i<n; i++) sol[i] = 0;
	for(int i = 0; i<n-1; i++) {
		cin >> e[i].first >> e[i].second;
		e[i].first--; e[i].second--;
		v[e[i].first].push_back(e[i].second);
		v[e[i].second].push_back(e[i].first);
	}
	cin >> Q;
	for(int i = 0; i<Q; i++) {
		int T, E, X;
		cin >> T >> E >> X;
		E--;
		int a, b;
		a = e[E].first;
		b = e[E].second;
		if (T == 1) sums[b][a] += X;
		else sums[a][b] += X;
	}
	long long offset = dfs(0, 0);
	for(int i = 0; i<n; i++) cout << sol[i]+offset << endl;
}