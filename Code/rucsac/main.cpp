#include <fstream>
#include <limits.h>

#define inf 2000000
using namespace std;
ifstream fin ("pusculita.in");
ofstream fout ("pusculita.out");
int n,g,a,b,Max,v[100001],i,j;
int main()
{
    fin>>g>>n;
    for(i=1;i<=g;i++)
    {
        v[i]=inf;
    }
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;

        for(j=0;j<=g-a;j++)
        {
            v[j+a]=min(v[j]+b,v[j+a]);
        }
    }


    fout<<v[g];
    return 0;
}
