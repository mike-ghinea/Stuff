#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("cautbin.in");
ofstream cout("cautbin.out");
int v[100001],n,i,j,st,dr,mij,x;
int main()
{
 	cin>>n;
 	for(i=1;i<=n;i++)
    cin>>v[i];
    cin>>x;
    sort(v+1,v+n+1);
    for(j=1;j<=n;j++)
        cout<<v[j]<<"\n";
        st=n;
        dr=1;
        mij=(st+dr)/2;
       while(1)
       {
           if(v[mij]>x)
            st=mij;
           else if(v[mij]<x)
            dr=mij;
           else if(v[mij]==x)
            break;
           mij=(st+dr)/2;
       }
       cout<<mij;


	return 0;
}
