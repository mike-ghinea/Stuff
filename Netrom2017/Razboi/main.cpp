//#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <bitset>
#include <vector>
using namespace std;
ofstream cout("raz.out");
void f(int j1[], int j2[])
{
    int i;
    vector<int>A,B,C;
    pair<string,int>F[15];
    for(i=2;i<15;i++)
        F[i].first=i+48, F[i].second=i;
    F[10].first="10";
    F[11].first="A";
    F[11].second=15;
    F[12].first="J";
    F[13].first="Q";
    F[14].first="K";
    for(i=25;i>=0;i--)
        A.push_back(j1[i]),B.push_back(j2[i]);
}

int main(int argc, char **argv)
{
    int j1[] = {10,13,11,7,8,5,11,5,8,8,12,6,9,9,3,6,12,7,11,3,5,14,6,7,2,4},j2[] = {9,13,14,12,13,5,4,7,11,10,3,9,13,10,2,4,2,8,4,12,14,6,14,2,3,10};
    f(j1,j2);
    return 0;
}
