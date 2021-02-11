#include <bits/stdc++.h>
using namespace std;

map<long long, int> trial_division2(long long n) {
    map<long long, int> factorization;
    while (n % 2 == 0) {
        factorization[2]++;
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n > 1)
        factorization[n]++;
    return factorization;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n;
	cin >> n;
	long long ans = 1;
	map<long long, int> m = trial_division2(n);
	for(map<long long, int>::iterator i = m.begin(); i!=m.end(); i++){
		if (i->first != 2){
			ans *= (i->second+1);
		}
	}
	cout << 2*ans << endl;
	return 0;
}
