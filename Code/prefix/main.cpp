#include <fstream>
#include <string.h>
#define dim 1000001

using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");
int t,i,j,ap[dim],k,n;
char s[dim];
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>s+1;
        n=strlen(s+1);
        k=0;
        for(j=2;j<=n;j++)
        {
            if(s[k+1]==s[j])
                k++;
            else
            {
                if(s[1]==s[j])
                    k=1;
                else
                    k=0;
            }
            ap[j]=k;
        }
        for(j=n;j>=1;j--)
        {
            if(ap[j])
                if(j%(j-ap[j])==0)
                    break;
        }
        fout<<j<<'\n';
    }
    return 0;
}
