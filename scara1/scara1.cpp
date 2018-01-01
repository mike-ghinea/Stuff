#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("scara1.in");
ofstream cout("scara1.out");
double best[9],sum[9],Min=1000;
int p,m,h,n,x[9],sol[9],s;
bool viz[9];
void tipar()
{
    int i,j;
    memset(best,0,sizeof(best));
    for(i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+x[i];
        best[i]=best[i-1]+x[i];
        for(j=i-2;j>=0;j--)
            if(sum[i]-sum[j]<=m)
                best[i]=min(best[i],best[j]+1.0*(sum[i]-sum[j])/(i-j)+p);
    }
    if(Min-best[n]>0.001)
    {
        Min=best[n];
        memcpy(sol,x,sizeof(sol));
    }
}
void back(int k)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(viz[i]==0)
        {
            x[k]=i;
            viz[i]=1;
            s+=i;
                if(k==n)
                {
                    if(s==h)
                        tipar();
                }
                else
                    back(k+1);
            viz[i]=0;
            s-=x[k];
        }
    }
}
int main()
{
    int i;
    cin>>h>>n>>m>>p;
    back(1);
    cout<<Min<<'\n';
    for(i=1;i<=n;i++)
        cout<<sol[i]<<" ";
    return 0;
}
