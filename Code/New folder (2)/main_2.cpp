#include<fstream>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
ifstream fin("2.in");
int i,t,T,k,p[101],n;
char ch[101];
int main()
{
    fin>>t;
    for(T=1;T<=t;T++)
    {
        fin>>n;
        fin.get();
        memset(ch,0,sizeof(ch));
        memset(p,0,sizeof(p));
        fin.getline(ch,101);
        p[0]=strlen(ch);
        int j=0;
        for(i=p[0];i>=1;i--)
            p[i]=ch[j++]-'0';
    }
    return 0;
}
