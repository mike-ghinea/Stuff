#include<fstream>
#include<queue>
#include<climits>
#include<cmath>
#define DIM 53
#define INF 1.0*INT_MAX
#define ERR 0.00001
using namespace std;
ifstream cin("excursie.in");
ofstream cout("excursie.out");
double cost[DIM][DIM],path[DIM][DIM];
int matrix[DIM][DIM],N,M,Lmax,li,lf,ci,cf,i,j;
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};
queue <double> Q[2];
queue <double> Path[2];
double distance(int x,int y)
{
    double D=sqrt((x-y)*(x-y)+1);
    return D;
}
int tan(int x,int y)
{
    return sqrt((x-y)*(x-y));
}
int main()
{
    cin>>N>>M;
    cin>>Lmax;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            {
                cin>>matrix[i][j];
                cost[i][j]=path[i][j]=INF;
            }
    }
    cin>>li>>ci>>lf>>cf;
    for(i=0;i<=M+1;i++)
        matrix[0][i]=matrix[N+1][i]=-1;
    for(i=0;i<=N+1;i++)
        matrix[i][0]=matrix[i][M+1]=-1;
    Q[0].push(li);
    Q[1].push(ci);
    cost[li][ci]=path[li][ci]=0;
    while(!Q[0].empty())
    {
        int x,y;
        x=Q[0].front();
        Q[0].pop();
        y=Q[1].front();
        Q[1].pop();
        for(i=0;i<4;i++)
        {
            int l,c;
            l=x+dx[i];
            c=y+dy[i];
            double DIST,EF;
            DIST=distance(matrix[x][y],matrix[l][c])
            if(matrix[l][c]==matrix[x][y])
                EF=1;
            else if(matrix[l][c]<matrix[x][y])
                EF=(DIST*tan(matrix[x][y],matrix[l][c]))/2;
            else
                EF=(DIST*tan(matrix[x][y],matrix[l][c]));
        }
    }
}
