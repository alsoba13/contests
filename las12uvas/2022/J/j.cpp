#include <bits/stdc++.h>
using namespace std;

long long f(int n) {
	long long sum = 0; 
	long long M = 0;
	for(int i = 0; i<n; i++) {
		long long a;
		cin >> a;
		M = max(a, M);
		sum += a;
	}
	if(M > sum-M) return M*2;
	return sum;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(true) {
		int n;
		cin >> n;
		if(cin.eof()) break;
		cout << f(n) << '\n';
	}
	return 0;
}