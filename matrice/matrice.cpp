#include<fstream>
using namespace std;
ifstream cin("matrice.in");
ofstream cout("matrice.out");
int n,m,a[1002001],nr,Max=-1,i,j,k,x,o,y;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
        cin>>a[i];
    for(i=1;i<=n*m;i++)
        {
            o=i;
            y=0;x=0;k=0;
            if(a[o]==1)
            {
                while(a[o]==1)
                {
                    k=a[o];
                    a[o]=0;
                    o++;
                    x++;
                    a[o+m-2]=0;
                }
            }
            if(k==1)
            {
                a[o-1]=k;
                while(a[o-1]==1)
                {
                    a[o-1]=0;
                    o+=m;
                    y++;
                }
            }
            if(x!=0&&y!=0)
            {
                nr++;
                if(x*y>Max)
                Max=x*y;
            }
        }
    cout<<nr<<" "<<Max;
    return 0;
}
