#include <fstream>


#define MOD 10000
#define DIM 200000
using namespace std;
ifstream fin ("diamant.in");
ofstream fout ("diamant.out");
int i,j,val,n,m,x,A[DIM],D[DIM],st,dr,k;
#define D (D+100000)
#define A (A+100000)
int main()
{
   fin>>n>>m>>x;
   A[0]=1;

   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           val=i*j;
           for(k=st;k<=dr;k++)
           {
               D[k-val]+=A[k];
               D[k]+=A[k];
               D[k+val]+=A[k];
           }
           st-=val;
           dr+=val;
           for(k=st;k<=dr;k++)
           {
               A[k]=D[k]%MOD;
               D[k]=0;
           }
       }
   }
   if(x<st || x>dr)
   {
       fout<<0;
       return 0;
   }
    fout<<A[x];
    return 0;
}
