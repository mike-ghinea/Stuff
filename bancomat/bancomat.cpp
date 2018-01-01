#include<fstream>
using namespace std;
ifstream cin("bancomat.in");
ofstream cout("bancomat.out");
struct dot{
    int x;int y;
}v[8];
int t,val,nr,x,ok=1,i,j,k;
int main()
{
    v[1].y=1;
    v[2].y=5;
    v[3].y=10;
    v[4].y=50;
    v[5].y=100;
    v[6].y=500;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        for(j=1;j<=6;j++)
            cin>>v[j].x;
        cin>>nr;
        for(j=1;j<=nr;j++)
        {
            cin>>x;
            for(k=6;k>=1&&v[k].x!=0;k--)
            {
                if(x%v[k].y==0)
                {
                    val=x/v[k].y;
                    if(val>v[k].x)
                    {
                        v[k].x-=val;
                        x%=v[k].y;
                    }
                    else
                    {
                        x%=v[k].y*v[k].x;
                        v[k].x=0;
                    }
                }
            }
            if(x!=0)
            {ok=0;break;}
        }
        if(ok==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
