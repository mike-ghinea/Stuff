#include<fstream>
#include<algorithm>
#define x first
#define y second
#define N 100005
#define foreach(i,n,v) for(int i=v;i<=n;i++)
using namespace std;
ifstream cin("dreapta.in");
ofstream cout("dreapta.out");
pair <double,double> v[N],q[N],in[N];
int n,m,st,dr,k,semn1,semn2,mid;
double a1,a2,b1,b2,c1,c2;
int semn(double a,double b,double c, double x,double y)
{
    double r=a*x+b*y+c;
    if(r<0)
        return -1;
    if(r>0)
        return 1;
    return 0;
}
int main()
{
    cin>>n;
    foreach(i,n,1)
        cin>>v[i].x>>v[i].y;
    cin>>m;
    foreach(i,m,1)
        cin>>q[i].x>>q[i].y;
    a1=q[2].y-q[1].y;
    b1=q[1].x-q[2].x;
    c1=q[2].x*q[1].y-q[1].x*q[2].y;
    foreach(i,n,2)
    {
        semn1=semn(a1,b1,c1,v[i-1].x,v[i-1].y);
        semn2=semn(a1,b1,c1,v[i].x,v[i].y);
        if(semn1*semn2==-1)
        {
            a2=v[i].y-v[i-1].y;
            b2=v[i-1].x-v[i].x;
            c2=v[i].x*v[i-1].y-v[i-1].x*v[i].y;
            k++;
            in[k].y=(a2*c1-a1*c2)/(a1*b2-a2*b1);
            in[k].x=(-c1-b1*in[k].y)/a1;
        }
    }
    sort(in+1,in+k+1);
    foreach(i,m,1)
    {
        st=1;
        dr=k;
        while(st<=dr)
        {
            mid=(st+dr)/2;
            if(q[i].x>in[mid].x)
                st=mid+1;
            else
                dr=mid-1;
        }
        if(dr%2==1)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }
}

