#include <bits/stdc++.h>
using namespace std;

vector<int> pr;

void p() {
	const int N = 10000000;
	int lp[N+1];
	pr = vector<int>();

	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

map<int, int> trial_division4(long long n) {
    map<int, int> factorization;
    for (int i = 0; i<pr.size(); i++) {
		int d = pr[i];
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n > 1)
        factorization[n]++;
    return factorization;
}

int f() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	map<long long, bool> m;
	int ans = 0;
	for(int i = 0; i<n; i++) {
		map<int, int> fact = trial_division4(a[i]);
		long long mul = 1;
		for(map<int, int>::iterator j = fact.begin(); j!=fact.end(); j++){
			if(j->second%2 == 1)
				mul *= j->first;
		}
		if(m[mul]){
			ans++;
			m=map<long long, bool>();
		}
		m[mul] = true;
	}
	if(m.size()>0) ans++;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	p();
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
