#include<fstream>
using namespace std;
ifstream cin("culori3.in");
ofstream cout("culori3.out");
unsigned long long a[1001][6],n,s,i;
int main()
{
    cin>>n;
    a[1][1]=a[1][2]=a[1][3]=a[1][4]=a[1][5]=1;
    for(i=2;i<=n;i++)
    {
        a[i][1]=a[i-1][2];
        a[i][2]=a[i-1][1]+a[i-1][3];
        a[i][3]=a[i-1][2]+a[i-1][4];
        a[i][4]=a[i-1][3]+a[i-1][5];
        a[i][5]=a[i-1][4];
    }
    for(i=1;i<=5;i++)
        s+=a[n][i];
    cout<<s;
}
