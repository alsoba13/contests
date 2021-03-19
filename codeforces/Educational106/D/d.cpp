#include <bits/stdc++.h>
using namespace std;

const int MAX = 20000100;
vector<int> primes;
int sieve[MAX+5];
int num_factors[MAX+5];

void compute_primes() {
	for(int i = 2; i <= MAX; i++) {
		if(sieve[i]==0){
			sieve[i] = i;
			primes.push_back(i);
		}
		for(int j=0; j<primes.size(); j++) {
			if (i*primes[j]>=MAX) break;
			sieve[i*primes[j]]=primes[j];
			if (i%primes[j] == 0) break;
		}
	}
}

int count_factors(int x) {
    if(num_factors[x]!=0) return num_factors[x];
    int ans = 0, xt = x;
    while (x!=1) {
        ans++;
        int div = sieve[x];
        while(sieve[x]==div){
            x = x/div;
        }
    }
    num_factors[xt] = ans;
    return ans;
}

vector<long long> divisorsOf(long long n){
	vector<long long> divisors;
	for (long long i=1; i*i<=n; i++) {
        if (n%i == 0) {
			divisors.push_back(i);
            if (n/i != i) divisors.push_back(n/i);
        }
    }
	return divisors;
}

long long f() {
	long long c, d, x;
	cin >> c >> d >> x;
	long long ans = 0;
	vector<long long> divisors = divisorsOf(x);
	for(long long i = 0; i<divisors.size(); i++){
		if((d+x/divisors[i])%c != 0) continue;
		long long ab = (d+x/divisors[i])/c;
		ans += 1<<count_factors(ab);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	compute_primes();
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
