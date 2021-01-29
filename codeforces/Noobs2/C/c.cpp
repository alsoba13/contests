#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, k;
	cin >> n >> k;
	vector<int> a;
	int ans = 0;
	for(int i = 0; i<n; i++){
		int b;
		cin >> b;
		if (b>=k) ans++;
		else a.push_back(b);
	}
	sort(a.begin(), a.end());
	for(int i = 0; i<a.size(); i++) {
		if(i != a.size()-1){
			if(a[i]+a.back()>=k) {
				ans++;
				a.pop_back();
			}
		}
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
