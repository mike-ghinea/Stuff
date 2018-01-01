#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("grid.in");
ofstream cout("grid.out");
int n,k,a=1,v[4][10001],i,j,m,v2[10001],w;
int main()
{
    int x1,x2,y1,y2;
    cin>>n>>k;
    for(i=0;i<=n-1;i++)
        v[0][i]=a,a++;
    for(i=0;i<=n-1;i++)
        v[1][i]=a,a++;
    for(i=0;i<=n-1;i++)
        v[2][i]=a,a++;
    for(w=1;w<=k;w++)
    {
        cin>>x1>>y1>>x2>>y2;
        m=v[x1][y1];
        v[x1][y1]=0;
        i=0;
        memcpy(v2,v[x2],sizeof(v[x2]));
        while(v2[i]!=0)
        {
            v[x2][i+1]=v2[i];
           i++;
        }
        v[x2][y2]=m;
    }
    for(j=0;j<=3;j++){
        i=0;
        while(v[j][i]!=0){
            cout<<v[j][i]<<" ";
            i++;
        }
        cout<<"\n";
    }
}
