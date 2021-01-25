#include <bits/stdc++.h>
using namespace std;


vector<long long> is_prime(30000, true);
void p(){
	int n = is_prime.size();
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}

long long f() {
	long long d;
	cin >> d;
	long long first = 1+d;
	while(!is_prime[first]){
		first++;
	}
	long long second = first+d;
	while(!is_prime[second]){
		second++;
	}
	return first*second;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	p();
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
