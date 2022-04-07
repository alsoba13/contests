#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<string> g(n);
	for(int i = 0; i<n; i++) cin >> g[i];
	int ones = 0;
	for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) ones+=g[i][j]-'0';
	int ans = n*n-ones+(n*n-n);
	for(int i = 0; i<n; i++){
		int x = 0;
		for(int j = 0; j<n; j++) {
			x += (g[(i+j)%n][j]-'0');
		}
		ans = min(ans, ones-x+n-x);
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
