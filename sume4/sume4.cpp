#include<fstream>
using namespace std;
ifstream cin("sume4.in");
ofstream cout("sume4.out");
int x,i,n,na,nm,q,a,m;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        na=x/1000;
        nm=x%100;
        q=x/100%10;
        if(na<nm)
        {a=a+na+q;
         m=m+nm;}
        else if(na>nm)
        {a=a+na;
         m=m+nm+q;}
        else if(na==nm)
         {a=a+na;m=m+nm;}
    }
    cout<<a<<" "<<m;
    return 0;
}
