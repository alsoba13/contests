#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j<m-1; j++){
			int c = 0;
			if(a[i][j]=='#')c++;
			if(a[i+1][j]=='#')c++;
			if(a[i][j+1]=='#')c++;
			if(a[i+1][j+1]=='#')c++;
			if(c==1 || c==3) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
