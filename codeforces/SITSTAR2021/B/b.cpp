#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	if(n%3 == 0){
		cout << n/3-1 << " " << n/3 << " " << n/3+1 << '\n';
	}else{
		cout << -1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
