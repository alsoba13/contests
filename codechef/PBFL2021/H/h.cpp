#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	for(int i = 0; i<n/2; i++){
		for(int j = 0; j<n/2-1; j++){
			cout << n/2+1+j-i;
		}
		cout << endl;
	}
	for(int i = 0; i<n/2-1; i++){
		cout << i+1;
	}
	cout << endl;
	for(int i = n/2-1; i>=0; i--){
		for(int j = 0; j<n/2-1; j++){
			cout << n/2+1+j-i;
		}
		cout << endl;
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
