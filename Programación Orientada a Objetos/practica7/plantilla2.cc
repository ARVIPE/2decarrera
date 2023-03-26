#include <iostream>
using namespace std;
template <class T> class MiClase{
  private:
      T x_, y_;
  public:
      MiClase (T a, T b){ x_=a; y_=b;};
      T divide(){return x_/y_;};
};
int main(){
  MiClase <int> enteros(666,3);
  MiClase <double> dobeles(78.4455, 45.5301);
  cout << "DIVISION DE ENTEROS = " << enteros.divide() << endl;
  cout << "DIVISION DE REALES = " << dobeles.divide() << endl;
}