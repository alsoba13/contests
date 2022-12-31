#include <bits/stdc++.h>
using namespace std;

std::vector<std::string> splitString(std::string str, char splitter){
    std::vector<std::string> result;
    std::string current = ""; 
    for(int i = 0; i < str.size(); i++){
        if(str[i] == splitter){
            if(current != ""){
                result.push_back(current);
                current = "";
            } 
            continue;
        }
        current += str[i];
    }
    if(current.size() != 0)
        result.push_back(current);
    return result;
}

bool g(vector<string> &aa, vector<string> &bb, int d, bool of) {
	int a = stoi(aa[d]);
	int b = stoi(bb[d]);
	if(d==2){
		if(of) return b == 0;
		return b == a+1;
	}
	if(of) {
		if(b != 0) return false;
		return g(aa, bb, d+1, true);
	}
	if (a == b) return g(aa, bb, d+1, false);
	if (a+1 == b) return g(aa, bb, d+1, true);
	return false;
}

bool f() {
	string a, b;
	cin >> a >> b;
	vector<string> aa = splitString(a, '.');
	vector<string> bb = splitString(b, '.');
	return g(aa, bb, 0, false);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"SI":"NO") << '\n';
	}
	return 0;
}
