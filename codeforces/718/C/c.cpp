#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int sol[n][n];
	for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) sol[i][j] = 0;
	for(int i = 0; i<n; i++) sol[i][i] = a[i];
	for(int i = 0; i<n; i++) {
		int x, y; x = y = i;
		for(int j = 0; j<a[i]-1; j++){
			if(x-1>=0 && sol[x-1][y]==0){
				sol[x-1][y] = a[i];
				x--;
				continue;
			}
			sol[x][y+1] = a[i];
			y++;
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(sol[j][i]!=0) cout << sol[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
