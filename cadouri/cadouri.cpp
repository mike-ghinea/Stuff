#include<fstream>
using namespace std;
ifstream cin("cadouri.in");
ofstream cout("cadouri.out");
int i,F,B,N,b,f,c,cb,cf;
int main()
{
    cin>>F>>B>>N;
    for(i=1;i<=N;i++)
    {
       cin>>c;
       if(c%2==0)
       {cf++;cb=cb;}
       else
       {cb++;cf=cf;}
    }
    f=F-cf;
    if(F<=cf)
        f=0;
    b=B-cb;
    cout<<f<<"\n"<<b;
    return 0;
}
