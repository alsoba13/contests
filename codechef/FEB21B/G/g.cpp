#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, q, m;
	cin >> n >> q >> m;
	vector<int> a(n);
	map<pair<int, int>, int> s;
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = 0; i<q; i++){
		int l, r; cin >> l >> r;
		s[make_pair(l, r)]++;
	}
	vector<int> sol(m+1,0);
	for(map<pair<int, int>, int>::iterator i = s.begin(); i!=s.end(); i++) {
		int l = a[i->first.first-1], r = a[i->first.second-1], f = i->second;
		for(int j = l; j<=m; j+=(l+r)) {
			sol[j]+=f;
		}
		for(int j = l+r; j<=m; j+=(l+r)) {
			sol[j]-=f;
		}
	}
	int ans = 0;
	for(int i = 0; i<=m; i++){
		sol[i] = sol[i]+(i?sol[i-1]:0);
		ans = max(ans, sol[i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; 
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
}
