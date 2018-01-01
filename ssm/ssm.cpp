#include<fstream>
#include<limits.h>
using namespace std;
ifstream cin("ssm.in");
ofstream cout("ssm.out");
int n,i,x,S,Smax=INT_MIN,li,limax,lf,lfmax;
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
                S=S+x;
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
            S=x;
            li=i;
            lf=i;
            if(Smax<S)
                {
                    Smax=S;
                    limax=li;
                    lfmax=lf;
                }
        }
    }
    cout<<Smax<<" "<<limax<<" "<<lfmax;
}
