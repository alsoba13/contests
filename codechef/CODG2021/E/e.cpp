#include <bits/stdc++.h>
using namespace std;

bool f() {
	string a, b;
	cin >> a >> b;
	int x=0, y=0;
	for(int i = 0; i<a.size(); i++){
		if (a[i] == 'x') x++;
	}
	int xb = 0;
	for(int i = 0; i<b.size(); i++){
		if (b[i] == 'x'){
			if((x+xb)%2==0){
				if(x>0) x--;
				else return false;
			}
			xb++;
		}
		if (b[i] == 'y'){
			if((x+xb)%2==1){
				if(x>0) x--;
				else return false;
			}
		}
	}
	return true;
}

int main() {
	cout << (f()?"YES":"NO") << '\n';
	return 0;
}
