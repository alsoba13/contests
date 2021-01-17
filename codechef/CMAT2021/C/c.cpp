#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, s, w;
	cin >> n >> m >> s >> w;
	parent = vector<int>(n);
	for(int i = 0; i<n; i++) make_set(i);
	for(int i = 0; i<m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		union_sets(a, b);
	}
	set<int> parents;
	for(int i = 0; i<n; i++){
		parents.insert(find_set(i));
	}
	int ans = s;
	ans += (parents.size()-1)*min(s,w);
	cout << ans << '\n';
}
