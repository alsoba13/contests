#include <bits/stdc++.h>
using namespace std;

int f() {
	int n; string s;
	cin >> n >> s;
	vector<int> n0(n+1);
	n0[0] = 0;
	for(int i = 1; i<=n; i++){
		if(s[i-1]=='0')n0[i] = n0[i-1]+1;
		else n0[i] = n0[i-1];
	}
	int ans = n+1;
	for(int i = 0; i<=n; i++){
		int ones, zeros;
		ones = i-n0[i];
		zeros = n0[n]-n0[i];
		ans = min(ans, ones+zeros);
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
