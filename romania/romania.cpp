#include<fstream>
#include<vector>
#define DIM 100001
using namespace std;
ifstream cin("romania.in");
ofstream cout("romania.out");
int N,K,x,i,j,k,l[DIM];
bool v[DIM],ok=0,m[1501][1501];
int main()
{
    cin>>N>>K;
    for(i=1;i<=K;i++)
    {
        cin>>l[i];
        v[l[i]]=1;
    }
    for(i=1;i<=K;i++)
    {
        if(l[i]!=N)
        {
            for(j=1;j<=N-1;j++)
            {
                if(v[j-1]==0 and l[i]!=j and max(l[i],j)-min(l[i],j)>=2 and m[l[i]][j]==0)
                {
                    cout<<l[i]<<" "<<j<<"\n";
                    m[l[i]][j]=m[j][l[i]]=1;
                    ok=1;
                    break;
                }
            }
        }
        else
        {
            if(m[N][N-2]==0 and m[N-2][N]==0 and v[i-1]==0)
            {
                cout<<N<<" "<<N-2<<"\n";
                ok=1;
            }
//            for(j=2;j<=N-1;j++)
//            {
//                if(v[j-1]==0 and l[i]!=j and max(l[i],j)-min(l[i],j)>=2 and m[l[i]][j]==0)
//                {
//                    cout<<l[i]<<" "<<j<<"\n";
//                    m[l[i]][j]=m[j][l[i]]=1;
//                    ok=1;
//                    break;
//                }
//            }
        }
        if(ok==0)
        {
            cout<<"-1\n";
            ok=1;
        }
        ok=0;
    }
}
