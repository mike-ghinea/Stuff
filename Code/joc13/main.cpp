#include <fstream>
#define dim 5001
using namespace std;
ifstream fin ("joc13.in");
ofstream fout("joc13.out");
int n,k,i,j,j1,Max,s,v[2][dim],bst[2][dim];
int main()
{
    fin>>n>>k;
    for(i=0;i<2;i++)
        for(j=0;j<n;j++)
            fin>>v[i][j];
    bst[0][0]=v[0][0];
    bst[1][0]=0;
    for(j=1;j<n;j++)
    {
        for(i=0;i<=1;i++)
        {
            Max=-11111;
            s=v[i][j];
            for(j1=1;j1<k&&j1<=j;j1++)
            {
                s+=v[i][j-j1];
                Max=max(Max,bst[1-i][j-j1]+s);
            }
            bst[i][j]=Max;
        }
    }
bst[1][n-1]=max(bst[1][n-1],bst[0][n-1]+v[1][n-1]);

fout<<bst[1][n-1];
    return 0;
}
