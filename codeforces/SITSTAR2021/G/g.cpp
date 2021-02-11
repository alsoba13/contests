#include <bits/stdc++.h>
using namespace std;

int k[31];

long long f() {
	long long n;
	cin >> n;
	long long n5 = n/5, n3 = n/3 - n/15, n2 = n/2 - n/6 - n/10 + n/30;
	return n5*4 + n3*2 + n2 + n;
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
