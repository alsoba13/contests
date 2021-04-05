#include <bits/stdc++.h>
using namespace std;

int f() {
	int x, y;
	cin >> x >> y;
	string s;
	cin >> s;
	int n = s.size();
	int dp[n][2];
	dp[0][0] = 0;
	dp[0][1] = 0;
	for(int i = 1; i<n; i++) {
		switch (s[i]) {
		case '?':
			if(s[i-1]=='?') {
				dp[i][0] = min(dp[i-1][0], dp[i-1][1]+y);
				dp[i][1] = min(dp[i-1][1], dp[i-1][0]+x);
			}
			if(s[i-1]=='C') {
				dp[i][0] = dp[i-1][0];
				dp[i][1] = dp[i-1][0]+x;
			}
			if(s[i-1]=='J') {
				dp[i][0] = dp[i-1][1]+y;
				dp[i][1] = dp[i-1][1];
			}
			break;
		case 'C':
			dp[i][0] = dp[i-1][0] + (s[i-1]=='J'?y:0);
			if(s[i-1]=='?')
				dp[i][0] = min(dp[i][0], dp[i-1][1]+y);
			dp[i][1] = dp[i][0]; 
			break;
		case 'J':
			dp[i][1] = dp[i-1][1] + (s[i-1]=='C'?x:0);
			if(s[i-1]=='?')
				dp[i][1] = min(dp[i][1], dp[i-1][0]+x);
			dp[i][0] = dp[i][1];
			break;
		}
	}
	return min(dp[n-1][0], dp[n-1][1]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
