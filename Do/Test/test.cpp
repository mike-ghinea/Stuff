#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cmath>
#include<windows.h>
#include<unistd.h>
#include<dos.h>
using namespace std;
void clrscr()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }
int GRESELI;
int ok;
int prim[]={0,2,3,5,7,11};
bool ciur[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0};
int va[12],vb[12];
int cmmdc(int a,int b)
{
    if(!b)
        return a;
    return cmmdc(b,a%b);
}
int cmmmc(int a,int b)
{
    return (a*b)/cmmdc(a,b);
}
int primm(int n)
{
    if(ciur[n]==1)
        return 1;
    return 0;
}
void part4()
{
    srand (time(NULL));
    int i=rand()%5+1;
    int j;
    do{
        j=rand()%5+1;
    }while(j==i);
    int a=prim[i];
    int b=prim[j];
    int x=rand()%5+1;
    int y;
    do{
        y=rand()%5+1;
    }while(x==y);
    int s=a*x+b*y;

    cout<<"4.Fie numerele prime distincte a si b.\nDandu-se suma lor afla cele doua numere:";
    if(x!=1)
        cout<<x;
    cout<<"a+";
    if(y!=1)
        cout<<y;
    cout<<"b="<<s<<"\n";
    bool ok=1;
    while(ok==1)
    {
        int r1,r2;
        cin>>r1>>r2;
        if(r1==a and r2==b)
        {
            cout<<"Felicitari!\nAcum poti sa treci la partea a cincea.\n";
            ok=0;
        }
        else
        {
            if(r1*x+r2*y==s and primm(r1) and primm(r2))
            {
                cout<<"Felicitari!\nO alta soltie era: "<<a<<" "<<b<<"\n";
                cout<<"Acum poti sa treci la partea a cincea.\n";
                ok=0;
            }
            else
                cout<<"Gresit!\nIncearca din nou.\n",GRESELI++;
        }

    }
    Sleep(1350);
}
void part3()
{
    srand (time(NULL));
    int r=4;
    int k=rand()%3;
    if(k==1)
        r*=3;
    else if(k==2)
        r*=9;
    k=rand()%100;
    if(k<=33)
        r*=5;
    k=rand()%100;
    if(k<=75 and k>=50)
        r*=7;
    k=rand()%100;
    if(k<=5 or k==87 or k==22 or k==55 or k==42 or k>=94)
        r*=11;
    int s1;
    k=rand()%9+1;
    s1=r*k;
    int s2;
    do{
        k=rand()%9+1;
        s2=r*k;
        if(s1%s2==0 or s2%s1==0 or s1==s2)
            s1/=2;
    }while(s1==s2 or s1%s2==0 or s2%s1==0);
    int r1,r2;

    cout<<"3)Fie numerele "<<s1<<" si "<<s2<<".\nAflati:\na)Cel mai mare divizor comun;\nb)Cel mai mic multiplu comun.\n";
    bool ok=1;
    r=cmmdc(s1,s2);
    int an=cmmmc(s1,s2);
    while(ok==1){
            cin>>r1>>r2;
    if(r1==r and r2==an)
        cout<<"Corect!\nTreci la partea a patra.\n",ok=0;
    else if(r1==r and r2!=an)
        cout<<"Decat punctul a) este corect.\nIncearca din nou.\n",GRESELI++;
    else if(r1!=r and r2==an)
        cout<<"Decat punctul b) este corect.\nIncearca din nou.\n",GRESELI++;
    else
        cout<<"Gresit!\nIncearca din nou.\n",GRESELI++;
    }
    Sleep(1350);
}
void part2()
{
    srand(time(NULL));
    int k1 = rand()%7+20;
    int k2 = rand()%7+20;
    int b1 = rand()%2+1,m;
    int b2 = rand()%2+1;
    cout<<"2)Fie 3^"<<k1<<" x 2^"<<k2-b1<<" + 3^"<<k1-b2<<" x 2^"<<k2<<".\n";
    int a1 = max(k2-b1,k2)-min(k2-b1,k2);
    int b = max(k1,k1-b2)-min(k1,k1-b2);
    cout<<"a)Aratati ca este divizibila cu "<<pow(3,b)+pow(2,a1)<<";\n";
    cout<<"b)Calculati numarul de divizori.\n";
    string S="3^";
    string a="";
    m=min(k1,k1-b2);
    while(m)
    {
        a+=m%10+48;
        m/=10;
    }
    reverse(a.begin(),a.end());
    S+=a;
    S+=" x 2^";
    a="";
    m=min(k2-b1,k2);
    while(m)
    {
        a+=m%10+48;
        m/=10;
    }
    reverse(a.begin(),a.end());
    S+=a;
    S+=" x ";
    a="";
    m=pow(3,b)+pow(2,a1);
    while(m)
    {
        a+=m%10+48;
        m/=10;
    }
    reverse(a.begin(),a.end());
    S+=a;
    a="";
    bool ok=1;
    while(ok==1){
    getline(cin,a);
    if(S==a)
        cout<<"Corect!\n",ok=0;
    else
        cout<<"Gresit!\n",GRESELI++;
    }
    int x;
    while(1)
    {   cin>>x;
        if(x==(min(k2-b1,k2)+1)*(min(k1-b2,k1)+1)*2)
            break;
        else
            cout<<"Gresit!\n",GRESELI++;
    }
    cout<<"Felicitari!\nAcum treci la partea a treia.";
    Sleep(1350);
}
void part1()
{
    srand(time(NULL));
    string r1,r2,r3;
    int v1[11];
    memset(v1,0,sizeof(v1));
    int x,k;
    cout<<"1)Scrieti numerele de forma:\n";
    x=rand()%299+1;
    k=rand()%4+2;
    cout<<"a)"<<x<<"x divizibile cu "<<k<<".\n";
    int y;
    int n=0;
    int ok=0;
    int okk=1;
    for(int i=0;i<=9;i++)
    {
        if((x*10+i)%k==0)
            v1[++n]=x*10+i;
    }
    while(okk)
    {ok=0;
        for(int i=1;i<=n;i++){
        cin>>y;if(y!=v1[i])ok=1;}
    if(ok==1)
        cout<<"Gresit!\n",GRESELI++;
    else cout<<"Corect!\n",okk=0;}
    x=rand()%299+1;
    k=rand()%4+2;
    cout<<"b)"<<x<<"x divizibile cu "<<k<<".\n";
    memset(v1,0,sizeof(v1));
    n=0;
    for(int i=0;i<=9;i++)
    {
        if((x*10+i)%k==0)
            v1[++n]=x*10+i;
    }
    okk=1;
    ok=0;
    while(okk)
    {ok=0;
        for(int i=1;i<=n;i++){
        cin>>y;if(y!=v1[i])ok=1;}
    if(ok==1)
        cout<<"Gresit!\n",GRESELI++;
    else cout<<"Corect!\n",okk=0;}
    x=rand()%299+1;
    k=rand()%4+2;
    cout<<"c)"<<x<<"x divizibile cu "<<k<<".\n";
    memset(v1,0,sizeof(v1));
    okk=1;
    ok=0;
    n=0;
    for(int i=0;i<=9;i++)
    {
        if((x*10+i)%k==0)
            v1[++n]=x*10+i;
    }
    while(okk)
    {ok=0;
        for(int i=1;i<=n;i++){
        cin>>y;if(y!=v1[i])ok=1;}
    if(ok==1)
        cout<<"Gresit!\n",GRESELI++;
    else cout<<"Corect!\n",okk=0;}
    cout<<"Felicitari!\nAcum treci la partea a doua.";
    Sleep(1350);
}
void part5()
{
    string S="";
    srand(time(NULL));
    int k=rand()%50+15;
    S+='1';
    for(int i=2;2*i<=k;i++)
    {
        if(k%i==0)
        {
            int m=i;
            S+=' ';
            while(m)
            {
                S+=m%10+48;
                m/=10;
            }
        }
    }
    S+=' ';
    int m=k;
    while(m)
    {
        S+=m%10+48;
        m/=10;
    }
    //cout<<S+"\n";
    reverse(S.begin(),S.end());

    cout<<"5.Scrieti divizorii propri ai numarului "<<k<<" in ordine descrescatoare.\n";
    string an;
    bool ok=1;
    cin.get();
    while(ok==1)
    {
        getline(cin,an);
        if(an==S)
            ok=0;
        else
            cout<<"Gresit!\nIncearca din nou.\n",GRESELI++;
    }
}
int main()
{
    char k;
    part1();
    clrscr();
    cin.get();
    part2();
    clrscr();
    part3();
    clrscr();
    part4();
    clrscr();
    part5();
    clrscr();
    cout<<"Felicitari!\nAi terminat tot testul.\n";
    cout<<"In total ai avut "<<GRESELI<<" greseli.";
    Sleep(2000);
    return 0;
}
