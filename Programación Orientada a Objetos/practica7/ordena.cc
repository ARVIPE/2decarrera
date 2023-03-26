#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main(){
    vector<int> v;

    int caso;
    int num;

    do{
        system("clear");
        cout << "Introduzca un númerito" << endl;
        cin >> num;

        v.push_back(num);

        cout << "¿Quiere introducir otro número?" << endl;
        cout << "Cualquier número - Si" << endl;
        cout << "2 - No" << endl;

        cin >> caso;
        

    }while(caso != 2);

    cout << "El vector desordenado es: " << endl;

    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        cout << ",";
    }

    cout << "\n";

    sort(v.begin(), v.end());

    cout << "El vector ordenado es: " << endl;

    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        cout << ",";
    }


}