#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i].first >> v[i].second;
	}
	for(int i = 0; i<n; i++) {
		bool good = true;
		for(int j = 0; j<n; j++) {
			if(abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second)>k) {
				good = false;
				break;
			}
		}
		if (good) return 1;
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}