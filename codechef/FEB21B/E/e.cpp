#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
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
long long nCk(long long N, long long K)
{
	if (K > N || K < 0) return 0;
	return ((fact(N)*inv_fact(K))%MOD)*inv_fact(N-K)%MOD;
}

//FTT implementation by "tfg". Copied from https://codeforces.com/contest/1473/submission/104315264
const int me = 20;
const int ms = 1 << me;
long long fexp(long long x, long long e, long long mod = MOD) {
	long long ans = 1;
	x %= mod;
	for(; e > 0; e /= 2, x = x * x % mod) {
		if(e & 1) ans = ans * x % mod;
	}
	return ans;
}
#define add(x, y) x+y>=MOD?x+y-MOD:x+y
const int gen = 3; // use search() from PrimitiveRoot.cpp if MOD isn't 998244353
int bits[ms];
long long root[ms];
void initFFT() {
	root[1] = 1;
	for(int len = 2; len < ms; len += len) {
		int z = (int) fexp(gen, (MOD - 1) / len / 2);
		for(int i = len / 2; i < len; i++) {
			root[2 * i] = root[i];
			root[2 * i + 1] = (long long)((long long) root[i] * z % MOD);
		}
	}
}
void pre(long long n) {
	long long LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}
std::vector<long long> fft(std::vector<long long> a, bool inv = false) {
	int n = (int) a.size();
	pre(n);
	if(inv) {
		std::reverse(a.begin() + 1, a.end());
	}
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(i < to) { std::swap(a[i], a[to]); }
	}
	for(int len = 1; len < n; len *= 2) {
		for(int i = 0; i < n; i += len * 2) {
			for(int j = 0; j < len; j++) {
				long long u = a[i + j], v = (long long)((long long) a[i + j + len] * root[len + j] % MOD);
				a[i + j] = add(u, v);
				a[i + j + len] = add(u, MOD - v);
			}
		}
	}
	if(inv) {
		long long rev = fexp(n, MOD-2, MOD);
		for(int i = 0; i < n; i++)
			a[i] = (int)(a[i] * rev % MOD);
	}
	return a;
}
template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}
std::vector<long long> operator *(std::vector<long long> a, std::vector<long long> b) {
	while(!a.empty() && a.back() == 0) a.pop_back();
	while(!b.empty() && b.back() == 0) b.pop_back();
	if(a.empty() || b.empty()) return std::vector<long long>(0, 0);
	int n = 1;
	while(n-1 < (int) a.size() + (int) b.size() - 2) n += n;
	a.resize(n, 0);
	b.resize(n, 0);
	a = fft(a, false);
	b = fft(b, false);
	for(int i = 0; i < n; i++) {
		a[i] = (long long) ((long long) a[i] * b[i] % MOD); 
	}
	return fft(a, true);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	initFFT();
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int ct[30];
	fill(ct, ct+30, 0);
	for(int i=0; i<n; i++){
		for(int k=0; k<30; k++){
			ct[k] += ((a[i]&(1<<k))>0);
		}
	}
	long long ans[n+1];
	fill(ans, ans+n+1, 0);
	for(int k = 0; k<30; k++){
		long long a = ct[k];
		long long b = n-ct[k];
		if(a==0) continue;
		vector<long long> fx, gx;
		for(int i = 1; i<=a; i++){
			if(i%2==0) fx.push_back(0);
			else fx.push_back(nCk(a, i));
		}
		for(int i = 0; i<=b; i++){
			gx.push_back(nCk(b, i));
		}
    	vector<long long> res = fx*gx;
		for(int m = 1; m<=n; m++){
			ans[m] = (ans[m] + (1<<k)*res[m-1])%MOD;
		}
	}
	for(int i = 2; i<=n; i++) ans[i] = (ans[i]+ans[i-1])%MOD;
	int q;
	cin >> q;
	for(int i = 0; i<q; i++){
		int m; cin >> m;
		cout << ans[m] << '\n';
	}
}
