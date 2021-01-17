#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++) 
			a[i][j] = -1;
	a[0][0] = n*n;
	int x = 0, y = 0, dir = 0;
	while(true){
		if(a[x][y] == 1) break;
		int nx, ny;
		switch (dir) {
			case 0: nx = x; ny = y+1; break;
			case 1: nx = x+1; ny = y; break;
			case 2: nx = x; ny = y-1; break;
			case 3: nx = x-1; ny = y; break;
		}
		if(nx<0 || nx>=n || ny<0 || ny>=n || a[nx][ny] != -1) {
			dir++;
			dir %=4;
			switch (dir) {
				case 0: nx = x; ny = y+1; break;
				case 1: nx = x+1; ny = y; break;
				case 2: nx = x; ny = y-1; break;
				case 3: nx = x-1; ny = y; break;
			}
		}
		a[nx][ny] = a[x][y] - 1;
		x = nx; 
		y = ny;
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++) 
			cout << a[i][j] << " ";
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
