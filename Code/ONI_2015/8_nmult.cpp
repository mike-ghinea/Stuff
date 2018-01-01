// prof. Tucu Galatan

#include <fstream>
using namespace std;

#define MOD 666013
ifstream fin("nmult.in");
ofstream fout("nmult.out");

// nr[i][v] - in cate moduri pot avea cel mult valoarea v la poz i
int nr[2][100001];
int n, k, w, p, c, i;

int main()
{
	fin >> n >> k >> w;
	for ( int v = 1; v <= n; ++v )
		nr[0][v] = v;
	for ( i = 2, c = 1, p = 0; i <= k; p = !p, c = !c, ++i )
	{
		nr[c][(i - 1)* w] = 0;
		for ( int v = (i - 1)* w + 1; v <= n - (k - i) * w; ++v )
			nr[c][v] = (nr[c][v - 1] + nr[p][v - w]) % MOD;
	}
	fout << nr[p][n] << '\n';
	fin.close();
	fout.close();
	return 0;
}
