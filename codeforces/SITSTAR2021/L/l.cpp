#include <bits/stdc++.h>
using namespace std;

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

long long f() {
	long long x; 
	cin >> x;
	long long ans = 0;
	vector<long long> fib(2, 1);
	while(true) {
		long long a = fib[fib.size()-2], b = fib[fib.size()-1];
		if (x<=a) break;
		fib.push_back(a+b);
		long long firstA = ((x%b)*inv(a, b))%b;
		if(x-firstA*a <= 0) continue;
		ans += (x-firstA*a-1)/(a*b);
		ans += (firstA!=0);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}
