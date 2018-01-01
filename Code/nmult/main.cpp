// solutie invers modular C(n-(k-1)*(w-1), k)
// prof. Eugen Nodea

# include <fstream>
# define M 666013
using namespace std;

ifstream f("nmult.in");
ofstream g("nmult.out");

long long n, k, w;
void GCD (long long A, long long B, long long &X, long long &Y)
{
    long long X0, Y0;
    if (B ==0 )
    {
        X = 1LL, Y = 0;
        return;
    }

    GCD (B, A % B, X0, Y0);
    X = Y0;
    Y = X0 - Y0 * (A/B);
}

long long inversm(long long N)
{
    long long X, Y;

    GCD (N, M, X, Y);
    if (X<=0)
    {
        X = M + X % M;
    }
    return X;
}
long long comb(long long N, long long K)
{
    long long A, B, i;
	A = B = 1;
	for(i=K+1; i<=N; ++i)
        if (i % M) A = ((A % M) * (i % M)) % M;
	for(i=1; i<=N-K; ++i)
        if (i % M) B = ((B % M) * (i % M)) % M;

    A = ((A % M)* (inversm(B) % M)) % M;
	return A;
}

int main()
{
    f >> n >> k >> w;
    // C(n-(w-1)(k-1), k)
    g << comb(n - (k-1) * (w-1), k);
    return 0;
}
