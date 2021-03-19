#include <bits/stdc++.h>
using namespace std;

const int MAX = 100; //10000100;
vector<int> primes;
int sieve[MAX+5];

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

vector<pair<int, int> > factorization(int x) {
    vector<pair<int, int> > factors;
    while (x!=1) {
        int div = sieve[x];
        int exp = 0;
        while(sieve[x]==div){
            x = x/div;
            exp++;
        }
        factors.push_back(make_pair(div,exp));
    }
    return factors;
}

int num_factors[MAX+5];
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

int main() {
	compute_primes();
    printf("List of primes up to %d:\n", MAX);
    for(int i = 0; i<primes.size(); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;
    printf("Factorization of each number up to %d\n", MAX);
    for (int i = 2; i<MAX; i++){
        vector<pair<int, int> > factors = factorization(i);
        cout << i << ": ";
        for(int j=0; j<factors.size(); j++) {
            if(j>0) cout << "* ";
            cout << factors[j].first << "^" << factors[j].second << " ";
        }
        cout << endl;
    }
	return 0;
}
