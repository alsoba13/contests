#include <bits/stdc++.h>
using namespace std;

long long r(long long n_zeros) {
	if (n_zeros<0) return -1;
	if (n_zeros == 0) return 0;
	long long number = 1;
	long long MAX = 0;

	while(n_zeros>(MAX*5)+1) {
		MAX = (MAX*5)+1;
		number *= 5;
	}
	
	long long offset_number = 0;
	long long offset_MAX = 0;
	for(int i = 0; i<5; i++) {
		long long offset = MAX;
		if(i == 4) offset++;
		if(i == 4 && offset_MAX+offset-1 == n_zeros) return -1;
		if(offset_MAX+offset > n_zeros) break;
		offset_MAX += offset;
		offset_number += number;
	}
	long long ans = r(n_zeros-offset_MAX);
	if(ans == -1) return -1;
	return offset_number + ans;
}

string f(long long d, long long n) {
	long long big_num = r(n);
	if(big_num == -1){
		return "NINGUNO";
	}
	for(int i = 0; i<5; i++) {
		if(big_num+i == 0) continue;
		if((big_num+i)%d == 0) return to_string(big_num+i);
	}
	return "NINGUNO";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(true) {
		long long d, n;
		cin >> d >> n;
		if(d == 0 && n == 0) break;
		cout << f(d, n) << '\n';
	}
	return 0;
}