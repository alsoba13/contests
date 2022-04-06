#include <bits/stdc++.h>
using namespace std;

void cross(){
	cout << "W\n";
	cout.flush();
}
void teleport(int room){
	cout << "T " << room << "\n";
	cout.flush();
}
void guess(long long guess){
	cout << "E " << guess << "\n";
	cout.flush();
}
void slv() {
	int n, k;
	cin >> n >> k;
	long long sumT, uniqueSumW = 0;
	set<int> seenW;
	int room, passages;
	cin >> room >> passages;
	sumT = passages;
	for(int i = 0; i<k/2; i++) {
		cross();
		cin >> room >> passages;
		if(seenW.find(room) == seenW.end()) {
			seenW.insert(room);
			uniqueSumW += passages;
		}
		teleport(rand()%n+1);
		cin >> room >> passages;
		sumT += passages;
	}
	guess((1.0*sumT*n/4001+uniqueSumW)/2);
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i<t; i++) {
		slv();
	}
	return 0;
}
