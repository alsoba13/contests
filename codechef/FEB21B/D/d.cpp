#include <bits/stdc++.h>
using namespace std;

int cnt_primes[1000001];
vector<bool> is_prime(1000001, true);
void cp(){
	int n = 1e6;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++)
		if (is_prime[i] && (long long)i * i <= n)
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
	cnt_primes[0] = 0;
	for(int i = 1; i<=n+1; i++)
		cnt_primes[i] = cnt_primes[i-1] + is_prime[i];
}

string f() {
	int n, k;
	cin >> n >> k;
	if(k==1){
		if(n>=3) return "Divyam";
		return "Chef";
	}
	if(cnt_primes[n]<=k)
		return "Chef";
	return "Divyam";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cp();
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
