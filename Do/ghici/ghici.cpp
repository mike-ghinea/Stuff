#include <fstream>
#include <cstring>
#include <algorithm>
#define MAXN 65536
#define MAXLG 18
using namespace std;
ifstream cin("ghicit.in");
ofstream cout("ghicit.out");
char A[MAXN];
struct entry {
    int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN],N,i,step,Count;
bool cmp(const entry &a, const entry &b) {
    if(a.nr[0]==b.nr[0])
        return a.nr[1]<b.nr[1];
    return a.nr[0]<b.nr[0];
}
int lcp(int x, int y) {
    int k,ret=0;
    if(x==y)
        return N-x;
    for(k=step-1;k >= 0 and x<N and y<N;k--)
        if (P[k][x]==P[k][y])
        {
            x+=(1<<k);
            y+=(1<<k);
            ret+=(1<<k);
        }
    return ret;
}
int a=0;
int main()
{
    cin.getline(A,MAXN);
    N=strlen(A);
    for(i=0;i<N;i++)
        P[0][i]=A[i]-'a';
    for(step=1,Count=1;Count >> 1 < N; ++step, Count <<= 1)
    {
        for(i=0;i<N;i++)
        {
            L[i].nr[0] = P[step - 1][i];
            if(Count+i<N)
                L[i].nr[1]=P[step - 1][i + Count];
            else
                L[i].nr[1]=-1;
            L[i].p=i;
        }
        sort(L,L+N,cmp);
        for(i=0;i<N;i++)
            if(i>0 and L[i].nr[0]==L[i-1].nr[0] and L[i].nr[1]==L[i-1].nr[1])
                P[step][L[i].p]=P[step][L[i-1].p];
            else
                P[step][L[i].p]=i;
    }
    a=N-L[0].p;
    for(i=1;i<N;i++)
    {
        a+=N-L[i].p;
        a-=lcp(L[i].p,L[i-1].p);
    }
    cout<<a;
    return 0;
}

