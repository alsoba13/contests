#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, c;
	cin >> n >> c;
	if(c < n-1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	if(c > n*(n+1)/2 -1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	vector<int> cs(n-1, 1);
	c -= n-1;
	for(int i = n-2; i>=0 && c>0; i--) {
		cs[i] += min(c, n-i-1);
		c -= cs[i]-1;
	}
	vector<int> sol(n);
	iota(sol.begin(), sol.end(), 1);
	for(int i = n-2; i>=0; i--) {
		reverse(sol.begin()+i, sol.begin()+i+cs[i]);
	}
	for(int i = 0; i<n; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		slv();
		//cout << f() << '\n';
	}
	return 0;
}
