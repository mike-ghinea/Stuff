#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int m,n,a[1024],b[1024],ab[1024][1024],sir[1024],Max,i,j;
int main(){
    cin>>m>>n;
    for(i=1;i<=m;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(a[i]==b[j])
            ab[i][j]=1+ab[i-1][j-1];
        else
            ab[i][j]=max(ab[i-1][j],ab[i][j-1]);
    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++Max] = a[i], --i, --j;
        else if (ab[i-1][j] < ab[i][j-1])
            --j;
        else
            --i;
    cout<<Max<<"\n";
    for(i=Max;i;i--)
        cout<<sir[i]<<" ";
}

