#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, m;
	cin >> n >> m;
	int ms[n][m], sol[n][m];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> ms[i][j];
		}
		sort(ms[i], ms[i]+m);
	}
	vector<int> mins(m);
	for(int i = 0; i<m; i++) {
		mins[i]=ms[0][i];
		sol[0][i] = ms[0][i];
	}
	for(int i = 1; i<n; i++){
		vector<pair<int, int> > ps(m);
		for(int j = 0; j<m; j++){
			ps[j] = make_pair(mins[j], j);
		}
		sort(ps.rbegin(), ps.rend());
		for(int j = 0; j<m; j++){
			mins[ps[j].second] = min(mins[ps[j].second], ms[i][j]);
			sol[i][ps[j].second] = ms[i][j];
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
