#include <bits/stdc++.h>
using namespace std;
 
set<long long> sol;
vector<long long> a, s;
 
void ff(int b, int e) {
	sol.insert(s[e]-s[b]+a[e]);
	int mM = (a[e] + a[b])/2;
	int lo = b, hi = e;
	while(lo<=hi) {
		int mid = (lo+hi)/2;
		if(a[mid]<=mM)
			lo = mid+1;
		else
			hi = mid-1;
	}
	if (lo <= e && lo>b) {
		ff(b, lo-1);
		ff(lo, e);
	}
}
 
void slv() {
	int n, q;
	cin >> n >> q;
	sol = set<long long>();
	a = vector<long long>(n);
	s = vector<long long>(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long sum = 0;
	for(int i = 0; i<n; i++) {
		s[i] = sum;
		sum += a[i];
	}
	ff(0, a.size()-1);
	for(int i = 0; i < q; i++){
		long long query;
		cin >> query;
		cout << (sol.find(query) == sol.end() ? "No" : "Yes") << endl;
	}
}
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}