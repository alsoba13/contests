#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int> > > a(m);
	for(int i = 0; i<m; i++) {
		cin >> a[i].second.first >> a[i].first;
		a[i].second.second = i+1;
	}
	sort(a.begin(), a.end());
	vector<pair<int, int> > b(2*n);
	long long sum = 0;
	for(int i = 0; i<2*n; i++) {
		sum += a[i].first;
		b[i] = a[i].second;
	}
	sort(b.begin(), b.end());
	cout << sum << "\n";
	for(int i = 0; i<n; i++) {
		cout << b[i].second << " " << b[2*n-1-i].second << "\n"; 
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
