#include <bits/stdc++.h>
using namespace std;

bool f() {
	int w, h, n;
	cin >> w >> h >> n;
	int nw = 1, nh = 1;
	while(w%2==0){
		nw*=2;
		w = w/2;
	}
	while(h%2==0){
		nh*=2;
		h = h/2;
	}
	return nh*nw>=n;
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