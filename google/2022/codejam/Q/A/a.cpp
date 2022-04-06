#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, m;
	cin >> n >> m;
	cout << "\n";
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++) {
			if(i == 0 && j == 0) cout << "..";
			else cout << "+-";
		}
		cout << "+\n";
		for(int j = 0; j<m; j++) {
			if(i == 0 && j == 0) cout << "..";
			else cout << "|.";
		}
		cout << "|\n";
	}
	for(int j = 0; j<m; j++) cout << "+-";
	cout << "+\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		slv();
		//cout << f() << '\n';
	}
	return 0;
}
