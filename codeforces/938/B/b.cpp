#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f() {
	long long n, c, d;
	cin >> n >> c >> d;
	vector<long long> a(n*n), b;
	for(int i = 0; i<a.size(); i++) cin >> a[i];
	sort(a.begin(), a.end());
	long long a1 = a[0];
	for (int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			b.push_back(a1+i*c+j*d);
		}
	}
	sort(b.begin(), b.end());
	for(int i = 0; i<a.size(); i++) if (a[i]!=b[i]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
