#include <bits/stdc++.h>
using namespace std;

void slv(int n) {
	map<int, pair<int, int> > m;
	for(int i = 0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		m[a].first++;
		m[b].second++;
	}
	int best = -1;
	int c_best = 0;
	int current = 0;
	int lastt = 0;
	for(map<int, pair<int, int> >::iterator i = m.begin(); i != m.end(); i++) {
		int t = i->first;
		int coming = i->second.first;
		int leaving = i->second.second;
		if(current == best) {
			c_best += (t-lastt);
		}
		current += (coming)-(leaving);
		if(current>best) {
			best = current;
			c_best = 0;
		}
		lastt = t;
	}
	cout << best << " " << c_best << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		slv(n);
	}
	return 0;
}