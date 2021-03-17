#include <bits/stdc++.h>
using namespace std;

void slv(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int k = 0;
	vector<int> sol(n);
	for(int i = n-1; i>=0; i--){
		k = max(k, a[i]);
		sol[i] = k>0?1:0;
		k--;
	}
	for(int i = 0; i<n; i++) cout << sol[i] << " "; cout << '\n';
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
