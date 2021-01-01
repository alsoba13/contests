#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<int> x(n);
	set<int> areas;
	for (int i = 0; i<n; i++) cin >> x[i];
	for (int i = 0; i<n-1; i++)
		for(int j = i+1; j<n; j++)
			areas.insert(x[j]-x[i]);
	return areas.size();
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}
