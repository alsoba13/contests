#include <bits/stdc++.h>
using namespace std;

int f() {
	int n; string s;
	cin >> n >> s;
	for(int i = 0; i<n-1; i++){
		if(s[i] == 'a' && s[i+1] == 'a') return 2;
	}
	for(int i = 0; i<n-2; i++){
		if(s[i] == 'a' && s[i+2] == 'a') return 3;
	}
	for(int i = 0; i<n-3; i++){
		if(s[i] == 'a' && s[i+1]!=s[i+2] && s[i+3] == 'a') return 4;
	}
	for(int i = 0; i<n-6; i++){
		if(s[i] == 'a' && s[i+1]==s[i+2] 
			&& s[i+3] == 'a'
			&& s[i+4]==s[i+5] && s[i+4]!=s[i+1]
			&& s[i+6] == 'a'
		) return 7;
	}
	return -1;
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
