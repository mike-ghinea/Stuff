#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("teams.in");
ofstream cout("teams.out");
int a,b,n,i,nr,v[100001],st,dr,mij,jb,ja;
int main()
{
    cin>>n>>a>>b;
    for(i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=2;i<=n;i++)
    {
        st=1;dr=i-1;ja=1;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(v[i]+v[mij]<a)
                st=mij+1;
            else
            {
                if(v[i]+v[mij]<=b)
                ja=mij;
                dr=mij-1;
            }
        }
        st=1;dr=i-1;jb=-1;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(v[i]+v[mij]>b)
                dr=mij-1;
            else
            {
                if(v[i]+v[mij]>=a)
                jb=mij;
                st=mij+1;
            }
        }
        if(jb!=-1)
            nr+=jb-ja+1;
    }
    cout<<nr;
}
