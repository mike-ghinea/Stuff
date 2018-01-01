#include <iostream>
#include <limits>
#include <windows.h>
#define line "                                 "
using namespace std;

int main()
{
    system ("COLOR A0");
    cout<<"HALLO";
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA7 );
    cout << "Press ENTER to quit." << flush;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA0 );
    cout<<"::";
    cin.ignore( numeric_limits <streamsize> ::max(), '\n' );

    return 0;
}
