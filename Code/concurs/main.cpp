#include <vector>
#include <fstream>

using namespace std;

#define MAX_N 32005
#define MAX_L 20


int K, N, M,a,b,cost[MAX_N],i,sol,nod,c1,c2,tata;
bool viz[MAX_N];
int L[MAX_N << 1], H[MAX_N << 1],Lg[MAX_N << 1], First[MAX_N];
int Rmq[MAX_L][MAX_N << 2];

vector <int> G[MAX_N];

ifstream fin ("concurs.in");
ofstream fout ("concurs.out");

void citire()
{
    fin >> N >> M;
    for(i=1;i<=N;i++)
        fin>>cost[i];
    for(i=1;i<N;i++)
    {
        fin>>a>>b;
        G[a].push_back(b);
        viz[b]=1;
    }
}

void dfs(int nod, int lev)
{
    H[++K] = nod; //nodul actual este adaugat in reprezentarea Euler a arborelui
    L[K] = lev; //se retine nivelul fiecarei pozitii din reprezentarea Euler a arborelui
    First[nod] = K; //se retine si prima aparitie a fiecarui nod in reprezentarea Euler a arborelui

    for(size_t i=0;i<G[nod].size();i++)
    {
        dfs(G[nod][i], lev+1);

        H[++K] = nod;
        L[K] = lev;
    }
}

void rmq()
{
//in Rmq[i][j] va fi nodul de nivel minim dintre pozitiile (j, j + 2^i - 1) din reprezentarea Euler a arborelui
    for(int i = 2; i <= K; ++i)
        Lg[i] = Lg[i >> 1] + 1;
    for(int i = 1; i <= K; ++i)
        Rmq[0][i] = i;

    for(int i = 1; (1 << i) < K; ++i)
        for(int j = 1; j <= K - (1 << i); ++j)
        {
            int l = 1 << (i - 1);

            Rmq[i][j] = Rmq[i-1][j];
            if(L[Rmq[i-1][j + l]] < L[Rmq[i][j]])
                Rmq[i][j] = Rmq[i-1][j + l];
        }
}

int lca(int x, int y)
{
//LCA-ul nodurilor x si y va fi nodul cu nivel minim din secventa (First[x], First[y]) din reprezentarea Euler a arborelui
    int diff, l, sol, sh;
    int a = First[x], b = First[y];
    if(a > b) swap(a, b);
    diff = b - a + 1;
    l = Lg[diff];
    sol = Rmq[l][a];
    sh = diff - (1 << l);
    if(L[sol] > L[Rmq[l][a + sh]])
        sol = Rmq[l][a + sh];
    return H[sol];
}

int main()
{
    citire();
    for(int i=1;i<=N;i++)
        if(!viz[i])
        {
            tata=i;
            break;
        }
    dfs(tata, 0);
    rmq();

    for(i=1;i<=M;i++)
    {
        int x, y;
        fin >> x >> y;
        int nod = lca(x,y);
        if(sol<cost[nod])
        {
            sol=cost[nod];
            c1=x;
            c2=y;
        }
        else if(cost[nod]==sol)
        {
            if(x<=c1)
            {
                if(y<c2)
                {
                    c1=x;
                    c2=y;
                }
            }

        }
    }
    fout<<sol<<' '<<c1<<' '<<c2;
}
