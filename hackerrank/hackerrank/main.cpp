#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char s;
ofstream out(".out");
int main()
{
    while(cin.get(s))
    {
        if(s<='Z' and s>='A' or s<='z' and s>='a')
            out<<s;
        out<<s;
    }
    return 0;
}
