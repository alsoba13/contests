#include <bits/stdc++.h>
using namespace std;

int f() {
	long long a, b;
	cin >> a >> b;
	int best = 1e9;
	for(int i = 0; i<100; i++){
		int ans = 0;
		int local_b = b, local_a = a;
		if(local_b==1){
			local_b = 2; ans++;
		}
		local_b+=i;
		ans+=i;
		while(local_a>0){
			local_a /= local_b;
			ans++;
		}
		if(ans>best) break;
		best = ans;
	}
	return best;
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
