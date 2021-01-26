#include <bits/stdc++.h>
using namespace std;

int f() {
	int r, n;
	cin >> r >> n;
	vector<pair<int, int> > a(n);
	for(int i = 0; i<n; i++){
		cin >> a[i].first;
		a[i].second = i+1;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i<n; i++){
		if(a[i].first>=r) return a[i].second;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
