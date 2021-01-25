#include <bits/stdc++.h>
using namespace std;

void slv(){
	int n; 
	string b;
	cin >> n >> b;
	cout << 1;
	b[0]++;
	for(int i = 1; i<n; i++){
		if(b[i]+1==b[i-1]) cout << 0;
		else {
			cout << 1;
			b[i]++;
		}
	}
	cout << '\n';
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
