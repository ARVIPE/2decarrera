#include <iostream>
using namespace std;

template <class T>
void mostrar(T *v, const int n)
{
  for(int i=0;i<n;i++)
  cout << v[i] << " , ";
}
int main(void)
{
  int enteros[9]={1,3,5,7,9,45,-1,-234,6};
  float flotantes[7]={5.6, 7.8, 3.9, 1.2,6.09,54.12,7.6};
  char letras[3]="SOS";
  cout << "------------------ENTEROS------------------";
  mostrar(enteros, 9);
  cout << "-----------------FLOTANTES-----------------";
  mostrar(flotantes,4);
  cout << "----------------CARACTERES------------------";
  mostrar(letras,4);
}