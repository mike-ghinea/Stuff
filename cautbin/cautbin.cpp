#include<fstream>
using namespace std;
ifstream cin("cautbin.in");
ofstream cout("cautbin.out");
int st,dr,mij,i,v[100001],n,m,p,x;
int cautbin(int x)
{
    st=1,dr=n;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(v[mij]<=x)
            st=mij+1;
        else
            dr=mij-1;
    }
    return dr;
}
void cautbin2(int x)
{
    st=1,dr=n;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(v[mij]>=x)
            dr=mij-1;
        else
            st=mij+1;
    }
    cout<<st<<"\n";
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>p>>x;
        if(p==0)
        {
            if(v[cautbin(x)]==x)
                cout<<dr<<"\n";
            else
                cout<<-1<<"\n";
        }
        else if(p==1)
            cout<<cautbin(x)<<"\n";
        else
            cautbin2(x);
    }
    return 0;
}
