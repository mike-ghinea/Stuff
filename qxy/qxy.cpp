#include<fstream>
#include<cstring>
#include<vector>
using namespace std;
ifstream cin("qxy.in");
ofstream cout("qxy.out");
short int N,i,q,j;
int Q;
vector<short int>v;
vector<short int>M[1001];
int main()
{
    cin>>N;
    v.push_back(0);
    for(i=1;i<=N;i++)
    {
        cin>>q;
        v.push_back(q);
    }
    for(i=0;i<=1000;i++)
        for(j=1;j<=N+1;j++)
            M[i].push_back(0);
    for(i=0;i<=1000;i++)
    {
        for(j=1;j<=N;j++)
        {
            M[i][j]=M[i][j-1];
            if(v[j]>=i)
                M[i][j]+=1;
        }
    }
    cin>>Q;
    for(q=1;q<=Q;q++)
    {
        int i,j,x,y;
        cin>>i>>j>>x>>y;
        cout<<M[x][j]-M[y+1][j]+M[y+1][i-1]-M[x+1][i-1]<<"\n";
    }
}
