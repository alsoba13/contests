#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, min, max, c, sol1 = 0, sol2 = 0;
	cin >> N;
	char letter, password[200];
	for(int i = 0; i < N; i++) {
		c = 0;
		scanf("%d-%d %c: %s", &min, &max, &letter, password);
		for (int j = 0; j < strlen(password); j++) if (password[j] == letter) c++;
		if (min <= c && c <= max) sol1++;
		if ((password[min-1] == letter && password[max-1] != letter) || (password[min-1] != letter && password[max-1] == letter)) sol2++;
	}
	cout << "Problem1: " << sol1 << endl << "Problem2: " << sol2 << endl;
}
