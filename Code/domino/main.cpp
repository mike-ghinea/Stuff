#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

#define DIM 50010

using namespace std;
ifstream fin("domino.in");
ofstream fout("domino.out");
int viz[DIM],i,n,a,b,nrimp,vf,l[10],nr,vf1,vf2;
vector <int> G[10];
stack <int> stv,V[10][10];
vector<int>::iterator it;
char s[10];
void DFS(int nod)
{
    viz[nod]=1;
    for(int i=0;i<l[nod];i++)
    {
        if(!viz[G[nod][i]])
            DFS(G[nod][i]);
    }
}
void euler(int nod)
{
    stv.push(nod);
    while(!stv.empty())
    {
        nod=stv.top();
        l[nod]=G[nod].size();
        if(l[nod])
        {
            int nou = G[nod].back();

            if(nod!=vf2 || nou!=vf1)
            {
                stv.push(nou);
                G[nou].erase(find(G[nou].begin(),G[nou].end(),nod));
            }
            G[nod].pop_back();
        }
        else
        {
            viz[++nr]=nod;
            stv.pop();
        }
    }
}
int main()
{
    fin>>n;
    fin.get();
    for(i=1;i<=n;i++)
    {
        fin.getline(s,10);
        a=s[0]-'0';
        b=s[2]-'0';
        G[a].push_back(b);
        G[b].push_back(a);
        V[a][b].push(i);
    }
    for(i=0;i<=9;i++)
    {
        l[i]=G[i].size();
        if(l[i]&1)
        {
            if(!vf1)
                vf1=i;
            else
                vf2=i;
            nrimp++;
        }
    }
    if(nrimp==1||nrimp>2)
    {
        fout<<0<<'\n';
        return 0;
    }
    for(i=0;i<=9;i++)
    {
        if(l[i])
        {
            vf=i;
            DFS(vf);
            break;
        }
    }
    for(i=0;i<=9;i++)
    {
        if(!viz[i] && l[i]>0)
        {
            fout<<0<<'\n';
            return 0;
        }
    }
    fout<<1<<'\n';
    if(nrimp==0)
    {
        euler(vf);
    }
    else
    {
        G[vf2].insert(G[vf2].begin(),vf1);
        l[vf2]++;
        euler(vf1);
    }
    for(i=1;i<=n;i++)
        {
            a=viz[i];
            b=viz[i+1];
            if(!V[a][b].empty())
            {
                fout<<V[a][b].top()<<' '<<0<<'\n';
                V[a][b].pop();
            }
            else
            {
                fout<<V[b][a].top()<<' '<<1<<'\n';
                V[b][a].pop();
            }
           // fout<<viz[i]<<' ';
        }

    return 0;
}
