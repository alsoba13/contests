#include <bits/stdc++.h>
using namespace std;
 
vector<int> fact[1000001];
 
void slv() {
	int n;
	cin >> n;
	map<int, vector<int> >m;
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		vector<int> factors = fact[a];
		int x = 1;
		for(int j = 0; j<factors.size(); j++) {
			int y = a, c = 0;
			while(y%factors[j] == 0){
				y /= factors[j];
				c++;
			}
			if(c%2 == 1) x *= factors[j];
		}
		m[x].push_back(a);
	}
	int d0 = 0, d1 = 0;
	for(map<int, vector<int> >::iterator i = m.begin(); i!=m.end(); i++){
		d0 = max(d0, (int)i->second.size());
		if (i->first == 1 || i->second.size()%2 == 0) d1 += i->second.size();
	}
	int q;
	cin >> q;
	for(int i = 0; i<q; i++){
		long long q_i;
		cin >> q_i;
		if(q_i == 0) cout << d0 << endl;
		else cout << max(d1,d0) << endl;
	}
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i = 2; i<1000001; i++) {
		if (fact[i].empty()) {
			for (int j = i; j<1000001; j+=i) {
				fact[j].push_back(i);
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
