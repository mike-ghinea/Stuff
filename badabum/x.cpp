#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
ifstream fin("x.in");
ofstream fout("x.out");
char s[]="Ana,are-un mar?verzui";
int c,i,k;
int main()
{
    cout<<s<<"\n";
    char *p=strtok(s," ,-?");
    while(p!=NULL)
    {
        //if(strlen(p)%2==1)
            cout<<p<<"\n";
        p=strtok(NULL," ,-?");
    }
}
