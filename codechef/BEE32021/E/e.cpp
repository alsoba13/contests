#include <bits/stdc++.h>
using namespace std;

vector<long long> pr;

void p(){
	const int N = 1e6;
	int lp[N+1];

	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

map<long long, int> factorize(long long n){
	map<long long, int> factors;
	for(int i = 0; i<pr.size(); i++){
		if(pr[i]*pr[i]>n)break;
		while(n%pr[i] == 0){
			factors[pr[i]]++;
			n /= pr[i];
		}
	}
	if (n != 1) factors[n]++;
	return factors;
}

long long c(map<long long, int> factors) {
	long long mult = 1;
	for(map<long long, int>::iterator it = factors.begin(); it!=factors.end(); it++){
		mult *= (it->second+1);
	}
	return mult - factors.size();
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

long long lcm (long long a, long long b) {
	return a*b/gcd(a,b);
}

void slv() {
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	for(int i = 0; i<n; i++){
		cin >> a[i];
		b[i] = c(factorize(a[i]));
	} 
	int max_ans = 0, i_ans = -1, j_ans = -1;
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++) {
			long long l = lcm(b[i], b[j]);
			if (l>max_ans) {
				max_ans = l;
				i_ans = i;
				j_ans = j;
			}
			if(l==max_ans){
				if(max(a[i], a[j])>max(a[i_ans], a[j_ans])){
					i_ans = i;
					j_ans = j;
				}
				if(max(a[i], a[j])==max(a[i_ans], a[j_ans]) && min(a[i], a[j])>min(a[i_ans], a[j_ans])){
					i_ans = i;
					j_ans = j;
				}
			}
		}
	}
	cout << max(a[i_ans], a[j_ans]) << " " << min(a[i_ans], a[j_ans]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	p();
	while (t--) {
		slv();
	}
	return 0;
}
