#include <bits/stdc++.h>
using namespace std;
 
int M[200500];
 
long long C(long N, long K)
{
   if (K > N) return 0;
   long long r = 1;
   long long d;
   for (d = 1; d <= K; d++)
   {
      r *= N--;
      r /= d;
   }
   return r;
}
 
long long f() {
	int n, k = 2, m = 3;
	cin >> n;
	for(int i = 0; i<=n+k+10; i++) M[i] = 0;
	vector<int> a(n);
	set<int> s;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		M[a[i]]++;
	}
	for(int i = 0; i<n; i++) s.insert(a[i]);
	for(int i = 1; i<=n+k+10; i++){
		M[i] += M[i-1];
	}
	long long sol = 0;
	for(set<int>::iterator i = s.begin(); i != s.end(); i++) {
		int qi = M[*i]-M[*i-1];
		int qT = M[*i+k] - M[*i-1];
		if(qT<m) continue;
		for(int j = 0; j<M[*i]-M[*i-1] && qT-j-1 >= m-1; j++) {
			sol += C(qT-j-1, m-1);
		}
	}
	return sol;
}
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}