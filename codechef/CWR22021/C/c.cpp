#include <bits/stdc++.h>
using namespace std;

int s[10000010];
int n7 (int n) {
	int ans = 0;
	while(n>0) {
		ans += (n%10==7);
		n/=10;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i = 0; i<10000010; i++) s[i] = 0;
	for(int i = 1; i<10000010; i++) {
		s[i] = s[i-1] + n7(i);
	}
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << s[b]-s[a-1] << '\n';
	}
	return 0;
}
