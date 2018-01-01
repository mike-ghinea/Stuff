#include <fstream>
#include <string>
#include <vector>
using namespace std;
ifstream cin("robots.in");
ofstream cout("robots.out");
int dx[]={1,0},dy[]={0,1},p,u,x,y,l,c;
int matrix[32][32];
int width,height,i,j;
char line;
int q[2][1000];
bool v[31][31];
int main()
{
    cin>>width>>height;
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
        {
            cin>>line;
            if(line=='0')
                matrix[i][j]=1;
        }
    for(i=0;i<=width;i++)
        matrix[height][i]=-1;
    for(i=0;i<=height;i++)
        matrix[i][width]=-1;
//    for(i=0;i<=width;i++)
//    {
//        for(j=0;j<=height;j++)
//            cout<<matrix[i][j]<<" ";
//    cout<<"\n";
//    }
    p=u=0;
    q[0][p]=0;
    q[1][p]=0;
    v[0][0]=1;
    while(p<=u)
    {
        x=q[0][p];
        y=q[1][p];
        cout<<x<<" "<<y<<" ";
        for(i=0;i<2;i++)
        {
            l=q[0][p]+dx[i];
            c=q[1][p]+dy[i];
            if(v[l][c]==0 and matrix[l][c]==1)
            {
                cout<<l<<" "<<c<<" ";
                u++;
                q[0][u]=l;
                q[1][u]=c;
                v[l][c]=1;
            }
            else if(matrix[l][c]==0)
                cout<<"-1 -1 ";
        }
        cout<<"\n";
        p++;
    }
}
