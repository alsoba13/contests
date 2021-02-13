#include <bits/stdc++.h>
using namespace std;

bool f(){
	long long A, B, n;
	cin >> A >> B >> n;
	vector<pair<long, long> > a(n);
	for(int i = 0; i<n; i++) cin >> a[i].first;
	for(int i = 0; i<n; i++) cin >> a[i].second;
	sort(a.begin(), a.end());
	a[n-1].second -= A;
	for(int i = 0; i<n; i++){
		if(B<=0) return false;
		if(a[i].second <= 0) continue;
		long long c = a[i].second / A + (a[i].second % A!=0);
		B-=a[i].first*c;
	}
	if(B>0) return true;
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
