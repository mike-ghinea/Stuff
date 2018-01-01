#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("plicuri.in");
ofstream cout("plicuri.out");
int k,p,mj,st,dr,n,i,x,t;
struct virgula
{
    int x,y;
}v[100001],a[100001];
int cmp(virgula a, virgula b)
{
    if(a.x<b.x)
        return 1;
    if(a.x==b.x&&a.y>b.y)
        return 1;
    return 0;
}
void bin(int st,int dr)
{
    while (st<=dr)
        {
            mj=(st+dr)/2;
            if(v[i].y<=a[mj].y)
            {
                p=mj;
                dr=mj-1;
            }
            else
                st=mj+1;
        }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i].x>>v[i].y;
        if(v[i].y<v[i].x)
        {
            t=v[i].x;
            v[i].x=v[i].y;
            v[i].y=t;
        }
    }
    sort(v+1,v+n+1,cmp);
    k=0;
    for(i=1;i<=n;i++)
    {
        st=1;
        dr=k;
        p=0;
        bin(st,dr);
        if(p!=0){
            a[p].y=v[i].y;
            a[p].x=v[i].x;
        }
        else
        {
            k++;
            a[k].y=v[i].y;
            a[k].x=v[i].x;
        }
    }
    cout<<k;
    return 0;
}
