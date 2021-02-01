#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	long long a = 0; 
	for(int i = 0; i<n; i++){
		int b; 
		cin >> b;
		a+=b;
	}
	return a%2 == 0?1:2;
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
