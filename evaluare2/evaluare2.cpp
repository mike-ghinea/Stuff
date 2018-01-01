#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std ;
ifstream cin("expresie2.in");
ofstream cout("expresie2.out");
char s[100002] ;
int n,k,v,st[100001];
int ssm()
{
    int maxim, suma;
    maxim=st[k] ;
    suma=0;
    if(st[k]>0)
        suma=st[k];
    k-- ;
    while (st[k]!= 1000)
    {
        suma+=st[k] ;
        if (suma > maxim)
            maxim=suma;
        if (suma < 0)
            suma=0 ;
        k-- ;
    }
    return maxim ;
}
int ssort()
{
    int i, nr;
    i=k;
    while (st[i]!=2000)
        i-- ;
    sort(st+i+1,st+k+1) ;
    nr=(k+i+1)/2 ;
    k=i ;
    return st[nr];
}
int main()
{
    int i,semn,x ;
    cin>>s;
    n=strlen(s) ;
    k=-1;
    i=0;
    while(i<n)
    {
        if (s[i]=='(')
        {
            st[++k]=1000;
            i++;
        }
        else if (s[i]=='[')
        {
            st[++k]=2000 ;
            i++ ;
        }
        else if (s[i]==')')
        {
            x=ssm();
            st[k]=x;
            i++;
        }
        else if (s[i]==']')
        {

            x=ssort();
            st[k]=x;
            i++;
        }
        else if (s[i]!= ',')
        {
            semn=1;
            if(s[i]=='-')
            {
                semn=-1;
                i++;
            }
            x=0 ;
            while (i<n and '0'<=s[i] and s[i]<='9')
            {
                x=x*10 + (s[i]-'0');
                i++ ;
            }
            x*=semn;
            st[++k]=x ;
        }
        else
        {
            i++;
            v++;
        }
    }
    int suma=0;
    for (i=0;i<=k;i++)
        suma+=st[i];
    cout<<v+1<<"\n";
    cout<<suma<<"\n";
    return 0;
}
