#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool f() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = 0; i<n; i++) cin >> b[i];
	cin >> m;
	vector<int> d(m);
	for(int i = 0; i<m; i++) cin >> d[i];
	map<int, int> missing;
	for(int i = 0; i<n; i++) {
		if (a[i] != b[i]) missing[b[i]]++;
	}
	for(int i = 0; i<m; i++) {
		missing[d[i]]--;
	}
	for(map<int, int>::iterator i = missing.begin(); i!=missing.end(); i++) {
		if(i->second > 0) return false;
	}
	for(int i = 0; i<n; i++) {
		if(d[m-1] == b[i]) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
