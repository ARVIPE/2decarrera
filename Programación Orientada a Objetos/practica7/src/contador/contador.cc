#include "contador.h"

Contador Contador::operator=(const Contador &c){
    valor_ = c.get();
    if(valor_ > max_){
        valor_ = max_;
    }
    if(valor_ < min_){
        valor_ = min_;
    }

    return *this;
}

Contador Contador::operator=(int i){
    valor_ = i;
    if(valor_ > max_){
        valor_ = max_;
    }
    if(valor_ < min_){
        valor_ = min_;
    }

    return *this;

}

Contador Contador::operator++(){
    valor_++;
    if(valor_ > max_){
        valor_ = max_;
    }
    return *this;
}

Contador Contador::operator++(int){
    Contador aux = *this;
    valor_++;
    if(valor_ > max_){
        valor_ = max_;
    }
    return aux;
    
}

Contador Contador::operator--(){ //--contador
    valor_--;
    if(valor_ < min_){
        valor_ = min_;
    }
    return *this;
}

Contador Contador::operator--(int){ //contador--
    Contador aux = *this;
    valor_--;
    if(valor_ < min_){
        valor_ = min_;
    }
    return aux;
}

Contador Contador::operator+(int num){ //Contador = contador + int
    valor_ = valor_ + num;
    if(valor_> max_){
        valor_ = max_;
    }
    return *this;
    
}

Contador operator+(int i, const Contador &c){//Contador = int + Contador
    int aux = c.get();

    aux = i + aux;

    if(aux > c.getmax()){
        aux = c.getmax();
    }
    Contador d = Contador(aux, c.getmin(), c.getmax());
    return d;
    
}

Contador Contador::operator-(int num){
    valor_ = valor_ - num;

    if(valor_ < min_){
        valor_=min_;
    }

    return *this;
}

Contador operator-(int i, const Contador &c){
    int aux = c.get();

    aux = i-aux;

    if(aux < c.getmin()){
        aux = c.getmin();
    }

    Contador d = Contador(aux, c.getmin(), c.getmax());
    return d;
}

std::ostream &operator<< (std::ostream &o, const Contador &c){
    o <<c.get();
    return o;
}

std::istream &operator>> (std::istream &i, Contador &c){
 while(1){
        int valor;
        i >> valor;
        if((valor < c.getmax()) || (valor > c.getmin())){
            return i;
        }
    }
}

