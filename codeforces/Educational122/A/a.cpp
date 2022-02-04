#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	if (n%7 == 0) return n;
	for(int i = 0; i<=9; i++) {
		if( (n/10*10+i) % 7 == 0 ) return (n/10*10+i);
	}
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
