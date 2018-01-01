#include<fstream>
using namespace std;
ifstream cin("miere.in");
ofstream cout("miere.out");
long long n,m,i,x,v[50001],nr,j;
int main()
{
 	cin>>n;
 	for(i=1;i<=n;i++)
        cin>>v[i];
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x;
        nr=0;
        for(j=1;j<=n;j++)
        {
            if(x>=v[j])
            {
                x=x-v[j];
                nr++;
            }
            else
            {
                cout<<nr<<"\n";
                break;
            }
        }
        for(j=1;j<=n;j++)
            v[j]++;
    }
	return 0;
}
