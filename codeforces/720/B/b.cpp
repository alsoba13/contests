#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

void slv() {
	int n;
	cin >> n;
	vector<int> a(n+2);
	a[0] = 1;
	a[n+1] = 1;
	for(int i = 0; i<n; i++) cin >> a[i+1];
	int min_i = 1;
	for(int i = 2; i<=n; i++){
		if(a[i]<a[min_i]) min_i = i;
	}
	vector<pair<pair<int, int>, pair<int, int> > > sol;
	for(int i = 1; i<=n; i++){
		if (i == min_i) continue;
		if(gcd(a[i], a[i-1]) != 1 || gcd(a[i], a[i+1]) != 1) {
			while(gcd(a[i], a[i-1]) != 1 || gcd(a[i], a[i+1]) != 1) {
				a[i]++;
			}
			sol.push_back(make_pair(make_pair(min_i, i), make_pair(a[min_i], a[i])));
		}
	}
	cout << sol.size() << '\n';
	for(int i = 0; i<sol.size(); i++){
		cout << sol[i].first.first << " " << sol[i].first.second << " " << sol[i].second.first << " " << sol[i].second.second << '\n';
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
