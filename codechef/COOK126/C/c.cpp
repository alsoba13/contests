#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, m, r, g, b;
	cin >> n >> m >> r >> g >> b;
	vector<pair<int, char> > tiles;
	tiles.push_back(make_pair(r, 'R'));
	tiles.push_back(make_pair(g, 'G'));
	tiles.push_back(make_pair(b, 'B'));
	sort(tiles.begin(), tiles.end());
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(tiles[(i+j)%2].first) {
				cout << tiles[(i+j)%2].second;
				tiles[(i+j)%2].first--;
			}else{
				cout << tiles[2].second;
			}
		}
		cout << endl;
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
