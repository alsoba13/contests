#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;
int const maxn = 2e5 + 5, max_val = 2e5 + 5;
int smallest_prime[max_val];
multiset<int> exponents[max_val];
int n;
map<int, int> factorization[maxn];

long long add(int i, int x, long long ans){
	while (x != 1) {
		int div = smallest_prime[x];
		int q = 0;
		while(smallest_prime[x]==div){
			x /= div;
			q++;
		}
		int min_exp = 0;
		if(exponents[div].size()==n) {
			min_exp=*exponents[div].begin();
		}
		int factorization_before = factorization[i][div];
		if(factorization_before!=0){
			exponents[div].erase(exponents[div].find(factorization_before));
		}
		factorization[i][div]+=q;
		exponents[div].insert(factorization_before+q);
		if(exponents[div].size() == n) {
			for(int i = min_exp; i<*exponents[div].begin(); i++){
				ans = (ans * div)%MOD;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> n >> q;
    for (long long i = 2; i < max_val; i++) {
        if (smallest_prime[i] == 0) {
            smallest_prime[i] = i;
            for (long long j = i * i; j < max_val; j += i) {
                if (smallest_prime[j] == 0) smallest_prime[j] = i;
            }
        }
    }
	long long ans = 1;
	for(int i = 0; i<n; i++){
		int x; cin >> x;
		ans = add(i, x, ans);
	}
	for(int i = 0; i<q; i++){
		int p,q; cin >> p >> q;
		p--;
		ans = add(p, q, ans);
		cout << ans << '\n';
	}
	return 0;
}
