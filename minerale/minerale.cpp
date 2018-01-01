#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("minerale.in");
ofstream cout("minerale.out");
char a,b,c,s[101];
int MATRIX[27][27],ARRAY[27],r,m,i,j,k,pas,d[101][101];
int res(int x,int y)
{
    int i,j;
    int rez=0;
    for(i=0;i<=26;i++)
    {
        int aux=(1<<i);
        if(x&aux)
        {
            for(j=0;j<=26;j++)
            {
                int aux2=(1<<j);
                if(y&aux2)
                    rez|=MATRIX[i][j];
            }
        }
    }
    return rez;
}
int main()
{
    cin>>r>>m;
    for(i=1;i<=r;i++)
    {
        cin>>a>>b;
        if(b<='Z')
        {
            cin>>c;
            MATRIX[b-'A'][c-'A']|=(1<<(a-'A'));
            continue;
        }
        ARRAY[b-'a']|=(1<<(a-'A'));
    }
    for(r=1;r<=m;r++)
    {
        cin>>s;
        memset(d,0,sizeof(d));
        int L=strlen(s);
        for(i=1;i<=L;i++)
            d[i][i]=ARRAY[s[i-1]-'a'];
        for(pas=2;pas<=L;pas++)
        {

            for(i=1;i+pas-1<=L;i++)
            {
                j=i+pas-1;
                for(k=i;k<j;k++)
                    d[i][j]|=res(d[i][k],d[k+1][j]);
            }
        }
        if(d[1][L]&(1<<('S'-'A')))
            cout<<1<<"\n";
        else if(d[1][L]==0)
            cout<<0<<"\n";
        else
            cout<<2<<"\n";
    }
}
