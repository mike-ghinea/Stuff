// solutie triunghiul lui Pascal C(n-(k-1)*(w-1), k)
// prof. Eugen Nodea

# include <fstream>
# include <cstring>
# define M 666013
using namespace std;

ifstream f("nmult.in");
ofstream g("nmult.out");

int n, k, w;
int L0[100001], L[100001];

void comb(int N)
{
    int i, j;
    L0[0] = L0[1] = 1; // linia 1
    for (i=2; i<=N; ++i)
    {
        L[0] = L[i] = 1;
        for (j=1; j<i; ++j)
            L[j] = (L0[j-1] % M + L0[j]  % M ) % M;
        memcpy(L0, L, sizeof(L));
    }
}
int main()
{
	f >> n >> k >> w;

	comb(n - (k-1) * (w-1));
	g << L[k];

	return 0;
}
