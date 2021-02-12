#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			int a; cin >> a;
			cout << 720720 + ((i+j)%2?a*a*a*a:0) << " ";
		}
		cout << endl;
	}
	return 0;
}
