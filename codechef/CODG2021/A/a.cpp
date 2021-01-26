#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
void p() {
	const int N = 30010;
	vector<long long> lp(N+1);
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			primes.push_back (i);
		}
		for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
			lp[i * primes[j]] = primes[j];
	}
}
set<long long> fact(long long n) {
    vector<long long> factorization;
    for (int i = 0; i<primes.size(); i++) {
		int d = primes[i];
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
	set<long long> factors;
	factors.insert(1);
	for(int i = 0; i<factorization.size(); i++){
		set<long long> factors_aux = factors;
		for(set<long long>::iterator j = factors_aux.begin(); j!=factors_aux.end(); j++){
			factors.insert(*j*factorization[i]);
		}
	}
    return factors;
}
long long f() {
	long long n, k;
	cin >> n >> k;
	if (k>=30) return 0;
	if (n == 0) return 0;
	set<long long> factors = fact(n);
	long long ans = 0;
	for(set<long long>::iterator j = factors.begin(); j!=factors.end(); j++){
		if((*j & (1<<(k-1)))>0) ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	p();
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
