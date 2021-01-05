#include <bits/stdc++.h>
using namespace std;

bool f() { // I did cases analysis. Fast algo but slow to code.
	int N, m;
	cin >> N >> m;
	map<int, int> g;
	for(int i = 0; i<m; i++) {
		int r, c; 
		cin >> r >> c;
		g[c]+=r;
	}
	int state = 0, n = 0;
	for(map<int, int>::iterator i = g.begin(); i!=g.end(); i++) {
		if (i->second == 3) {
			if (state != 0) return false;
			n = i->first;
		}
		if (i->second == 2) {
			if (state == -1){
				if ((i->first - n) % 2 == 0){
					n = i->first;
					state = 0;
				} else {
					return false;
				}
			} else {
				if (state == 0){
					state = -1;
					n = i->first - 1;
				}else{
					if ((i->first - n) % 2 == 0 || (i->first - n)<2){
						return false;
					} else {
						state = 0;
						n = i->first;
					}
				}
			}
		}
		if (i->second == 1) {
			if (state == 1){
				if ((i->first - n) % 2 == 0){
					n = i->first;
					state = 0;
				} else {
					return false;
				}
			} else {
				if (state == 0){
					state = 1;
					n = i->first - 1;
				}else{
					if ((i->first - n) % 2 == 0 || (i->first - n)<2){
						return false;
					} else {
						state = 0;
						n = i->first;
					}
				}
			}
		}
	}
	return state == 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << (f()? "YES": "NO") << endl;
		//slv();
	}
	return 0;
}