#ifndef COMPLEX_H
#define COMPLEX_H
#include <ostream>
#include <iostream>
template<typename T>
class complex{
public:
    T real;
    T img;
    complex(const T& r,const T& i){
        real=r;
        img=i;
    }
    complex operator +( const complex & v )
    {
        return complex( this->real + v.real, this->img + v.img );
    }

    complex operator -( const complex & v )
    {
        return complex( this->real - v.real, this->img - v.img );
    }

    complex operator *( const complex & v )
    {
        return complex( this->real * v.real+(this->img * v.img)*-1, this->real * v.img +this->img * v.real);
    }

    friend std::ostream& operator<<(std::ostream & out, const complex<T>& a) {
        if(a.real!=0){
            out << a.real;
        }
        if(a.img>0&&a.real!=0){
            out<<'+';
        }
        if(a.img!=0)
        out<< a.img<<'j';
        return out;
    }

};



#endif // COMPLEX_H
