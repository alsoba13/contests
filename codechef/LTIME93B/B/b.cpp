#include <bits/stdc++.h>
using namespace std;

bool f() {
	string s;
	cin >> s;
	vector<int> c(26, 0);
	for(int i = 0; i<s.size(); i++){
		c[s[i]-'a']++;
	}
	int c1 = 0;
	int pairs = 0;
	for(int i = 0; i<26; i++){
		if(c[i] == 1) c1++;
		else{
			if(c[i]%2==0) pairs += c[i]/2;
			else pairs += (c[i]-3)/2;
		}
	}
	return c1<=pairs;
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
