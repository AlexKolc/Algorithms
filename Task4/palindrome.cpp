#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <climits>

using namespace std;

const int N = 2000;
string s, p;
int d[N][N];

int searchLength(int i, int j) {
	if (d[i][j] == -1) 
    	if (s[i] == s[j]) 
       		d[i][j] = searchLength(i + 1, j - 1) + 2;
     	else 
       		d[i][j] = max(searchLength(i + 1, j), searchLength(i, j - 1));
   return d[i][j];
}

void searchPal(int l, int r, int lp, int rp) {
    while (l <= r) {
     	if (l == r && d[l][r] == 1)
       		p[lp++] = s[l++];
    	else if (s[l] == s[r]) {
         	p[lp++] = s[l++];
         	p[rp--] = s[r--];
        }
        else if (d[l + 1][r] > d[l][r - 1])
        	l++;
        else
            r--;
    }
}

int main() {
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < s.size(); j++)
			if (i == j)
				d[i][j] = 1;
			else if (i > j)
				d[i][j] = 0;
			else
				d[i][j] = -1;
	int len = searchLength(0, s.size() - 1);
	cout << len << endl;
	p = s;
	searchPal(0, s.size(), 0, len - 1);
	for (int i = 0; i < len; i++)
		cout << p[i];
	return 0; // HTEOLFEOLEH
}