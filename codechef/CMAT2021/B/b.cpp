#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;

void computePrimes() {
	long long lim = sqrt(1000000000);
    vector<bool> mark(lim + 1, false);    
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
}

vector<bool> segmentedSieve(long long L, long long R) {
    vector<bool> isPrime(R - L + 1, true);
    for (long long i = 0; i<primes.size(); i++)
        for (long long j = max(primes[i] * primes[i], (L + primes[i] - 1) / primes[i] * primes[i]); j <= R; j += primes[i])
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	computePrimes();
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<bool> isPrime = segmentedSieve(n, m);
		for(int i = 0; i<isPrime.size(); i++) if (isPrime[i]) cout << i + n << " "; cout << '\n';
	}
	return 0;
}
