#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("copii.in");
ofstream cout("copii.out");
char a[11][11],viz[11][11];
int i,j,n,x[11],nr,sol;
int check()
{
    memset(viz,0,sizeof(viz));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(x[i]!=x[j] and !(a[i][j]-'1'))
                viz[x[i]][x[j]]=1;
    for(i=1;i<=nr;i++)
        for(j=1;j<=nr;j++)
            if(i!=j and !viz[i][j])
                return 0;
    return 1;
}
void back(int k)
{
    if(k==n+1)
    {
        sol+=check();
        return;
    }
    for(int i=1;i<=nr;i++)
    {
        x[k]=i;
        back(k+1);
    }
    x[k]=++nr;
    back(k+1);
    nr--;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i]+1;
    back(1);
    cout<<sol-1;
    return 0;
}
