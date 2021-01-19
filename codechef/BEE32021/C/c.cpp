#include <bits/stdc++.h>
using namespace std;

void slv() {
	list<string> s;
	int n, m;
	cin >> n;
	list<string>::iterator it = s.begin();
	int ip = 0;
	for(int i = 0; i<n; i++){
		string a;
		int pos;
		cin >> a >> pos;
		pos--;
		advance(it, pos-ip);
		s.insert(it, a);
		ip = pos+1;
	}
	cin >> m;
	set<string> no;
	for(int i = 0; i<m; i++){
		string a;
		cin >> a;
		no.insert(a);
	}
	bool d = false;
	for(it = s.begin(); it!=s.end(); it++){
		if(no.find(*it) == no.end()) {
			cout << *it << '\n';
			d = true;
		};
	}
	if (!d) cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
