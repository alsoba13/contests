#include <bits/stdc++.h>
using namespace std;
#define INF 10000000000

long long f() {
	int n[4];
	vector<pair<long long, int> > p[4];
	for(int i = 0; i<4; i++) cin >> n[i];
	for(int j = 0; j<4; j++){
		for(int i = 0; i<n[j]; i++) {
			long long p_;
			cin >> p_;
			p[j].push_back(make_pair(p_, i));
		}
	}
	for(int i = 1; i<4; i++){
		vector<set<int> > inc(n[i]);
		int m;
		cin >> m;
		for(int j = 0; j<m; j++){
			int a, b;
			cin >> a >> b;
			a--; b--;
			inc[b].insert(a);
		}
		sort(p[i-1].begin(), p[i-1].end());
		for(int j = 0; j<n[i]; j++){
			long long minA = INF;
			for(int k = 0; k<n[i-1]; k++){
				if(inc[j].find(p[i-1][k].second)==inc[j].end()){
					minA = p[i-1][k].first;
					break;
				}
			}
			p[i][j].first += minA;
		}
	}
	long long ans = INF;
	for(int i = 0; i<n[3]; i++){
		ans = min(p[3][i].first, ans);
	}
	if (ans == INF) return -1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << f() << '\n';
	return 0;
}