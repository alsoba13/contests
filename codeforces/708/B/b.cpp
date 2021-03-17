#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, m;
	cin >> n >> m;
	vector<int> r(m);
	for(int i = 0; i<n; i++) {
		int a;
		cin >> a;
		r[a%m]++;
	}
	int ans = 0;
	if(r[0]>0) {
		ans++;
		r[0] = 0;
	}
	for(int i = 1; i<(m+1)/2; i++){
		if(r[i]>0 && r[m-i]>0){
			int mm = min(r[i], r[m-i]) + 1;
			r[i] = max(r[i]-mm, 0);
			r[m-i] = max(r[m-i]-mm, 0);
			ans++;
		}
	}
	if(m%2==0){
		if(r[m/2]>0){
			ans++;
			r[m/2]=0;
		}
	}
	for(int i = 1; i<m; i++){
		if(r[i]>0) ans+=r[i];
	}
	return ans;
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
