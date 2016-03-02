#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	freopen("levenshtein.in", "r", stdin);
	freopen("levenshtein.out", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	int n1 = s1.size(), n2 = s2.size();
	int **d = new int*[n1 + 1];
	for (int i = 0; i <= n1; i++)
		d[i] = new int[n2 + 2];
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			if (!i && !j) {
				d[i][j] = 0;
			} else if (!j && i > 0) {
				d[i][j] = i;
			} else if (!i && j > 0) {
				d[i][j] = j;
			} else {
				d[i][j] = min(d[i][j - 1] + 1, min(d[i - 1][j] + 1, 
					d[i - 1][j - 1] + ((s1[i - 1] == s2[j - 1]) ? (0) : (1)))
				);
			}
		}
	}
	cout << d[n1][n2];
	for (int i = 0; i <= n1; i++)
		delete[] d[i];
	delete[] d;
	return 0;
}
