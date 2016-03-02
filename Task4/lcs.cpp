#include <iostream>
#include <vector>

using namespace std;

const int N = 2002;
long long n, m, a[N], b[N], d[N][N];
vector <int> ans;

int lcs(int i, int j) {
    if (!i || !j) 
    	return 0;
    if (d[i][j] != -1)
        return d[i][j];
    if (a[i] == b[j])
        d[i][j] = lcs(i - 1, j - 1) + 1;
    else
        d[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
    return d[i][j];
}

void lcsAnswer(){
    int i = n, j = m;
    while (i && j) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else {
            if (d[i - 1][j] > d[i][j - 1])
                i--;
            else
                j--;
        }
    }
}

int main() {
	freopen("lcs.in", "r", stdin);
	freopen("lcs.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++)
			d[i][j] = -1;
	cout << lcs(n, m) << endl;
	lcsAnswer();
	for (int i = ans.size() - 1; i > -1; i--)
		cout << ans[i] << ' ';
	return 0;
}