#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n;
	cin >> n;
	vector<string> m(n);
	for(int i = 0; i<n; i++) cin >> m[i];
	for(int i = 0; i<n; i++) {
		string b;
		cin >> b;
		for(int j = 0; j<n; j++)
			m[i][j] = (b[j] == m[i][j]) ? '0' : '1';
	}
	for(int i = 1; i<n; i++)
		for(int j = 1; j<n; j++)
			if((m[i][j]==m[0][j])!=(m[i][j-1]==m[0][j-1])) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
