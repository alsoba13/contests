#include <bits/stdc++.h>
using namespace std;

int f() {
	int n; 
	cin >> n;
	return n%3 == 0;
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
