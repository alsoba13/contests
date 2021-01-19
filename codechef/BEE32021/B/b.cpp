#include <bits/stdc++.h>
using namespace std;

int f() {
	long long n;
	cin >> n;
	int ans = 0;
	while(n>0){
		n/=2;
		ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
