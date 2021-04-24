#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, K;
	cin >> n >> m >> K;
	long long hs[n][m-1];
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m-1; j++){
			cin >> hs[i][j];
		}
	}
	long long vs[n-1][m];
	for(int i = 0; i<n-1; i++) {
		for(int j = 0; j<m; j++){
			cin >> vs[i][j];
		}
	}
	long long sols[n][m][21], mins[n][m];
	for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) mins[i][j] = INF;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(j!=m-1) mins[i][j] = min(mins[i][j], hs[i][j]);
			if(j>0) mins[i][j] = min(mins[i][j], hs[i][j-1]);
			if(i!=n-1) mins[i][j] = min(mins[i][j], vs[i][j]);
			if(i>0) mins[i][j] = min(mins[i][j], vs[i-1][j]);
		}
	}
	for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) sols[i][j][0] = 0;
	for(int k = 1; k<=K; k++){
		if(k%2){
			for(int i = 0; i<n; i++)for(int j = 0; j<m; j++)sols[i][j][k] = -1;
			continue;
		}
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<m; j++) {
				sols[i][j][k] = sols[i][j][k-2]+2*mins[i][j];
				if(j!=m-1) sols[i][j][k] = min(sols[i][j][k], 2*hs[i][j]+sols[i][j+1][k-2]);
				if(j>0) sols[i][j][k] = min(sols[i][j][k], 2*hs[i][j-1]+sols[i][j-1][k-2]);
				if(i!=n-1) sols[i][j][k] = min(sols[i][j][k], 2*vs[i][j]+sols[i+1][j][k-2]);
				if(i>0) sols[i][j][k] = min(sols[i][j][k], 2*vs[i-1][j]+sols[i-1][j][k-2]);
			}
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << sols[i][j][K] << " ";
		}
		cout << endl;
	}
	return 0;
}