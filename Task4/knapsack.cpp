#include <fstream>
#include <algorithm>

using namespace std;

int N, M, m[1003], c[10003], a[1003][10003];

ifstream in("knapsack.in");
ofstream out("knapsack.out");

int FindAns(int count, int k, int s){
	if (a[k][s] == 0) {
        out << count << endl;
	    return 0;
    }
	if (a[k - 1][s] == a[k][s])
	    FindAns(count, k - 1, s);
	else{
	    FindAns(count + 1, k - 1, s - m[k]);
	    out << k << ' ';
	}
}

int main() {
    in >> N >> M;
    for (int i = 1; i <= N; i++)
        in >> m[i];
    for (int i = 1; i <= N; i++)
        in >> c[i];
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            a[i][j] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= M; j++)
            if (j >= m[i])
                a[i][j] = max(a[i - 1][j], a[i - 1][j - m[i]] + c[i]);
            else
                a[i][j] = a[i - 1][j];
    FindAns(0, N, M);
    return 0;
}


