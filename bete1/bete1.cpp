#include<fstream>
using namespace std;
ifstream cin("bete1.in");
ofstream cout("bete1.out");
int n,i,x,y,s,maxx,maxy,nrx=1,nry=1;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        s=s+x;
        if(maxx<x)
            {maxx=x;
             nrx=1;}
        else if(maxx==x)
            {maxx=x;
            nrx++;}
        else
            maxx=maxx;
    }
    for(i=n+1;i<=2*n;i++)
    {
        cin>>y;
        s=s+y;
        if(maxy<y)
            {maxy=y;
             nry=1;}
        else if(maxy==y)
            {maxy=y;
             nry++;}
        else
            maxy=maxy;
    }
    cout<<s/n<<"\n"<<maxx+maxy<<endl;
    if(nrx>nry)
        cout<<nry;
    else if(nry>nrx)
        cout<<nrx;
    else if(nry==nrx)
        cout<<nrx;
    return 0;
}

