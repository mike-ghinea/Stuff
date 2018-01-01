#include<fstream>
using namespace std;
ifstream cin("speeding.in");
ofstream cout("speeding.out");
struct wert{
    int dist;
    int speed;
};
wert way[101];
wert tr[101];
int speedy[101];
int i,N,M,j,k;
int main()
{
    cin>>N>>M;
    j=1;
    for(i=1;i<=N;i++)
    {
        cin>>way[i].dist>>way[i].speed;
        k+=way[i].dist;
        for(;j<=k;j++)
            speedy[j]=way[i].speed;
    }
    k=0;
    j=1;
    int Max=0;
    for(i=1;i<=M;i++)
    {
        cin>>tr[i].dist>>tr[i].speed;
        k+=tr[i].dist;
        for(;j<=k;j++)
            Max=max(tr[i].speed-speedy[j],Max);
    }
    cout<<Max;
}
