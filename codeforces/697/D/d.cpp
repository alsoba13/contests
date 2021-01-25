#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	vector<long long> ones, twos;
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = 0; i<n; i++) {
		int b;
		cin >> b;
		if(b == 1) ones.push_back(a[i]);
		else twos.push_back(a[i]);
	}
	sort(ones.rbegin(), ones.rend());
	sort(twos.rbegin(), twos.rend());
	long long ans = 0;
	int i1 = 0, i2 = 0;
	while(m>0 && (i1<ones.size() || i2<twos.size())) {
		if(i1>=ones.size()) {
			m-=twos[i2++];
			ans+=2;
			continue;
		}
		if(i2>=twos.size() || m<=ones[i1]) {
			m-=ones[i1++];
			ans++;
			continue;
		}
		if(i1<ones.size()-1 && ones[i1]+ones[i1+1]>twos[i2]){
			m-=ones[i1++];
			ans++;
		}else{
			ans+=2;
			m-=twos[i2++];
		}
	}
	if(m>0) return -1;
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