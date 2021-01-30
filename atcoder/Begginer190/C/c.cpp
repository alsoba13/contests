#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int  n, m, k;
	cin >> n >> m;
	vector<int> a(m), b(m);
	for(int i = 0; i<m; i++) cin >> a[i] >> b[i];
	cin >> k;
	int cd[k][2];
	for(int i = 0; i<k; i++) cin >> cd[i][0] >> cd[i][1];
	bool d[n+10];
	int ans = 0;
	for(int i = 0; i<(1<<k); i++){
		for(int j = 1; j<=n; j++) d[j] = false;
		for(int j = 0; j<k; j++){
			d[cd[j][(i>>j)&1]] = true;
		}
		int c = 0;
		for(int j = 0; j<m; j++) if(d[a[j]] && d[b[j]]) c++;
		ans = max(ans, c);
	}
	cout << ans << endl;
	return 0;
}
