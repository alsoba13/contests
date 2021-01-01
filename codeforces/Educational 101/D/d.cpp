#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	vector<int> sqrs;
	vector<pair<int, int> > sol;
	sqrs.push_back(n);
	for(long long i = n-1; i>=3; i--) {
		if (i*i < sqrs.back())
			sqrs.push_back(i);
		else 
			sol.push_back(make_pair(i, n));
	}
	int n2 = n;
	for(int i = 1; i<sqrs.size(); i++){
		sol.push_back(make_pair(n, sqrs[i]));
		sol.push_back(make_pair(sqrs[i], n));
		n2 = n2/sqrs[i] + (n2%sqrs[i] > 0);
	}
	while(n2 > 1) {
		sol.push_back(make_pair(n, 2));
		n2 = n2/2 + (n2%2 > 0);
	}
	cout << sol.size() << endl;
	for(int i = 0; i<sol.size(); i++) cout << sol[i].first << " " << sol[i].second << endl;
}

void slv2() { // This was my proposed solution but the other one is definitely better
	int n;
	cin >> n;
	int n32 = 32;
	vector<pair<int, int> > s;
	vector<int> p32;
	for(int i = 3; i<=n-1; i++) {
		if (i == n32) {
			p32.push_back(i);
			n32 *= 32;
		} else {
			s.push_back(make_pair(i, i+1));
		}
	}
	if(p32.size()){
		s.push_back(make_pair(n, p32.back()));
		s.push_back(make_pair(n, p32.back()));
		for(int i = p32.size()-1; i >= 1; i--){
			s.push_back(make_pair(p32[i], p32[i-1]));
			s.push_back(make_pair(p32[i], p32[i-1]));
		}
		s.push_back(make_pair(32, 2));
		s.push_back(make_pair(32, 2));
		s.push_back(make_pair(32, 2));
		s.push_back(make_pair(32, 2));
		s.push_back(make_pair(32, 2));
	} else {
		int n2 = n;
		while(n2>1) {
			s.push_back((make_pair(n, 2)));
			n2 = n2/2 + n2%2;
		}
	}
	cout << s.size() << endl;
	for(int i = 0; i<s.size(); i++){
		cout << s[i].first << " " << s[i].second << endl;
	}
}

int main() {
	int t = 0; 
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}