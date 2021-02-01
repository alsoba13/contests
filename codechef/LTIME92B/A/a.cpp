#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	int odd = 0; 
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		if (a%2==1) odd++;
	}
	return min(n-odd, odd);
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
