#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, ans = 0;
	cin >> n;
	while(n>0) {
		if(n%2 == 0) ans++;
		n /= 2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << "\n";
	}
	return 0;
}
