#include <bits/stdc++.h>
using namespace std;

bool f() {
	string s; int n, k;
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i<n/2-(n%2==0?1:0); i++){
		if(s[i] == s[n-i-1]) k--;
		else break;
	}
	return k <= 0;
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
