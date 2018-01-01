#include <fstream>

#define Ndim 705
#define zeros(x) ( (x ^ (x - 1)) & x )
#define MOD 30103
using namespace std;
ifstream fin("evantai.in");
ofstream fout("evantai.out");
int N,V[Ndim],AIB[Ndim][2004],sol,B[Ndim][Ndim];
void read()
{
    int a=0,b=0;
    fin>>N;
    for(int i=1;i<=N;i++)
        fin>>V[i];
}
void update(int l,int c,int val)
{
    while(l<=N)
    {
        int c1=c;
        while(c1<=2001)
        {
            AIB[l][c1]=(val+AIB[l][c1])%MOD;
            c1+=zeros(c1);
        }
        l+=zeros(l);
    }
}
int query(int l, int c)
{
    int val=0;
    while(l)
    {
        int c1=c;
        while(c1)
        {
            val=(AIB[l][c1]+val)%MOD;
            c1-=zeros(c1);
        }
        l-=zeros(l);
    }
    return val;
}
void solve()
{
    int i,j,val,x;
    for(i=N-1;i>=1;i--)
    {
        for(j=N;j>i;j--)
        {
            x=1+query(j-1,V[i]+V[j]-1);
            if(x>MOD)
                x-=MOD;
            sol+=x;
            if(sol>MOD)
                sol-=MOD;
            update(j,V[i]+V[j],x);
        }
    }
}
void print()
{
    fout<<sol%MOD;
}
int main()
{
    read();
    solve();
    print();
    return 0;
}
