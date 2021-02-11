#include <bits/stdc++.h>
using namespace std;

bool g(vector<long long> &a, int k, long long b) {
	long long sum = 0;
	for(int i = 0; i<a.size(); i++) {
		if(sum+a[i]<b){
			sum += a[i];
		}else{
			if(sum+a[i]>b){
				sum = a[i];
				k--;
			}else{
				sum = 0;
				k--;
			}
		}
		if(k<0) break;
	}
	if (sum>0) k--;
	return k>=0;
}

long long f() {
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	long long hi = 0; long long lo = 0;
	for(int i = 0; i<n; i++) {
		cin>>a[i];
		hi += a[i];
		lo = max(lo, a[i]);
	}
	long long ans;
	while(lo<=hi){
		long long mid = (lo+hi)/2;
		if(g(a, k, mid)){
			ans = mid;
			hi = mid-1;
		}else
			lo = mid+1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
