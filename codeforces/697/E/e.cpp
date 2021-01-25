#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<long long> factorials(1, 1);
int n_factorials = 0;
vector<long long> inv_factorials(1, 1);
int n_inv_factorials = 0;
long long inv(long long a, long long b) {
    long long b0 = b, x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        long long q = a/b;
        long long t = a;
        a = b;
        b = t%b;
        t = x0;
        x0 = x1 - q*x0;
        x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;  
}
long long fact(long long N) {
    if (N <= n_factorials) return factorials[N];
    for(int i = n_factorials+1; i<=N; i++)
        factorials.push_back(factorials[i-1] * i % MOD);
    n_factorials = N;
    return factorials[N];
}
long long inv_fact(long long N) {
    if (N <= n_inv_factorials) return inv_factorials[N];
    for(int i = n_inv_factorials+1; i<=N; i++)
        inv_factorials.push_back(inv_factorials[i-1] * inv(i, MOD) % MOD);
    n_inv_factorials = N;
    return inv_factorials[N];
}
long long C(long long N, long long K)
{
	if (K > N) return 0;
	return ((fact(N)*inv_fact(K))%MOD)*inv_fact(N-K)%MOD;
}

int f() {
	int n, k;
	cin >> n >> k;
	map<int, int> m;
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		m[a]++;
	}
	for(map<int,int>::reverse_iterator i = m.rbegin(); i!=m.rend(); i++) {
		if(k>i->second){
			k-=i->second;
		}else{
			return C(i->second, k);
		}
	}
	return 1;
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
