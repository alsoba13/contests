#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > p(n);
	int sol = 0;
	for(int i = 0; i<n; i++) cin >> p[i].first >> p[i].second;
	for(int i = 0; i<n-1; i++) {
		for(int j = i+1; j<n; j++){
			int x, y;
			x = p[j].first - p[i].first;
			y = p[j].second - p[i].second;
			if(abs(x) >= abs(y)) sol++;
		}
	}
	cout << sol << endl;
	return 0;
}