#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("reactivi.in");
ofstream cout("reactivi.out");
int n,i,d=1;
struct dot{
    int a;
    int b;
}v[100003];
bool acompare(dot lhs, dot rhs) {
    return lhs.a < rhs.a;
    }

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>v[i].a>>v[i].b;
    sort(v+1,v+n+1,acompare);
    sort(v+1,v+n+1,acompare1);
    for (i=1;i<=n;i++)
        cout<<v[i].a<<" "<<v[i].b<<"\n";
    /*for (i=2;i<=n;i++)
        if(v[i].u>v[i-1].p)
            d++;
    cout<<d;*/
}
