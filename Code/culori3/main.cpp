#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("culori3.in");
ofstream fout("culori3.out");
int cod[2][6],a[6][2][1501],s[1501],i,j,n;
void aduna( int a[], int b[], int c[])
{
    int t=0,i;

    for(i=1; i<=a[0]||i<=b[0]; i++)
    {
        t=a[i]+b[i]+t;
        c[i]=t%10;
        t=t/10;

    }
    c[0]=i-1;
    if(t>0)
    {
        c[i]=t;
        c[0]++;
    }
}
int main()
{
    fin>>n;
    cod[0][1]=2;
    cod[0][2]=1;
    cod[1][2]=3;
    cod[0][3]=2;
    cod[1][3]=4;
    cod[0][4]=3;
    cod[1][4]=5;
    cod[0][5]=4;
    for(i=1; i<=5; i++)
        a[i][1][0]=a[i][0][0]=1;
    for(i=1; i<=5; i++)
        a[i][1][1]=1;

    for(i=2; i<=n; i++)
    {
        for(j=1; j<=5; j++)
        {

            aduna(a[cod[0][j]][1-i%2],a[cod[1][j]][1-i%2],a[j][i%2]);


        }

    }
    for(i=1; i<=5; i++)
    {
        aduna(s,a[i][n%2],s);
    }
    for(i=s[0]; i>=1; i--)
        fout<<s[i];
    return 0;
}
