#include <bits/stdc++.h>
using namespace std;

string f() {
	int n;
	string s;
	cin >> n >> s;
	int k = 0;
	if(n > 1 && s[0] != s[1]) {
		for(int i = 1; i<n; i++) {
			if(s[i]<=s[i-1]) k = i;
			else break;
		}
	}
	string ans = "";
	for(int i = 0; i<=k; i++) ans+= s[i];
	for(int i = 0; i<=k; i++) ans+= s[k-i];
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
