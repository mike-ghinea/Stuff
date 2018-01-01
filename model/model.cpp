#include<fstream>
using namespace std;
ifstream cin("ssm.in");
ofstream cout("ssm.out");
int n,i,li,lf,limax,lfmax,S,Smax=-999999999,x;
int main()
{
    cin>>n>>x;
    S=x;
    li=1;
    lf=1;
    for(i=2;i<=n;i++)
    {
        cin>>x;
        if(S+x>=x)
        {
            S+=x;
            lf++;
            if(Smax<S)
            {
                Smax=S;
                limax=li;
                lfmax=lf;
            }
        }
        else
        {
            li=lf=i;
            S=x;
            if(Smax<S)
            {
                Smax=S;
                limax=li;
                lfmax=lf;
            }
        }
    }
    cout<<Smax<<" "<<limax<<" "<<lfmax;
    return 0;
}
