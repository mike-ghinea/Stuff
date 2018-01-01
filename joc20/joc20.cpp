#include<fstream>
using namespace std;
ifstream cin("joc20.in");
ofstream cout("joc20.out");
int n,a[1001],b[1001],i,an[1001],tu[1001],s1,s2,nr1=1,nr2;
int main()
{
    cin>>n;
    nr2=n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(i=n+1;i<=2*n;i++)
    cin>>b[i-n];
    for(i=1;i<=n;i++)
    {
        if(b[i]==1)
        {
            if(i%2!=0)
            {an[i]=a[nr1];nr1++;}
            else
            {tu[i/2]=a[nr1];nr1++;}
        }
        else if(b[i]==2)
        {
            if(i%2!=0)
            {an[i]=a[nr2];nr2--;}
            else
            {tu[i/2]=a[nr2];nr2--;}
        }
    }
    for(i=1;i<=n;i++)
    s1=s1+an[i];
    for(i=1;i<=n;i++)
    s2=s2+tu[i];
    if(s1>s2)
    cout<<s1<<" 1";
    else if(s2>s1)
    cout<<s2<<" 2";
    else if(s1==s2)
    cout<<s1<<" 0";
    return 0;
}
