#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string f() {
	int n, f, k;
	cin >> n >> f >> k;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	f = a[f-1];
	sort(a.rbegin(), a.rend());
	if (a[k-1] < f) return "YES";
	if (a[k-1] > f) return "NO";
	if (k == n) return "YES";
	if (a[k] == f) return "MAYBE";
	return "YES";
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
