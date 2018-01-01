#include <fstream>
#include <string.h>

#define Ndim 1005
using namespace std;
ifstream fin("kss.in");
ofstream fout("kss.out");
int N,t,NXT[28][Ndim],nrsol;
long long K,BST[Ndim];
char S[Ndim],SOL[Ndim];
void prep()
{
    memset(NXT,0,sizeof(NXT));
    for(int ch='a'-'a'; ch<='z'-'a'; ch++)
    {
        for(int i=N;i>=1;i--)
        {
            if(S[i]-'a'==ch)
                NXT[ch][i]=i;
            else
                NXT[ch][i]=NXT[ch][i+1];
        }
    }
}
void dinamic()
{
    memset(BST,0,sizeof(BST));
    for(int i=N;i>=1;i--)
    {
        BST[i]=1;
        for(int ch='a'-'a'; ch<='z'-'a'; ch++)
            BST[i]+=BST[NXT[ch][i+1]];
    }
}
int solve()
{
    int q=1,q1;
    nrsol=0;
    memset(SOL,0,sizeof(SOL));
    int ch=0;
    while(nrsol<N)
    {
        q1=NXT[ch][q];
        while(BST[q1]<K)
        {
            K-=BST[q1];
            ch++;
            if(ch>'z'-'a')
                return 0;
            q1=NXT[ch][q];
        }
        K--;
        SOL[++nrsol]=char(ch+'a');
        q=q1+1;
        ch=0;
        if(K==0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    fin>>t;
    while(t--)
    {
        fin>>N>>K;
        fin>>(S+1);
        prep();
        dinamic();
        if(solve())
        {
            fout<<(SOL+1)<<'\n';
        }
        else
            fout<<-1<<'\n';
    }
    return 0;
}
