#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("tastatura.in");
ofstream cout("tastatura.out");
int i,n,j,k[10001];
char x[1001],m[10001][51];
int main()
{
    cin>>(x+1);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>(m[i]+1);
        k[i]=strlen(m[i]+1);
    }
    for(i=1;i<=2;i++)
    {
        for(j=1;j<=2;j++)
            cout<<m[i][j];
        cout<<"\n";
    }

}
