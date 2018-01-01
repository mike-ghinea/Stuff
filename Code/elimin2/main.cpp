#include <fstream>
#include <string.h>

#define DIM 2002
using namespace std;
ifstream fin("elimin2.in");
ofstream fout("elimin2.out");
int i,j,pas,v[DIM],n,p,u;
short int bst[DIM][DIM],st[DIM][11],dr[DIM][11],sol;
char s[DIM+1];
void write(int p, int u, int x)
{
    if(x<=0)
        return;
    for(int i=9;i>=0;i--)
    {
        if(bst[dr[p][i]][st[u][i]]==x)
        {
            fout<<i;
            write(dr[p][i]+1,st[u][i]-1,x-2);
            if(x>1)
                fout<<i;
            return;
        }
    }
}
int main()
{
    fin>>(s+1);
    n=strlen(s+1);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=9;j++)
        {
            st[i][j]=st[i-1][j];
        }
        st[i][s[i]-'0']=i;
    }
    for(i=n;i>=1;i--)
    {
        for(j=0;j<=9;j++)
        {
            dr[i][j]=dr[i+1][j];
        }
        dr[i][s[i]-'0']=i;
    }
    for(i=1;i<=n;i++)
    {
        bst[i][i]=1;
    }
    for(pas=1;pas<n;pas++)
    {
        for(i=1;i<=n-pas;i++)
        {
            j=i+pas;
            if(s[j]==s[i])
            {
                bst[i][j]=bst[i+1][j-1]+2;
            }
            else
            {
                bst[i][j]=max(bst[i+1][j],bst[i][j-1]);
            }

        }
    }
    for(i=1;i<=9;i++)
    {
        sol=max(sol,bst[dr[1][i]][st[n][i]]);
    }
    write(1,n,sol);
    return 0;
}
