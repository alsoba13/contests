#include <bits/stdc++.h>
using namespace std;

long long a[100001];
long long cum[100001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long k;
	int q, n;
	cin >> n >> q >> k;
	for(int i = 0; i<n; i++) cin >> a[i];
	cum[0] = 0;
	for(int i = 1; i<n; i++){
		cum[i] = cum[i-1]+a[i]-a[i-1]-1;
	}
	for(int i = 0; i<q; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << 2*cum[r]-2*cum[l]+a[l]+k-a[r]-1 << '\n';
	}
}

