#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n; 
	cin >> n;
	map<string, set<char> > suffix;
	for(int i = 0; i<n; i++) {
		string s;
		cin >> s;
		string suf = s.substr(1, s.size()-1);
		suffix[suf].insert(s[0]);
	}
	long long ans = 0;
	for(map<string, set<char> >::iterator i = suffix.begin(); i!=suffix.end(); i++){
		map<string, set<char> >::iterator j = i;
		j++;
		for(; j!=suffix.end(); j++){
			set<char> a = suffix[i->first];
			set<char> b = suffix[j->first];
			vector<char> u(a.size()+b.size()); 
			vector<char>::iterator it = set_union(a.begin(), a.end(), b.begin(), b.end(), u.begin());
			u.resize(it-u.begin());
			ans += (u.size()-a.size())*(u.size()-b.size());
		}
	}
	return 2*ans;
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
