#include<fstream>
#include<vector>
#include<set>
#include<algorithm>
#define DIM 200001
#define poz second
#define val first
using namespace std;
ifstream cin("sir3.in");
ofstream cout("sir3.out");
int v[DIM],x[DIM],N,S,i;
pair<int,int> w[DIM];
set <pair<int,int> > Set;
int am[4*DIM], AM[4*DIM],solm,solM,sol,stsol,drsol;
int a,b;
void build(int nod, int st, int dr)
{
    if (st == dr)
    {
        am[nod] = x[st];
        AM[nod] = x[st];
    }
    else
    {
        int mid = (st + dr)/2;
        build(2*nod, st, mid);
        build(2*nod+1, mid+1, dr);
        am[nod] = min(am[2*nod], am[2*nod+1]);
        AM[nod] = max(AM[2*nod], AM[2*nod+1]);
    }
}
void querym(int nod, int st, int dr)
{
    if (a <= st and dr <= b)
    {
        solm = min(solm, am[nod]);
        return;
    }
    int mid = (st + dr)/2;
    if (a <= mid)
        querym(2*nod, st, mid);
    if (b >= mid+1)
        querym(2*nod+1, mid+1, dr);
}
void queryM(int nod, int st, int dr)
{
    if (a <= st and dr <= b)
    {
        solM = max(solM, AM[nod]);
        return;
    }
    int mid = (st + dr)/2;
    if (a <= mid)
        queryM(2*nod, st, mid);
    if (b >= mid+1)
        queryM(2*nod+1, mid+1, dr);
}
int main ()
{
    cin>>N>>S;
    for(i=1;i<=N;i++)
    {
        cin>>v[i];
        w[i].val = v[i];
        w[i].poz = i;
    }
    sort(w+1, w+N+1);
    for (i=1;i<=N;i++)
    {
        int st=1, dr=N;
        int mid;
        while(st<=dr)
        {
            mid=(st+dr)/2;
            if (w[mid].val == S-v[i])
                break;
            if (w[mid].val < S-v[i])
                st=mid+1;
            else
                dr=mid-1;
        }
        if (st <= dr)
        {
            x[i] = w[mid].poz;
            int p = i;
            int v = x[i];
            if (p>v)
                swap(p,v);
            Set.insert(make_pair(p,v));
        }
        else
            x[i]=0;
    }
    build(1,1,N);
    for (set<pair<int,int> >::iterator it=Set.begin();it!=Set.end();it++)
    {
        solm = N+1;
        solM = 0;
        a=it->first;
        b=it->second;
        a++;
        b--;
        querym(1, 1, N);
        queryM(1, 1, N);
        a--;
        b++;
        if(solm > a and solM <b)
        {
            if (b-a > sol)
            {
                sol = b-a;
                stsol = a;
                drsol = b;
            }
        }
    }
    cout<< sol+1<<" "<<stsol<<" "<<drsol;
    return 0;
}
