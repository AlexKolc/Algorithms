#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 5000;

int main() {
    //freopen("lis.in", "r", stdin);
    //freopen("lis.out", "w", stdout);
	int n;
	cin >> n;
	int a[N], d[N], p[N];
	for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i])
                if (d[j] + 1 > d[i]) {
                    d[i] = d[j] + 1;
                    p[i] = j;
                }
    }
     
    int ans = d[0],  pos = 0;
    for (int i = 0; i < n; ++i)
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    //cout << ans << endl;
     
    vector <int> answer;
    while (pos != -1) {
        answer.push_back(a[pos]);
        pos = p[pos];
    }
    for (int i = answer.size() - 1; i > -1; --i)
        cout << answer[i] << ' ';
	return 0;
}


