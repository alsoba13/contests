#include <bits/stdc++.h>
using namespace std;

bool adj[18][18];
int n, m;

bool clique(int mask) {
	vector<int> members;
	for(int i = 0; i<n; i++) if ( (1<<i) & mask) members.push_back(i);
	for(int i = 0; i<members.size(); i++)
		for(int j = i+1; j<members.size(); j++)
			if (!adj[members[i]][members[j]]) return false;
	return true;
}

int main() {
	cin >> n >> m;
	bool is_clique[270000];
	int dp[270000];
	for(int i = 0; i<n; i++) for (int j = 0; j<n; j++) adj[i][j] = false;
	for(int i = 0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a][b] = true;
		adj[b][a] = true;
	}
	for(int mask = 0; mask<(1<<n); mask++) {
		is_clique[mask] = clique(mask);
		dp[mask] = 1000;
	}
	dp[0] = 0;
	for(int mask = 1; mask<(1<<n); mask++) {
		if(is_clique[mask]) dp[mask] = 1;
		else
			for(int submask = mask; submask; submask = (submask-1)&mask)
				dp[mask] = min(dp[mask], dp[submask]+dp[submask^mask]);
	}
	cout << dp[(1<<n)-1] << endl;
	return 0;
}