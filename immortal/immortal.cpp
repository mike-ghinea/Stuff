#include<fstream>
#define NMAX 25
using namespace std;
ifstream cin("immortal.in");
ofstream cout("immortal.out");
struct poz{int x,y;}LST[NMAX*NMAX];
struct sol{struct poz srt,fin;}SOL[NMAX*NMAX];
bool ok;
int N,I,M,POZ[NMAX][NMAX];
bool dead[NMAX];
int dx[]={-1, 0, 1,  0};
int dy[]={ 0, 1, 0, -1};
inline void print()
{
    for(int i=0;i<I-1;++i)
    {
        cout<<SOL[i].srt.x-1<<" ";
        cout<<SOL[i].srt.y-1<<" ";
        cout<<SOL[i].fin.x-1<<" ";
        cout<<SOL[i].fin.y-1<<"\n";
    }
}
void _back(int NRL)
{
    int x,y,deaded,i,d;
    if(!ok)
    {
        if(NRL==I-1)
        {
            ok=1;
            print();
        }
        else
            for(i=1;i<=I;++i)
                if(!dead[i])
                {
                    x=LST[i].x;
                    y=LST[i].y;
                    for(d=0;d<4;++d)
                    {
                        if(POZ[x+dx[d]][y+dy[d]]>0 and POZ[x+2*dx[d]][y+2*dy[d]]==0)
                        {
                            deaded=POZ[x+dx[d]][y+dy[d]];
                            SOL[NRL].fin.x=x+2*dx[d];
                            SOL[NRL].fin.y=y+2*dy[d];
                            SOL[NRL].srt.x=x;
                            SOL[NRL].srt.y=y;
                            LST[i].x=x+2*dx[d];
                            LST[i].y=y+2*dy[d];
                            POZ[x][y]=0;
                            POZ[x+2*dx[d]][y+2*dy[d]]=i;
                            dead[POZ[x+dx[d]][y+dy[d]]]=1;
                            POZ[x+dx[d]][y+dy[d]]=0;

                            _back(NRL+1);

                            LST[i].x=x;
                            LST[i].y=y;
                            POZ[x][y]=i;
                            POZ[x+2*dx[d]][y+2*dy[d]]=0;
                            POZ[x+dx[d]][y+dy[d]]=deaded;
                            dead[POZ[x+dx[d]][y+dy[d]]]=0;
                        }
                    }
                }
    }
}
int main()
{
    cin>>N>>M>>I;
    for(int i=1;i<=I;++i)
    {
        int x,y;
        cin>>x>>y;
        POZ[x+1][y+1]=i;
    }
    int k=0;
    for(int i=2;i<=N+1;++i)
        for(int j=2;j<=M+1;++j)
            if(POZ[i][j])
            {
                LST[++k].x=i;
                LST[k].y=j;
                POZ[i][j]=k;
            }
    for(int i=0;i<N+4;i++)
        POZ[i][0]=POZ[i][1]=POZ[i][M+3]=POZ[i][M+2]=-1;
    for(int i=0;i<M+4;i++)
        POZ[0][i]=POZ[1][i]=POZ[N+2][i]=POZ[N+3][i]=-1;
    _back(0);
    return 0;
}
