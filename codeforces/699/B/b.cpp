#include <bits/stdc++.h>
using namespace std;

long long f() {
	long long n, k;
	cin >> n >> k;
	vector<int> h(n);
	for(int i = 0; i<n; i++) cin >> h[i];
	while(true){
		int where = -1;
		for(int i = 0; i<n-1; i++){
			if(h[i]<h[i+1]) {
				where = i; break;
			}
		}
		if (where==-1) break;
		h[where]++;
		k--;
		if(k==0) return where+1;
	}
	return -1;
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
