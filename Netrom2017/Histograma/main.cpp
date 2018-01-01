//#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <bitset>
#include <vector>
using namespace std;
ofstream cout("hist.out");
void f(string t[], char s[], int n)
{
    int i=0,j,M=0,a,e=256,v[e][100],u=32;
    string g=" ";
    char c[102][e],b,*p;
    memset(c,u,26112);
    for(;i<n;i++)
        for(j=0;j<t[i].size();)
            ++v[t[i][j++]][i];
    for(b='A';b<='Z';b++)
        for(i=0;i<n;i++)
            M=max(M,max(v[b+u][i],v[b][i]));
    for(i=1;i<=M;i++)
        for(b=65;b<92;b++)
            for(j=0;j<n;j++)
            {
                p=&c[i][b];
                if(v[b][j]==i)
                    *p=(*p==u)?s[j]:'x';
                if(v[b+u][j]==i)
                    *(p+u)=(*(p+u)==u)?s[j]:'x';
            }
    for(;i;i--)
        for(j=0;j<e;j++,p=&c[i][j])
            if(*p==u&*(p+e)!=u)
                *p=46;
    cout<<"  ^\n";
    for(i=M;i;)
    {
        cout<<(M>9&i<9?g:"")<<i--<<"|";
        for(b=65;b<91;b++)
            cout<<c[i+1][b]+g+c[i+1][b+u]+g;
        cout<<"\n";
    }
    cout<<" 0|";
    for(i=104;i;i--)
        cout<<'-';
    cout<<">\n   ";
    for(b=64;b<90;)
        cout<<b+g+char(++b+u)+g;
}
int main(int argc, char **argv)
{
    string t[3];
    char s[3];
    int n=3;
    s[0] = '#';
    s[1] = '*';
    s[2] = '$';
    t[0] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    t[1] = "";
    t[2] = "";
    f(t,s,n);
    return 0;
}

