#include <fstream>

using namespace std;
ifstream fin("distante.in");
ofstream fout("distante.out");
int n,m,s,OK,t,i,d[50010],a,b,c;
int main()
{
    fin>>t;
    while(t)
    {
        t--;
        fin>>n>>m>>s;
        OK=1;
        for(i=1;i<=n;i++)
        {
            fin>>d[i];
            if(d[i]!=0&&i==s)
            {
                OK=0;
            }
        }
        for(i=1;i<=m;i++)
        {
            fin>>a>>b>>c;
            if(d[a]+c<d[b]||d[b]+c<d[a])
                OK=0;
        }
        if(OK)
            fout<<"DA"<<'\n';
        else
            fout<<"NU"<<'\n';
    }
    return 0;
}
