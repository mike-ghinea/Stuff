#include<fstream>
using namespace std;
ifstream cin("meteo.in");
ofstream cout("meteo.out");
int i,x,n,p,nr,mn,np,j,aux,sn,sp,k;
int main()
{
    cin>>n>>p>>nr;
    int x[nr],min[n],max[p];
    for(i=1;i<=nr;i++)
    {
        cin>>x[i]; //am terminat citirea
        aux=x[i];
        for(j=1;j<=n;j++)
        {
            if (aux<min[j])
            min[j]=aux;
        }
        aux=x[i];
        for(k=1;k<=p;k++)
        {
            if (aux>max[k] && aux!=max[k])
            max[k]=aux;
        }
    }
   for(j=1;j<=n;j++)
    sn=sn+min[j];
    np=sn/n;
   for(k=1;k<=p;k++)
   sp=sp+max[k];
   mn=sp/p;
   cout<<np<<" "<<mn;
   return 0;
}
