#include<fstream>
using namespace std;
ifstream cin("paint.in");
ofstream cout("paint.out");
bool v[101];
int a,b,c,d,i,s=0;
int main()
{
    cin>>a>>b;
    for(i=a;i<b;i++)
        if(v[i]==0)
            v[i]=1;
    cin>>c>>d;
    for(i=c;i<d;i++)
        if(v[i]==0)
            v[i]=1;
    int k=max(b,d);
    int i=min(a,c);
    for(;i<=k;i++)
        s+=v[i];
    cout<<s;
}
