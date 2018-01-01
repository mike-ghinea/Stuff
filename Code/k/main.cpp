#include <fstream>
#define nMax 1000005
using namespace std;
ifstream fin("kbubblesort.in");
ofstream fout("kbubblesort.out");
int v[nMax], k, n, i, ok;

int main()
{
    fin>>n>>k;
    for(i=1;i<=n;i++)
        fin>>v[i];
    ok=1;
    while(ok&&k)
    {
        ok=0;
        for(i=1;i<n&&k;i++)
            if(v[i]>v[i+1])
            {
                swap(v[i], v[i+1]);
                ok=1;
                k--;
            }
    }
    for(i=1;i<=n;i++)
        fout<<v[i]<<" ";
    return 0;
}
