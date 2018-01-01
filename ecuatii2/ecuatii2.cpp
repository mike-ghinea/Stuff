#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
ifstream cin("ecuatii2.in");
ofstream cout("ecuatii2.out");
int n,i,sx,s;
string eq;
int main()
{
    cin>>n;
    while (cin>>eq)
    {
        int k=0,semn=1;
        s=sx=0;
        for (i=0;i<eq.size();i++)
            {
                if (eq[i]=='=')
                {
                    k=1;
                    semn=-1;
                    continue;
                }
                if (!k)
                {
                    if (eq[i]=='+')
                        semn=1;
                    else if (eq[i]=='-')
                        semn=-1;
                    if (eq[i]=='x')
                        sx+=semn;
                    if ('0'<=eq[i] and eq[i]<='9')
                    {
                        int sum,j;
                        sum=eq[i]-'0';
                        j=i+1;
                        while('0'<=eq[j] and eq[j]<='9')
                            sum=sum*10+eq[j++]-'0';
                        if(eq[j]=='x')
                        {
                            sx+=sum*semn;
                            i=j;
                        }
                        else
                        {
                            s+=sum*semn;
                            i=j-1;
                        }
                    }
                }
                else
                {
                    if (eq[i]=='+')
                        semn=-1;
                    else if (eq[i]=='-')
                        semn=1;
                    if (eq[i]=='x')
                        sx+=semn;
                    if ('0'<=eq[i] and eq[i]<='9')
                    {
                        int sum,j;
                        sum=eq[i]-'0';
                        j=i+1;
                        while('0'<=eq[j] and eq[j]<='9')
                            sum=sum*10+eq[j++]-'0';
                        if(eq[j]=='x')
                        {
                            sx+=sum*semn;
                            i=j;
                        }
                        else
                        {
                            s+=sum*semn;
                            i=j-1;
                        }
                    }
                }
        }
        if (sx==0 and s==0)
            cout<<"infinit\n";
        else if (sx==0 && s!=0)
            cout<<"imposibil\n";
        else
         cout<<fixed<<setprecision(5)<<(double)(-s)/sx<<"\n";
    }
    return 0;
}
