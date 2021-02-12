#include <bits/stdc++.h>
using namespace std;
long long base = 10000;
long long myfloor(long long a);
long long myceil(long long a){
	if(a<0) return -myfloor(-a);
	return (a/base+(a%base>0))*base;
}
long long myfloor(long long a){
	if(a<0) return -myceil(-a);
	return (a/base)*base;;
}
unsigned long long mysqrt(unsigned long long a){
	unsigned long long lo = 0, hi = 1, ans = 0;
	while(hi*hi<=a) hi*=2;
	while(lo<=hi){
		unsigned long long mid = (lo+hi)/2;
		if(mid*mid<=a){
			lo = mid+1;
			ans = mid;
		}else{
			hi = mid-1;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long double dX, dY, dR;
	cin >> dX >> dY >> dR;
	long long X = llround(dX*base), Y = llround(dY*base), R = llround(dR*base);
	long long ans = 0;
	for(long long x = myceil(X-R); x<=myfloor(X+R); x+=base){
		unsigned long long sq = mysqrt(R*R-(x-X)*(x-X));
		long long y1, y2;
		y1 = myfloor(Y+sq);
		y2 = myceil(Y-sq);
		if(y1>=y2) ans+=y1/base-y2/base+1;
	}
	cout << ans << '\n';
	return 0;
}
