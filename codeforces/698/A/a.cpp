#include <bits/stdc++.h>
using namespace std;

int f() {
	vector<int> c(101);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		c[a-1]++;
	}
	int ans = 0;
	for(int i = 0; i<101; i++){
		ans = max(ans, c[i]);	
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
