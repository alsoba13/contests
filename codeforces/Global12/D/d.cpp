#include <bits/stdc++.h>
using namespace std;

int a[300005];
int c[300005];

bool is_permutation(int n){
	int max_ = a[0], min_ = a[0];
	set<int> s;
	for(int i = 0; i<n; i++) {
		max_ = max(max_, a[i]);
		min_ = min(min_, a[i]);
		s.insert(a[i]);
	}
	if (min_ == 1 && max_ == n && n == s.size()) return true;
	return false;
}

void slv() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) c[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	int l = 0, r = n-1, t = 1;
	while (l<r) {
		if (a[l] == t) {
			t++;
			if (c[t-1] == 1){
				l++;
				continue;
			} else break;
		}
		if (a[r] == t) {
			t++;
			if (c[t-1] == 1){
				r--;
				continue;
			} else break;
		}
		if (c[t] > 0) {
			t++;
		}
		break;
	}
	t--;
	if (is_permutation(n)) cout << 1;
	else cout << 0;
	for (int i = 2; i <= n-t; i++) cout << 0;
	for (int i = n-t+1; i <= n; i++) cout << 1;
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}