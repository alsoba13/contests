#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, m, sol = 0;
	cin >> n >> m;
	set<int> ts;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		ts.insert(t);
	}
	for(int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (ts.find(t) != ts.end()) sol++;
	}
	return sol;
}


int main() {
	int t;
	cin >> t;
	while (t--)
		cout << f() << endl;
	return 0;
}