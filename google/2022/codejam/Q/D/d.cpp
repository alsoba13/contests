#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> slv(vector<long long> &F, vector<vector<int> > &sons, int node) {
	if(sons[node].size() == 0) return make_pair(F[node], 0);
	pair<long long, long long> ans;
	int n = sons[node].size();
	vector<pair<long long, long long> > sols(n);
	for(int i = 0; i<n; i++)
		sols[i] = slv(F, sons, sons[node][i]);
	sort(sols.begin(), sols.end());
	for(int i = 0; i<n; i++){
		ans.second += sols[i].second;
		if(i == 0) ans.first = max(F[node], sols[i].first);
		else ans.second += sols[i].first;
	}
	return ans;
}

long long f_() {
	int n;
	cin >> n;
	vector<long long> F(n);
	for(int i = 0; i<n; i++) cin >> F[i];
	vector<vector<int> > sons(n);
	vector<int> trees;
	for(int i = 0; i<n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			trees.push_back(i);
			continue;
		}
		x--;
		sons[x].push_back(i);
	}
	long long ans = 0;
	for(int i = 0; i<trees.size(); i++) {
		pair<long long, long long> a = slv(F, sons, trees[i]);
		ans += a.first+a.second;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		//slv();
		cout << f_() << '\n';
	}
	return 0;
}
