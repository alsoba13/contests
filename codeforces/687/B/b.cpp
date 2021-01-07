#include <bits/stdc++.h>
using namespace std;

int g(vector<int> &c, int max_c, int n, int k) {
	int i = 0;
	int sol = 0;
	while(i < n) {
		while (i < n && c[i] == max_c) {
			i++;
		}
		while (i < n && c[i] != max_c) {
			sol++;
			i += k;
		}
	}
	return sol;
}

int f() {
	int n, k;
	cin >> n >> k;
	vector<int> c;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int c_;
		cin >> c_;
		c.push_back(c_);
		s.insert(c_);
	}
	int sol = n;
	for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
		sol = min(sol, g(c, *i, n, k));
	}
	return sol;
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}

	return 0;
}