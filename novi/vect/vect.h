#ifndef _VECT_H_IS_INCLUDED_
#define _VECT_H_IS_INCLUDED_

#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include<cmath>
#include <sstream>



using namespace std;
// deklaracija potrebna za testiranje
template <typename> class VectTest;

template <typename T>
class Vect
{
    friend class VectTest<T>;  // da testovi mogu dohvatiti privatne varijable
public:
    explicit Vect(size_t n = 0, T v= {});  // Ctor
    // Kontrola kopiranja dolazi ovdje
    // CCtor
    // MCtor
    // OP
    // MOP
    // DTOR


    explicit Vect(const Vect<T>& v);

    explicit Vect(Vect<T> && v) ;

     Vect& operator=(const Vect<T> & v);

     Vect& operator=( Vect<T> && v);

     ~Vect() { free();}

     T const& operator[] (size_t index) const;

     T & operator[] (size_t index);

     void push_back(T value);

     size_t size() const;

     size_t capacity() const;

   ostream& operator<<(ostream& out);



      Vect<T>& operator+=(const Vect<T>& y);
      Vect<T>& operator-=(const Vect<T>& y);


      Vect<T>&  operator-(const Vect<T> & y) ;
      Vect<T>&  operator+(const Vect<T> & y) ;



























double two_norm() const;
    // dohvat elemenata (operator [])
    // push_back metoda

     // info rutine size() i capacity()

     // operatori +=, -=, *=
     // euklidska norma vraća double !

private:
        T *mdata;       // pokazivač na prvi element
        T *mfirst_free; // pokazivač na prvo slobodno mjesto
        T *mend;        // pokazivač na kraj alociranog prostora
                             // (jedno mjesto iza posljednjeg)
  
        // Oslobodi zauzeti prostor (pomoću alokatora)
        void free();

      	// realociraj na novu lokaciju. Povećaj dimenziju vektora 2 puta; ako je 
        // vektor prazan alociraj jedan element. 
        void reallocate();

        // dodati vlastite privatne metode.
	
        // alokator ne mora imati pristup varijablama članicama klase pa ga činimo 
        // statičkim. Ne zaboraviti definirati ga.
        static std::allocator<T> alloc;
};

template <typename T>
 ostream& operator<<(ostream& out, Vect<T> const & v);

// template <typename T>
// Vect<T>  operator+( Vect<T> const& x, Vect<T> const & y) ;



// template <typename T>
// Vect<T>  operator-(const Vect<T> & x,const Vect<T> & y) ;









// Deklaracija operator +, - i << 

// Implementacija je u posebnoj .h datoteci
#include "vect_impl.h"

#endif
