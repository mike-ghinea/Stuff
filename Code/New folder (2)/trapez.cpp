#include<fstream>
#include<climits>
#include<algorithm>
#define Inf INT_MAX
using namespace std;
ifstream cin("trapez.in");
ofstream cout("trapez.out");
int n,x[1004],y[1004],nr=0,p=1,t,i,j;
double v[1000004],u=1;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(y[i]==y[j])
                v[++nr]=Inf;
            else
                v[++nr]=((x[j]-x[i])*u)/(y[j]-y[i]);
    sort(v+1,v+1+nr);
    for(i=2;i<=nr;i++)
        if(v[i]==v[i-1])
            p++;
        else
            t+=p*(p-1)/2,p=1;
    t+=p*(p-1)/2;
    cout<<t;
    return 0;
}
