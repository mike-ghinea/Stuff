#include <fstream>
using namespace std;
ifstream cin("aib.in");
ofstream cout("aib.out");
int arbbin[100001],n,p,m;
void up(int val,int x)
{
    for(int i=x;i<=n;i+=i&(-i))
        arbbin[i]+=val;
}
int query(int x)
{
    int sol=0;
    for(int i=x;i>0;i-=i&(-i))
        sol+=arbbin[i];
    return sol;
}
int cautbin(int val)
{
    int st,dr,mij,x;
    st=1;
    dr=n;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        x=query(mij);
        if(x==val)
            return mij;
        else if(x>val)
            dr=mij-1;
        else
            st=mij+1;
    }
    return -1;
}
int main()
{
    int i,x,a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        up(x,i);
    }
    for(i=1;i<=m;i++)
    {
        cin>>p;
        if(p==0)
        {
            cin>>a>>b;
            up(b,a);
        }
        if(p==1)
        {
            cin>>a>>b;
            cout<<query(b)-query(a-1)<<'\n';
        }
        if(p==2)
        {
            cin>>a;
            cout<<cautbin(a)<<'\n';
        }
    }
    return 0;
}

