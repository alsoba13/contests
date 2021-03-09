#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, k;
	cin >> n >> k;
	vector<int> a;
	for(int i = k/2+(k%2!=0); i<k; i++){
		a.push_back(i);
	}
	for(int i = k+1; i<=n; i++){
		a.push_back(i);
	}
	cout << a.size() << '\n';
	for(int i = 0; i<a.size(); i++) cout << a[i] << " "; cout << endl;
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
