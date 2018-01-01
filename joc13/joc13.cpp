#include <fstream>
using namespace std;
ifstream cin("joc13.in");
ofstream cout("joc13.out");
int main()
{
    int n,k,i,j,j1,s,Max,a[2][5001],b[2][5001];
    cin>>n>>k;
    for(i=0;i<2;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    b[0][0]=a[0][0];
    b[1][0]=0;
    for(i=1;i<n;i++)
        for(j=0;j<2;j++)
        {
            Max=-11111;
            s=a[j][i];
            for(j1=1;j1<k and j1<=i;j1++)
            {
                s+=a[j][i-j1];
                Max=max(s+b[1-j][i-j1],Max);
            }
            b[j][i]=Max;
        }
    b[1][n-1]=max(b[0][n-1]+a[1][n-1],b[1][n-1]);
    cout<<b[1][n-1];
    return 0;
}

