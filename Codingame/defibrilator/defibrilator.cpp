#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define longA coord.a
#define longB coord.c
#define latA coord.b
#define latB coord.d
#define adress first
#define distance second
using namespace std;
double convert(string X)
{
    double c;
    reverse(X.begin(),X.end());
    int n=X.length();
    int k=1,i;
    int ok=1;
    c=0;
    for(i=0;i<n;i++)
    {
        char C=X[i];
        if(ok==1)
        {
            if(C==',' or C=='.')
                ok=0;
            else
            {
                if(C=='0')
                    c/=10;
                else
                {
                    c+=(C-48);
                    c/=10;
                }
            }
        }
        else
        {
            if(C=='0')
                k*=10;
            else
            {
                c+=(C-48)*k;
                k*=10;
            }
        }
    }
    return c;
}
struct coordinate
{
    double a,b,c,d;
}coord;
double dif(double x1,double y1,double x2,double y2)
{
    double a=(x1-x2)*(x1-x2);
    double b=(y1-y2)*(y1-y2);
    double k=sqrt(a+b);
    return k;
}
int n,k,i,j;
string X,Y,Ad,ad,co;
vector <pair <string,double> > defib;
int main()
{
    cin>>X;
    cin.get();
    cin>>Y;
    cin.get();
    longA=convert(X);
    latA=convert(Y);
    cin>>k;
    cin.get();
    double Min=1<<30;
    for(i=1;i<=k;i++)
    {
        getline(cin,Ad);
        cin.get();
        n=Ad.length();
        ad="";
        for(j=0;j<n and Ad[j]!=';';j++);
        j++;
        for(;j<n and Ad[j]!=';';j++)
            ad+=Ad[j];
        j++;
        for(;j<n and Ad[j]!=';';j++);
        j++;
        for(;j<n and Ad[j]!=';';j++);
        j++;
        co="";
        for(;j<n and Ad[j]!=';';j++)
            co+=Ad[j];
        longB=convert(co);
        j++;
        co="";
        for(;j<n and Ad[j]!=';';j++)
            co+=Ad[j];
        latB=convert(co);
        double car=dif(longA,latA,longB,latB);
        Min=min(Min,car);
        defib.push_back(make_pair(ad,car));
    }
    n=defib.size();
    for(i=0;i<n;i++)
    {
        if(defib[i].distance==Min)
        {
            cout<<defib[i].adress;
            return 0;
        }
    }
}
