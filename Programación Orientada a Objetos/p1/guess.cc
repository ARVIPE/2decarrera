#include <iostream>
#include <cstdlib> // Fíjate que no llevan la terminación .h
#include <ctime>   // Fíjate que no llevan la terminación .h
using namespace std;

int main(void)
{

    srand(time(NULL)); // time(NULL) returns “UNIX Epoch”, this is seconds
    // since 00:00:00 1 January 1970

    int random = rand() % 10 + 1;
    int num = 0;

    cout << "Introduzca un número del 1 al 10\n";

    while (num != random)
    {
        cin >> num;
        cout << "Introduzca otro número\n";
    }

    cout << "Has acertado!!!\n";
}