#include<fstream>
using namespace std;
ifstream cin("concurs3.in");
ofstream cout("concurs3.out");
int n,i,x,H,ok,a,b;
int main()
{
    cin>>H>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(H/100==x/100)
        {
            if(H/10%10==x/10%10)
            {
                if(H%100==x%100)
                    ok=1;
                else
                {a=a+1;b=b+1;}
            }
            else
            {a=a+1;b=b;}
        }
        else
        {a=a;b=b;}

    }
    if(ok==1)
        cout<<"DA\n"<<a+1<<"\n"<<b+1;
    else
        cout<<"NU\n"<<a<<"\n"<<b;

    return 0;
}
