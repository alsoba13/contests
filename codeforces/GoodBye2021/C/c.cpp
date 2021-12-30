#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	if (n == 1) return 0;
	int ans = n;
	for(int xi = 0; xi<n-1; xi++){
		for(int xj = xi+1; xj<n; xj++){
			int ko = 0;
			for(int xz = 0; xz<n; xz++){
				if( (a[xz]-a[xi])*(xj-xi) != (xz-xi)*(a[xj]-a[xi]))
					ko++;
			}
			ans = min(ans, ko);
		}
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