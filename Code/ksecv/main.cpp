#include <fstream>
#define dim 100001
using namespace std;
ifstream fin("ksecv.in");
ofstream fout("ksecv.out");
int n,k,v[dim],j,i,dr,Min,bst[2][dim];
struct strct
{
   int poz,val;
} stv[dim];
int max1(long long a, int b)
{

    if(a>b)
        return a;
    return b;
}
int main()
{
   fin>>n>>k;
   for(i=1;i<=n;i++)
   {
      fin>>v[i];
      bst[1][i]=max(v[i],bst[1][i-1]);
   }
   for(i=2;i<=k;i++)
   {
      stv[1].poz=i;
      stv[1].val=min(bst[1-i%2][i],bst[1-i%2][i-1]);
      dr=1;
      bst[i%2][i]=v[i]+bst[1-i%2][i-1];
      for(j=i+1;j<=n;j++)
      {
         Min=bst[1-i%2][stv[dr].poz];
         while(dr>=1&&v[j]>v[stv[dr].poz])
         {
            Min=min(Min,stv[dr].val);
            dr--;
         }
         if(dr==0)
            bst[i%2][j]=Min+v[j];
         else
            bst[i%2][j]=min(bst[i%2][stv[dr].poz],Min+v[j]);
         stv[++dr].poz=j;
         stv[dr].val=Min;
      }
   }
   fout<<bst[1-i%2][n];
    return 0;
}
