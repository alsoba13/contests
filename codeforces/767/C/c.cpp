#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	vector<int> mex(n);
	vector<bool> m(n+1, false);
	vector<int> sol;
	int MEX = 0;
	for(int i = n-1; i>=0; i--) {
		m[a[i]]=true;
		while(m[MEX]) MEX++;
		mex[i] = MEX;
	}
	int expected_mex = -1;
	vector<bool> seen;
	int c = 0;
	for(int i = 0; i<n; i++) {
		if(expected_mex == -1) {
			expected_mex = mex[i];
			sol.push_back(expected_mex);
			seen = vector<bool>(expected_mex, false);
			c = 0;
		}
		if(a[i]<expected_mex && !seen[a[i]]) {
			seen[a[i]] = true;
			c++;
		}
		if (c == expected_mex) {
			expected_mex = -1;
		}
	}
	cout << sol.size() << "\n";
	for(int i = 0; i<sol.size(); i++) cout << sol[i] << " "; cout << "\n";
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
