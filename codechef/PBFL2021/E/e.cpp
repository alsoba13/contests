#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		for(int j = 1; j<=i+1; j++){
			cout << j << " ";
		}
		cout << '\n';
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
