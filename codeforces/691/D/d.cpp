#include <bits/stdc++.h>
using namespace std;

int dp[101][101][10001];

int main() {
	int n, B;
	cin >> n;
	for(int i = 0; i<101; i++)
		for(int k = 0; k<101; k++)
			for(int A = 0; A < 10001; A++) dp[i][k][A] = -1e9;
	dp[0][0][0] = 0; 
	double sumb;
	for(int i = 1; i<=n; i++) {
		int a, b;
		cin >> a >> b;
		dp[i][0][0] = 0;
		for(int k = 1; k<=i; k++){
			for(int A = 0; A<=10001; A++){
				if (a<=A) dp[i][k][A] = max(dp[i-1][k][A], dp[i-1][k-1][A-a]+b);
				else dp[i][k][A] = dp[i-1][k][A];
			}
		}
		sumb+=b;
	}
	for(int k = 1; k<=n; k++){
		double ans = 0;
		for(int A = 0; A<=10000; A++){
			ans = max(ans, min(sumb/2+dp[n][k][A]/2., (double)A));
		}
		printf("%lf ", ans);
	}
	cout << endl;
	return 0;
}