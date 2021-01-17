#include <bits/stdc++.h>
using namespace std;


void slv() {
	int n;
	cin >> n;
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j<(n-i)*2-1; j++){
			if(i==0 || j == 0 || j == (n-i)*2-2) cout << j+1 + i;
			else cout << " ";
		}
		cout << '\n';
	}
	cout << n << '\n';
	for(int i = n-2; i>=0; i--){
		for(int j = 0; j<(n-i)*2-1; j++){
			if(i==0 || j == 0 || j == (n-i)*2-2) cout << j+1 + i;
			else cout << " ";
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
