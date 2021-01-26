#include <bits/stdc++.h>
using namespace std;

int f() { 
	int n; 
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	int max_local = 0, ans = 0;
	for(int i = 0; i<n; i++) {
		if(a[i] == 1){
			max_local = 1;
		}else{
			if (a[i] == max_local+1){
				max_local = a[i];
			} else{
				max_local = 0;
			}
		}
		ans = max(ans, max_local);
	}
	return ans;
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
