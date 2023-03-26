//pieza.h 
#include <iostream>
#include <string>

class Pieza
{
    private:
        std::string nombre_;
        int codigo_, cantidad_;
        double precio_;

    public:
    //constructor vacío
        Pieza(){nombre_="Sin Nombre";
                codigo_=0; 
                cantidad_=0; 
                precio_=0.0;};
    //constructor parametrizado
        Pieza(int codigo, std::string nombre, double precio=0.0, int cantidad=0){
            codigo_=codigo;
            nombre_=nombre;
            cantidad_=cantidad;
            precio_=precio;
        };
    //contructor de copia
        Pieza(Pieza const &p){
            nombre_=p.nombre_;
            codigo_=p.codigo_;
            cantidad_=p.cantidad_;
            precio_=p.precio_;
        };

    //observadores
        void  getNombre(std::string &nombre){nombre=nombre_;}
        inline int getCodigo(){return codigo_;}
        inline int getCantidad(){return cantidad_;}
        inline double getPrecio(){return precio_;}

    //modificadores
        inline void set_nombre(std::string nombre){nombre_=nombre;}
        inline void set_codigo(int codigo){codigo_=codigo;}
        inline void set_cantidad(int cantidad){cantidad_=cantidad;}
        inline void set_precio(double precio){precio_=precio;}

    std::string getPieza(){
        return "Hay " + std::to_string(cantidad_) + " unidades de la pieza " + nombre_ + ".";
    }            
};