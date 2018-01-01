#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("cifra.in");
ofstream cout("cifra.out");
char n[101];
int T,i,v[101];
int pow(int n)
{
    int p=n,sol=1;
    while(p!=0)
    {
        if(p%2==1)
            sol=(n*sol)%10;
        n=(n*n)%10;
        p/=2;
    }
    return sol;
}
int main()
{
    for(i=1;i<=100;i++)
        v[i]=(v[i-1]+pow(i))%10;
    cin>>T;
    while(T--)
    {
        cin>>(n+1);
        int s=strlen(n+1);
        if(s==1)
            cout<<v[n[s]-'0']<<"\n";
        else
            cout<<v[n[s]-'0'+(n[s-1]-'0')*10]<<"\n";
    }
    return 0;
}
