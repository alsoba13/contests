#include <vector>
#include <set>
#include <iostream>
using namespace std;


long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}


int f() {
	long long C, S;
	cin >> C >> S;
	vector<long long> c(C), s(S);
	for(int i = 0; i<C; i++) {
		cin >> c[i];
	}
	for(int i = 0; i<S; i++) {
		cin >> s[i];
	}
	set<pair<long long, long long> > sol;
	for(int i = 0; i<C; i++) {
		for(int j = 0;j<S; j++){
			sol.insert(make_pair(c[i]/gcd(c[i],s[j]), s[j]/gcd(c[i],s[j])));
		}
	}
	return sol.size();
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}

	return 0;
}