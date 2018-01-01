#include<fstream>
#include<climits>
#define M 101
#define INF 1006666666L
using namespace std;
ifstream cin("coach.in");
ofstream cout("coach.out");
int m,n,mc[M][M],i,j,t,c,val[M],num[M],renum[M],x,y,k,s;
long long a[M][M],T;
int main()
{
    cin>>n>>m>>T;
    for(i=1;i<=n;i++)
    {
        cin>>val[i];
        renum[i]=num[i]=i;
    }
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(val[i]>val[j])
            {
                renum[num[i]]=j;
                renum[num[j]]=i;
                swap(val[i],val[j]);
                swap(num[i],num[j]);
            }
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        mc[renum[x]][renum[y]]=mc[renum[y]][renum[x]]=c;
    }
    for(s=1;s<n;s++)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(mc[i][j]!=0 and i>=s and j>=s)
                    a[i][j]=mc[i][j];
                else
                    a[i][j]=INF;
        for(k=s;k<=n;k++)
        {
            for(i=s;i<=n;i++)
                if(a[i][k]!=INF)
                    for(j=s;j<=n;j++)
                        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            for(i=s;i<=k;i++)
                for(j=s;j<=k;j++)
                    if(a[i][j]==T)
                        {
                            cout<<num[i]<<" "<<num[j]<<" "<<val[s]<<" "<<val[k];
                            return 0;
                        }
        }
    }
}
