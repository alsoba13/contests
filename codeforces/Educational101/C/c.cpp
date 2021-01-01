#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for(int i=0; i<n; i++) cin >> h[i];
	vector<pair<int,int> > s(n);
	s[0].first = s[0].second = h[0];
	for(int i = 1; i<n; i++){
		s[i].first = s[i-1].first-(k-1);
		s[i].second = s[i-1].second+(k-1);
		if (h[i] > s[i].second) return false;
		if (h[i]+k-1 < s[i].first) return false;
		s[i].first = min(h[i]+k-1, max(h[i], s[i].first));
		s[i].second = max(h[i], min(h[i]+k-1, s[i].second));
		if (s[i].second < s[i].first) return false;
	}
	if (s[n-1].first > h[n-1]) return false;
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << (f()?"YES":"NO") << endl;
	}
	return 0;
}