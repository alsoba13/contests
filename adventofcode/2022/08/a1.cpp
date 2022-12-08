#include <iostream>
#include <vector>
using namespace std;

int f() {
	vector<vector<int> > g(99, vector<int>(99));
	for(int i = 0; i<99; i++){
		string a;
		cin >> a;
		for(int j = 0; j<99; j++) g[i][j] = a[j]-'0';
	}
	vector<vector<bool> > sol(99, vector<bool>(99, false));
	for(int i = 0; i<99; i++){
		for(int j = 0; j<99; j++) {
			if (i == 0 || j == 0 || i == 98 || j == 98) {
				sol[i][j] = true;
			}
		}
	}
    for(int i = 1; i<98; i++) {
        int max_so_far = g[i][0];
        for(int j = 1; j<98; j++) {
            if(g[i][j] > max_so_far) {
                sol[i][j] = true;
                max_so_far = max(max_so_far,g[i][j]);
            }
        }
    }
    for(int i = 1; i<98; i++) {
        int max_so_far = g[i][98];
        for(int j = 97; j>=0; j--) {
            if(g[i][j] > max_so_far) {
                sol[i][j] = true;
                max_so_far = max(max_so_far,g[i][j]);
            }
        }
    }
    for(int i = 1; i<98; i++) {
        int max_so_far = g[0][i];
        for(int j = 1; j<98; j++) {
            if(g[j][i] > max_so_far) {
                sol[j][i] = true;
                max_so_far = max(max_so_far,g[j][i] );
            }
        }
    }
    for(int i = 1; i<98; i++) {
        int max_so_far = g[98][i];
        for(int j = 97; j>=0; j--) {
            if(g[j][i] > max_so_far) {
                sol[j][i] = true;
                max_so_far = max(max_so_far,g[j][i]);
            }
        }
    }
    int ans = 0;
	for(int i = 0; i<99; i++){
		for(int j = 0; j<99; j++) {
			cout << sol[i][j] << " ";
            if(sol[i][j]) ans ++;
		}
		cout << endl;
	}
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << f() << '\n';
	return 0;
}
