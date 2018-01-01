#include <fstream>
#include<math.h>
#include<algorithm>
using namespace std;
ifstream fin("mere.in");
ofstream fout("mere.out");
long long n,k,i,t;
int main()
{
fin>>t;
for(i=1;i<=t;i++)
{
    fin>>n>>k;

    if(n-k<0)
    {
        fout<<"Remiza \n";
    }
    else
    {
        if(n-k<k)
        {
            fout<<"Santa Klaus \n";
        }
        else
        {
            if(n-k==k)
            {
                fout<<"Remiza \n";
            }
            else
            {
                if(n%k==0)
                {
                    if(n/k%2==1)
                        fout<<"Remiza \n";
                    else
                        fout<<"Santa Klaus \n";
                }
                else
                    fout<<"Santa Klaus \n";
            }
        }
    }
}
    return 0;
}
