#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
#define dim 101
using namespace std;
ifstream fin("pm2.in");
ofstream fout("pm2.out");
int val,v[dim],i,j,n,k,x,smax,st,dr,mij,c[dim],d[dim],t[dim],cnt1[dim],sol,cnt[dim],b[dim],nrb,Max,Max1;
vector <int> fii[dim];
queue <int> Q;
bool viz[dim];
int solve1(int poz,int incr)
{
    int Max1=0;
    memset(t,0,sizeof(t));
    memcpy(cnt,cnt1,sizeof(cnt));
    v[poz]+=incr;
    for(int i=1;i<=n;i++)
        if(cnt[i]==0)
        {
            Q.push(i);
            t[i]=v[i];
        }
    while(!Q.empty())
    {
        int nod=Q.front();
        for(vector<int>::iterator it = fii[nod].begin();it!=fii[nod].end();it++)
        {
            t[*it]=max(t[*it],t[nod]+v[*it]);
            cnt[*it]--;
            if(!cnt[*it])
                Q.push(*it);
        }
        Q.pop();
    }
    v[poz]-=incr;
    for(int i=1;i<=n;i++)
        Max1=max(Max1,t[i]);
    return Max1;
}
int solve(int poz,int incr)
{
    memcpy(cnt,cnt1,sizeof(cnt));
    v[poz]+=incr;
    for(i=1;i<=n;i++)
        if(cnt[i]==0)
        {
            Q.push(i);
            t[i]=v[i];
        }
    while(!Q.empty())
    {
        int nod=Q.front();
        for(vector<int>::iterator it = fii[nod].begin();it!=fii[nod].end();it++)
        {
            t[*it]=max(t[*it],t[nod]+v[*it]);
            c[*it]=max(c[*it],t[nod]);
            cnt[*it]--;
            if(!cnt[*it])
                Q.push(*it);
        }
        Q.pop();
    }
    v[poz]-=incr;
    for(i=1;i<=n;i++)
        Max1=max(Max1,t[i]);
    return Max1;
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>v[i];
    }
    for(i=1;i<=n;i++)
    {
        fin>>k;
        cnt1[i]=k;
        for(j=1;j<=k;j++)
        {
            fin>>x;
            fii[x].push_back(i);
        }
    }
    Max=solve(0,0);

    fout<<Max<<'\n';
    for(i=1;i<=n;i++)
    {
        st=0;
        dr=1000000;
        sol=0;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            int val = solve1(i,mij);
            if(val>Max)
            {
                dr=mij-1;
            }
            else
            {
                st=mij+1;
                sol=mij;
            }
        }
        d[i]=sol;
    }
    for(i=1;i<=n;i++)
        fout<<c[i]<<' '<<c[i]+d[i]<<'\n';

    return 0;
}
