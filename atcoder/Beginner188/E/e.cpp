#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
vector<vector<int> > g; 
vector<bool> seen;

long long dfs(int src, long long mpr) {
	long long sell_price = a[src]-mpr;
	if (seen[src]) return sell_price;
	seen[src] = true;
	mpr = min(mpr, a[src]);
	for(int i = 0; i<g[src].size(); i++){
		sell_price = max(sell_price, dfs(g[src][i], mpr));
	}	
	return sell_price;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	g = vector<vector<int> >(n);
	a = vector<long long>(n);
	vector<pair<long long, int> > b(n);
	seen = vector<bool>(n, false);
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(b.begin(), b.end());
	for(int i = 0; i<m; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
	}
	long long ans = (long long)-1e18;
	for(int i = 0; i<n; i++){
		if(!seen[b[i].second]){
			ans = max(ans, dfs(b[i].second, (long long)1e18));
		}
	}
	cout << ans << endl;
}