#include<fstream>
using namespace std;
ifstream cin("mese.in");
ofstream cout("mese.out");
int n,m,a[251][251],Max,i,j,w,nrc,nrl,q,nr,d,s;
int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j]==1)
            {
                w=j;
                q=i;
                nrc=nrl=0;
                while(a[i][j]==1){
                    a[i][j]=0;
                    j++;
                    nrl++;
                    }
                a[i][w]=1;
                s=w;
                while(a[i][w]==1){
                    while(a[i][w]==1)
                    {
                        a[i][w]=0;
                        w++;
                    }
                    w=s;
                    i++;
                    nrc++;
                    }
                i=q;j=w;
                nr++;
                d=nrc*nrl;
                if(d>Max)
                    Max=d;

            }
    cout<<nr<<" "<<Max;
}
