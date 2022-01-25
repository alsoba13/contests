#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	int grid[n][n];
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cin >> grid[i][j];
		}
	}
	int a, b; a = b = 0;
	for(int i = 1; i<n; i+=4){
		for(int j = 0; j<n; j++) {
			int x = i + 2*j;
			int y = 0 + 2*j;
			if (x<n && y<n){
				a = a^grid[x][y];
				b = b^grid[n-1-x][y];
			}
		}
	}
	for(int i = 3; i<n; i+=4){
		for(int j = 0; j<n; j++) {
			int x = 0 + 2*j;
			int y = i + 2*j;
			if (x<n && y<n){
				a = a^grid[x][y];
				b = b^grid[n-1-x][y];
			}
		}
	}
	return a^b;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
