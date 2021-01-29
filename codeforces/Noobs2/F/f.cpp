#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	map<int, int> have;
	int ans = 0;
	int p = 0;
	for(int i = 0; i<n; i++){
		if(i<=p){
			have[a[i-1]]--;
			if (have[a[i-1]]==0){
				k+=a[i-1];
			}
		}
		p = max(i, p);
		while(1){
			if (p>=n) {
				break;
			}
			if (have[a[p]]>0){
				have[a[p]]++;
				p++;
				continue;
			}
			if (a[p]>k){
				break;
			}
			have[a[p]]++;
			k-=a[p];
			p++;
		}
		ans = max(ans, p-i);
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
