#include <bits/stdc++.h>
using namespace std;

int g(int x){
	cout << "? " << x << endl << flush;
	cin >> x;
	return x;
}

int main() {
	int n;
	cin >> n;
	int lo = 1, hi = n;
	while(lo!=hi){
		int mid = (lo+hi)/2;
		int x1, x2;
		x1 = g(mid);
		x2 = g(mid+1);
		if(x1>x2){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}
	cout << "! " << lo << endl << flush;
}