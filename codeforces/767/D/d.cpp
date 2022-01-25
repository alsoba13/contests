#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n; 
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i<n; i++) cin >> s[i];
	for(int i = 0; i<n; i++) {
		if(s[i].size() == 1) return true;
		if(s[i].size() == 2) {
			if(s[i][0] == s[i][1]) return true;
		}else{
			if(s[i][0] == s[i][2]) return true;
		}
	}
	set<string> seen;
	for(int i = 0; i<n; i++) {
		if(s[i].size() == 2) {
			if(seen.find(string("") + s[i][1] + s[i][0]) != seen.end()) return true;
		}else{
			if(seen.find(string("") + s[i][2] + s[i][1]) != seen.end()) return true;
			if(seen.find(string("") + s[i][2] + s[i][1] + s[i][0]) != seen.end()) return true;
		}
		seen.insert(s[i]);
	}
	seen = set<string>();
	for(int i = n-1; i>=0; i--) {
		if(s[i].size() == 2) {
			if(seen.find(string("") + s[i][1] + s[i][0]) != seen.end()) return true;
		}else{
			if(seen.find(string("") + s[i][1] + s[i][0]) != seen.end()) return true;
			if(seen.find(string("") + s[i][2] + s[i][1] + s[i][0]) != seen.end()) return true;
		}
		seen.insert(s[i]);
	}
	return false;
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
