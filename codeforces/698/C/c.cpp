#include <bits/stdc++.h>
using namespace std;

bool f() {
	long long n;
	cin >> n;
	vector<long long> a(2*n);
	for(long long i=0; i<2*n; i++){
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	long long c = 0;
	set<long long> nums;
	for(long long i = 0; i<n; i++){
		if(a[2*i]!=a[2*i+1]) return false;
		if(a[2*i]-c<=0) return false;
		if((a[2*i]-c)%(2*(n-i)) != 0) return false;
		long long num = (a[2*i]-c)/(2*(n-i));
		if(nums.find(num) != nums.end()) return false;
		nums.insert(num);
		c += 2*num;
	}
	return true;
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
