#include <fstream>

using namespace std;
ifstream fin ("joctv.in");
ofstream fout ("joctv.out");
int bestsum,n,i,j,a[101][101],cont,sum;
int main()
{
    fin>>n;
    bestsum=-101;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fin>>a[i][j];

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];

    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            sum=0;
            for(cont=1;cont<=n;cont++)
            {
                if(sum<0)
                    sum=a[j][cont]-a[j][cont-1]-a[i-1][cont]+a[i-1][cont-1];
                else
                    sum+=a[j][cont]-a[j][cont-1]-a[i-1][cont]+a[i-1][cont-1];

                if(bestsum<sum)
                    bestsum=sum;
            }
        }
    }

    fout<<bestsum;
    return 0;
}
