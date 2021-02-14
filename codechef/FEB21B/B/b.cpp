#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<pair<int, pair<int, int> > > a(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i].first;
		a[i].second.first = i;
	}
	for(int i = 0; i<n; i++) cin >> a[i].second.second;
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 1; i<n; i++){
		while(a[i].second.first<=a[i-1].second.first){
			a[i].second.first+=a[i].second.second;
			ans++;
		}
	}
	return ans;
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
