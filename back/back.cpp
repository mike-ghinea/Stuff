#include <fstream>
using namespace std;
ifstream cin("permutari.in");
ofstream cout("permutari.out");
int x[20],n,viz[20],p,m;
void tipar(int k)
{
    for(int i=1;i<=k;i++)
        cout<<x[i]<<" ";
    cout<<"\n";
}
void back(int k)
{
    for(int i=1;i<=m;i+=2)
    {
            x[k]=i;
            viz[i]=1;
            if(k==n)
            {
                tipar(k);
            }
            else
            {
                back(k+1);
            }
            viz[i]=0;
    }
}
int main()
{
    cin>>n;
    m=n*2;
    back(1);
    return 0;
}
