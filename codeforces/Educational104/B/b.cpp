#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, k;
	cin >> n >> k;
	k--;
	if(n%2==0){
		return k%n+1;
	}
	return (k+(k/(n/2)))%n+1;
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
