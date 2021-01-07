#include <bits/stdc++.h>
using namespace std;


int f() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	return max(r-1, n-r)+max(c-1, m-c);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}

	return 0;
}