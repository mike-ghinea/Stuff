#include<fstream>
#define Ndim 1000000
#define Mdim 2048
using namespace std;
ifstream cin("ksecv4.in");
ofstream cout("ksecv4.out");
int N,M,K;
long long MinT[4*Ndim],MaxT[4*Ndim],A[Mdim],B[Mdim],V[Ndim], P=1ll<<60;
void update_min(int nod, int st, int dr, int poz, long long val)
{
    if(st==dr)
    {
        MinT[nod]=val;
        return;
    }
    int mid = (st+dr)/2;
    if(mid>=poz)
        update_min(2*nod, st, mid, poz, val);
    else
        update_min(2*nod+1, mid+1, dr, poz, val);
    MinT[nod]=min(MinT[2*nod], MinT[2*nod+1]);
}
void update_max(int nod, int st, int dr, int poz, long long val)
{
    if(st==dr)
    {
        MaxT[nod]=val;
        return;
    }
    int mid = (st+dr)/2;
    if(mid>=poz)
        update_max(2*nod, st, mid, poz, val);
    else
        update_max(2*nod+1, mid+1, dr, poz, val);
    MaxT[nod]=max(MaxT[2*nod], MaxT[2*nod+1]);
}
long long query_min(int nod, int st, int dr, int a, int b)
{
    if(st>=a and dr<=b)
        return MinT[nod];
    long long Sol = P;
    int mid = (st+dr)/2;
    if(mid>=a)
        Sol = min(Sol, query_min(nod*2, st, mid, a, b));
    if(mid<b)
        Sol = min(Sol, query_min(nod*2+1, mid+1, dr, a, b));
    return Sol;
}
long long query_max(int nod, int st, int dr, int a, int b)
{
    if(st>=a and dr<=b)
        return MaxT[nod];
    long long Sol = 0;
    int mid = (st+dr)/2;
    if(mid>=a)
        Sol = max(Sol, query_max(nod*2, st, mid, a, b));
    if(mid<b)
        Sol = max(Sol, query_max(nod*2+1, mid+1, dr, a, b));
    return Sol;
}
bool verif(int val)
{
    int st,dr,mid,poz=0;
    for(int i=1;i<=K;i++)
    {
        st = poz;
        dr = N-K+i-1;
        while(st<=dr)
        {
            mid = (st+dr)/2;
            long long Q = (query_max(1,0,N-1,poz,mid)-query_min(1,0,N-1,poz,mid)+1)/2;
            if(Q<=val)
                st=mid+1;
            else
                dr=mid-1;
        }
        poz=st;
    }
    if(poz<N)
        return 0;
    return 1;
}
int main()
{
    int i;
    cin>>N>>K>>M;
    for(i=0;i<M;i++)
        cin>>A[i];
    for(i=0;i<M;i++)
        cin>>B[i];
    long long valMax=0;
    for(i=0;i<N;i++)
    {
        V[i]=A[i%M] xor B[i/M];
        valMax=max(valMax, V[i]);
        update_min(1,0,N-1,i,V[i]);
        update_max(1,0,N-1,i,V[i]);
    }
    long long st=0;
    long long dr=valMax;
    while(st<=dr)
    {
        int mid = (st+dr)/2;
        if(verif(mid))
            dr = mid-1;
        else
            st = mid+1;
    }
    cout<<dr+1;
    return 0;
}
