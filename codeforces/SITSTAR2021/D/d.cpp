#include <bits/stdc++.h>
using namespace std;

int f(){
	int a[3], b[3];
	for(int i = 0; i<3; i++) cin >> a[i];
	for(int i = 0; i<3; i++) cin >> b[i];
	sort(a, a+3);
	sort(b, b+3);
	int ans = 0;
	for(int i = 0; i<3; i++) ans += a[i]*b[i];
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
