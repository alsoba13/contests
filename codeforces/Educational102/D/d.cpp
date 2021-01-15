#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, m;
	string ins;
	cin >> n >> m >> ins;
	vector<int> v(1, 0), min0(n+1), max0(n+1);
	for(int i = 0; i<n; i++) {
		if(ins[i] == '-') v.push_back(v.back()-1);
		else v.push_back(v.back()+1);
	}
	for(int i = 1; i<v.size(); i++) {
		min0[i] = min(min0[i-1], v[i]);
		max0[i] = max(max0[i-1], v[i]);
	}
	vector<int> min1(n+1, v.back()), max1(n+1, v.back());
	for(int i = v.size()-2; i>=0; i--) {
		min1[i] = min(min1[i+1], v[i]);
		max1[i] = max(max1[i+1], v[i]);
	}
	for(int i = 0; i<m; i++){
		int q0, q1;
		cin >> q0 >> q1;
		int min_inicio = min0[q0-1], max_inicio = max0[q0-1];
		min_inicio = min(min_inicio, v[q0-1]+min1[q1]-v[q1]);
		max_inicio = max(max_inicio, v[q0-1]+max1[q1]-v[q1]);
		cout << max_inicio-min_inicio+1 << "\n";
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
