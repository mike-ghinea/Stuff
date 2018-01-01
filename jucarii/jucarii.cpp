#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("jucarii.in");
ofstream cout("jucarii.out");
int x[15],n,viz[15],w,nr,q,OK=0;
int scmax(int a[],int n)
{
    int best[15],Max,poz[15],i,p,j;
    memset(best,0,sizeof(best));
    memset(poz,0,sizeof(poz));
    best[n]=1;
    poz[n]=-1;
    Max=1;
    p=n;
    for(i=n-1;i>=1;--i)
    {
        best[i]=1;
        poz[i]=-1;
        for(j=i+1;j<=n;++j)
        {
            if(a[i]<a[j]&&best[i]<best[j]+1)
            {
                best[i]=best[j]+1;
                poz[i]=j;
                if (best[i]>Max)
                {
                    Max=best[i];
                    p=i;
                }
            }
        }
    }
    if(Max>=w)
        {
            nr++;
            return 1;
        }
    else
        return 0;
}
void tipar(int k)
{
    for(int i=1;i<=k;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<"\n";
   viz[x[n]]=0;
}
void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!(viz[i]))
        {
            x[k]=i;
            viz[i]=1;
            if(k==n)
                {
                    if(scmax(x,n+1) and nr==q)
                    {
                        tipar(k);
                        OK=1;
                        break;
                    }
                }
            else
                back(k+1);
            viz[i]=0;
            if(OK)
                break;
        }
}
int main()
{
    cin>>n>>w>>q;
    back(1);
    return 0;
}
