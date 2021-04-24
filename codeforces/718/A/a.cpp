#include <bits/stdc++.h>
using namespace std;

int f() {
	long long n;
	cin >> n;
	if(n%2050 != 0) return -1;
	n /= 2050;
	int c = 0;
	while(n){
		c += n%10;
		n /= 10;
	}
	return c;	
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
