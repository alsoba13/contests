#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n; 
	cin >> n;
	set<pair<long long, int> > p;
	long long x;
	cin >> x;
	for(int i = 2; i<=n; i++){
		long long v;
		cin >> v;
		p.insert(make_pair(v, i));
	}
	vector<pair<pair<int, int>, long long> > s;
	while(p.size() > 1){
		long long v = p.begin()->first; 
		int idx = p.begin()->second;
		p.erase(p.begin());
		if (v>x){
			long long v2 = p.begin()->first;
			int idx2 = p.begin()->second;
			p.erase(p.begin());
			p.insert(make_pair(v2+v-x, idx2));
			s.push_back(make_pair(make_pair(idx, idx2), v-x));
			v = x;
		}
		x += v;
		s.push_back(make_pair(make_pair(idx, 1), v));
	}
	if(p.begin()->first > x){
		cout << -1 << '\n';
		return;
	}
	s.push_back(make_pair(make_pair(p.begin()->second, 1), p.begin()->first));
	cout << s.size() << endl;
	for(int i = 0; i<s.size(); i++){
		cout << s[i].first.first << " " << s[i].first.second << " " << s[i].second << '\n';
	}
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