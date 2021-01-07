#include <bits/stdc++.h>
using namespace std;

long long slv() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int a_;
		cin >> a_;
		a.push_back(a_);
	}
	long long sol = 0;
	for(int i = 1; i < a.size(); i++) {
		sol += abs(a[i]-a[i-1]);
	}
	int max_ = max(abs(a[0]-a[1]), abs(a[n-1]-a[n-2]));
	for (int i = 1; i < n-1; i++) {
		max_ = max(max_, abs(a[i]-a[i-1]) + abs(a[i+1]-a[i]) - abs(a[i+1]-a[i-1]));
	}
	return sol-max_;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << slv() << endl;
	}
	return 0;
}