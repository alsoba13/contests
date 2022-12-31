#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	int ans = 801;
	for(int i = 0; i<n; i++) {
		int m;
		cin >> m;
		int M = 0;
		for(int j = 0; j<m; j++) {
			int a;
			cin >> a;
			M = max(a, M);
		}
		ans = min(ans, M);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		cout << f(n) << '\n';
	}
	return 0;
}