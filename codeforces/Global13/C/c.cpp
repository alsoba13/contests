#include <bits/stdc++.h>
using namespace std;

long long f() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	long long ans = 0;
	vector<long long> b(n, 0);
	for(int i = 0; i<n; i++){
		long long current_jumps = max(a[i]-b[i]-1, 0LL);
		ans += current_jumps;
		for(int j = i+1; j<min(i+1+a[i], (long long)n); j++){
			if(j == i+1){
				if(current_jumps+b[i]>=a[i]) {
					b[j]+=current_jumps+b[i]-a[i]+1;
				}
			}else {
				b[j]++;
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
