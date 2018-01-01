#include <fstream>
using namespace std;
ifstream f("densitate.in");
ofstream g("densitate.out");

int n, i, p, j, nr,Q,a,b, v[500001];
bool prime[500001];

int main()
{f>>n>>Q;

    for (i=2; i<=n; i++)
    {
        if (prime[i] ==0)
        {
            for(j=i+i;j<=n;j=j+i)
               prime[j]=1;
        }
    }

for(i=2;i<=n;i++)
        v[i]=v[i-1]+1-prime[i];


for(j=1;j<=Q;j++)
{
    f>>a>>b;

    g<<v[b]-v[a-1]<<'\n';
    }


    return 0;
}

