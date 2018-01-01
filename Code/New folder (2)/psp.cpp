#include<fstream>
using namespace std;
ifstream cin("psp.in");
ofstream cout("psp.out");
int n,i,x,m,mf,nr,m4;//m=memorie
int main()
{
    cin>>n>>m;
    nr=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        mf=mf+x;
        if(mf>m)
        {nr=nr;mf=mf-x;}
        else
        {nr=nr+1;mf=mf;}
    }
    cout<<nr<<" "<<m-mf;
    return 0;
}
