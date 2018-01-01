#include <fstream>
#include <string.h>

#define Ndim 256
using namespace std;
ifstream fin("matrice3.in");
ofstream fout("matrice3.out");
int N,M,Q,lg[Ndim];
unsigned char RMQ[10][10][Ndim][Ndim],A[Ndim][Ndim],B[Ndim][Ndim],V[4];
bool MAT [Ndim][Ndim];
char S[Ndim];
void read()
{
    int i,j;
    fin>>N>>M>>Q;
    for(i=1;i<=N;i++)
    {
        fin>>(S+1);
        for(j=1;j<=M;j++)
            MAT[i][j]=S[j]-'0';
    }

}
void din_prep()
{
    int i,j,l,c;
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(MAT[i][j]==0)
            {
                A[i][j]=A[i][j-1]+1;
                B[i][j]=B[i-1][j]+1;
                RMQ[0][0][i][j]=min((unsigned char)(RMQ[0][0][i-1][j-1]+1),min(A[i][j],B[i][j]));
            }
    for(i=2;i<=N||i<=M;i++)
        lg[i]=lg[i/2]+1;
    l=0;
    for(c=1;(1<<c)<=M;c++)
        for(i=1;i<=N;i++)
            for(j=1;j+(1<<c)-1<=M;j++)
                RMQ[l][c][i][j]=max(RMQ[0][c-1][i][j],RMQ[0][c-1][i][j+(1<<(c-1))]);
    c=0;
    for(l=1;(1<<l)<=N;l++)
        for(i=1;i+(1<<l)-1<=N;i++)
            for(j=1;j<=M;j++)
                RMQ[l][c][i][j]=max(RMQ[l-1][0][i][j],RMQ[l-1][0][i+(1<<(l-1))][j]);
    for(l=1;(1<<l)<=N;l++)
        for(c=1;(1<<c)<=M;c++)
            for(i=1;i+(1<<l)-1<=N;i++)
                for(j=1;j+(1<<c)-1<=M;j++)
                    RMQ[l][c][i][j]=max(max(max(RMQ[l-1][c-1][i][j] , RMQ[l-1][c-1][i+(1<<(l-1))][j]) ,
                                    RMQ[l-1][c-1][i][j+(1<<(c-1))]) , RMQ[l-1][c-1][i+(1<<(l-1))][j+(1<<(c-1))]);
}
bool verif(int x1,int y1,int x2, int y2,int L)
{
    int l=x2-x1+1,c=y2-y1+1;
    int pl=lg[l],pc=lg[c];
    return L<=max(max(max(RMQ[pl][pc][x1][y1] , RMQ[pl][pc][x1+l-(1<<pl)][y1]) ,RMQ[pl][pc][x1][y1+c-(1<<pc)]) , RMQ[pl][pc][x1+l-(1<<pl)][y1+c-(1<<pc)]);
}
void solve()
{
    int i,st,dr,mid,x1,y1,x2,y2;
    fin.get();
    while(Q--)
    {
        fin.getline(S+1,20);
        int nr=0;
        for(i=0;i<4;i++)
            V[i]=0;
        for(i=1;i<=strlen(S+1);i++)
        {
            if(S[i]>='0'&&S[i]<='9')
                V[nr]=V[nr]*10+S[i]-'0';
            else
                nr++;
        }
        x1=V[0];y1=V[1];x2=V[2];y2=V[3];
        st=1;dr=min(x2-x1+1,y2-y1+1);
        while(st<=dr)
        {
            mid=(st+dr)/2;
            if(verif(x1+mid-1,y1+mid-1,x2,y2,mid))//apelez functia verif cu coord x1+L y1+l, x2 y2
                st=mid+1;
            else
                dr=mid-1;
        }
        fout<<st-1<<'\n';
    }
}
int main()
{
    read();
    din_prep();
    solve();
    return 0;
}
