#include <bits/stdc++.h>
using namespace std;


vector<bool> is_prime(1000010, true);
vector<int> sol(1000010, 0);

void fillsol() {
	for(int i = 2; i<sol.size(); i++)
		if(is_prime[i] && is_prime[i-2])
			sol[i] = sol[i-1]+1;
		else
			sol[i] = sol[i-1];
}

void p(){
	int n = is_prime.size();
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) 
		if (is_prime[i])
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	p();
	fillsol();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << sol[n] << '\n';
	}
	return 0;
}
