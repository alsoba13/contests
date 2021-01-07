#include <bits/stdc++.h>
using namespace std;
//MIRAR SOLUCION AUTOR
int n, m;
int sum[500][500];
string c[500];

int count(int x, int y) {
	int k = 2;
	while (1) {
		if(x+k-1>=n) return k-1;
		if(y-k+1 < 0 || y+k-1 >= m) return k-1;
		if(sum[x+k-1][y+k-1] - sum[x+k-1][y-k+1] + (c[x+k-1][y+k-1] == '*') < 2*k-1) return k-1;
		k++;
	}
	return 0;
}

int f() {
	cin >> n >> m;
	long long sol = 0;
	for(int i = 0; i<n; i++) cin >> c[i];
	for(int i = 0; i<n; i++) {
		int s = 0;
		for(int j = 0; j<m; j++) {
			sum[i][j] = s;
			s += (c[i][j] == '*');
		}
	}
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			if (c[i][j] == '*')
				sol += count(i, j);
	return sol;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}