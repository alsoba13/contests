#include <bits/stdc++.h>
using namespace std;

void slv(){ // Maps made it more complex than should. I should have used array and binary search.
	int n;
	cin >> n;
	map<int, pair<int, int> > m, minB;
	vector<int> A(n), B(n);
	for(int i = 0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b){
			if (m[b].first>a || m[b].first==0)
				m[b] = make_pair(a, i);
		}else
			if (m[a].first>b || m[a].first==0)
				m[a] = make_pair(b, i);
		A[i] = min(a, b);
		B[i] = max(a, b);
	}
	int min = 2*1e9;
	int i_min;
	for(map<int, pair<int, int> >::iterator i = m.begin(); i!=m.end(); i++){
		if (i->second.first < min) {
			min = i->second.first;
			i_min = i->second.second;
		}
		minB[i->first] = make_pair(min, i_min);
	}
	for(int i = 0; i<n; i++){
		map<int, pair<int, int> >::reverse_iterator s(m.find(A[i]));		
		if (s!=m.rend()){
			if (minB[s->first].first<B[i]) {
				cout << minB[s->first].second+1 << " ";
				continue;
			}
		}
		cout << -1 << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}