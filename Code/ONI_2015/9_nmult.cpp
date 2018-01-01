// student Alexandru Murtaza - Universitatea Bucuresti

#include <fstream>

using namespace std;

const char InFile[] = "nmult.in";
const char OutFile[] = "nmult.out";
const int MOD = 666013;

ifstream fin(InFile);
ofstream fout(OutFile);

int N, K, W;

inline int mypow(int A, int B)
{
	int ans=1;
	for (; B; B >>= 1)
	{
		if (B & 1)
		{
			ans = (1LL*ans*A)%MOD;
		}
		A = (1LL*A*A) % MOD;
	}
	return ans;
}

inline int invmod(int A)
{
	return mypow(A,MOD-2);
}

int main()
{
	fin >> N >> K >> W;
	fin.close();


	long long CN = N - (W-1)*(K-1);
	int CK = K;


	if (CN < CK )
	{
		fout << "0\n";
		fout.close();
		return 0;
	}

	int st = 1;
	int dr = CN;
	int other = CK;
	if (CK < CN - CK)
	{
		st = CN - CK + 1;
		other = CK;
	}
	else
	{
		st = CK + 1;
		other = CN - CK;
	}

	int sol = 1;
	for (int i = st; i <= dr; ++i)
	{
		sol = (1LL * sol*i) % MOD;
	}

	int other_p = 1;
	for (int i = 1; i <= other; ++i)
	{
		other_p = (1LL * other_p*i) % MOD;
	}

	sol = (1LL * sol*invmod(other_p)) % MOD;

	fout << sol << "\n";
	fout.close();
	return 0;
}
