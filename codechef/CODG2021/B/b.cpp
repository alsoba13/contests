#include <bits/stdc++.h>
using namespace std;

int f() {
	int n; 
	cin >> n;
	vector<int> a(n), p(n);
	for(int i = 0; i<n; i++){
		cin >> a[i];
		a[i]--;
		p[a[i]] = i;
	}
	int ans = 0;
	int pos = 0;
	for(int i = 0; i<n; i++){
		ans += abs(pos-p[i]);
		pos = p[i];
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
