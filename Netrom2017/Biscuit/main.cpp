//#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <bitset>
#include <vector>
using namespace std;
ofstream cout("out.out");
static unsigned long g1,g2,g3;
void f(unsigned short l, unsigned short c, unsigned short d)
{
    static int m[16][16],a,b,q,x[]= {1,2,3,2},f,g,h,i,*p;
    if(!g2++)
        memset(m,0,1024),a=b=0;
    p=&m[l=l*2+x[d]][c=c*2+x[3-d]];
    if(a+b<25)
    {
        cout<<"Jucatorul "<<(g1?"B":"A")<<" mutare ";
        if(l<2 | l>12 | c<2 | c>12 | *p)
            cout<<"invalida \n";
        else
            *p=1,
            f=*(p-17),
            g=*(p-15),
            h=*(p+15),
            i=*(p+17),
            (g1?b:a) += q=d%2 ? (*(p-32)&f&g) + (*(p+32)&h&i) : (*(p-2)&f&h) + (*(p+2)&g&i),
            cout<<"valida ("<<a<<':'<<b<<") \n",
            g1^=!q;
    }
    if(a+b>24)
        cout<<"Jocul s-a terminat \n";
}


int main(int argc, char **argv)
{
    f(0,0,0);
    f(0,0,1);
    f(0,1,2);
    f(1,1,3);
    f(1,0,0);
    f(0,1,2);
    f(0,1,1);
    f(0,2,2);
    f(1,2,3);
    int i,j,d;
    for(i=0;i<=5;i++)
        for(j=0;j<=5;j++)
            for(d=0;d<=3;d++)
                f(i,j,d);
    return 0;
}

