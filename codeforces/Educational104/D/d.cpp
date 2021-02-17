#include <bits/stdc++.h>
using namespace std;

long long f() {
	long long n;
	cin >> n;
	if(n<5) return 0;
	long long i = 1;
	for(;i*i<=(2*n-1); i+=2);
	return i/2-1;
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
