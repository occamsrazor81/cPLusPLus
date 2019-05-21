// Vaša implementacija dolazi ovdje.

#include <iostream>
#include <string>
#include <algorithm>
#include "vect.h"
#include <stdexcept>
#include<cmath>
#include <memory>
#include <sstream>



using namespace std;

template <typename T>
allocator<T> Vect<T>::alloc;


template<typename T>
 Vect<T>::Vect(size_t n , T v)
{
    mdata=nullptr;
    mend=nullptr;
    mfirst_free=nullptr;

    if(n>0)
    {
        mdata=alloc.allocate(n);
        for(size_t i=0; i < n; ++i)
        {

            alloc.construct(mdata+i,v);

        }
        mfirst_free=mdata+n;
        mend=mfirst_free;


    }
}



 template <typename T>
 Vect<T>::Vect(const Vect<T>& v)
 {

     mdata=nullptr;
     mend=nullptr;
     mfirst_free=nullptr;

     size_t duljina = v.size();

     if(duljina > 0)
     {
         mdata=alloc.allocate(duljina);
         mfirst_free=mdata+duljina;
         mend=mfirst_free;


         for(size_t i=0; i<duljina; ++i)
             alloc.construct(mdata+i,v[i]);

     }
 }

 template<typename T>
 Vect<T>::Vect(Vect<T> && v)
 {
     mdata=v.mdata;
     mfirst_free=v.mfirst_free;
     mend=v.mend;

     v.mdata=nullptr;
     v.mfirst_free=nullptr;
     v.mend=nullptr;
 }

 template<typename T>
 Vect<T>& Vect<T>::operator=(const Vect<T> & v)
 {

     if(this->mdata!=v.mdata)

     {
         free();
         size_t novaduljina=v.size();
         mdata=alloc.allocate(novaduljina);

                 mfirst_free=mdata+novaduljina;
                 mend=mfirst_free;



             for(size_t i=0; i<novaduljina;++i)
                 alloc.construct(mdata+i,v[i]);



     }

     return *this;
}


 template<typename T>
 Vect<T>& Vect<T>::operator=(Vect<T> && v)
 {
     if(this!=&v)
     {
         free();
         mdata=v.mdata;
         mfirst_free=v.mfirst_free;
         mend=v.mend;

         v.mdata=nullptr;
         v.mfirst_free=nullptr;
         v.mend=nullptr;

     }

    return *this;

 }

 template<typename T>
 size_t Vect<T>::size() const
 {
     size_t duljina;
     duljina = mfirst_free-mdata;
     return duljina;
 }

 template<typename T>
 size_t Vect<T>::capacity() const
 {
     size_t maxduljina;
     maxduljina=mend-mdata;
     return maxduljina;
 }


template<typename T>
 T const& Vect<T>::operator[] (size_t index) const
 {
     return mdata[index];
 }


 template<typename T>
  T & Vect<T>::operator[] (size_t index)
  {
      return mdata[index];
  }

template<typename T>
  double Vect<T>::two_norm() const
  {
        double norma2=0.0;
        for(size_t  i=0;i<size();++i)
            norma2+=mdata[i]*mdata[i];

        norma2=sqrt(norma2);
        return norma2;
  }

  template<typename T>
  void Vect<T>::push_back(T value)
  {
      if(mfirst_free==mend)
          reallocate();
      alloc.construct(mfirst_free++,value);
  }

  template<typename T>
  void Vect<T>::reallocate()
  {
      size_t novaduljina;
      if(size()>0)
      novaduljina=2*size();

      else
          novaduljina=1;

      T * novimdata=alloc.allocate(novaduljina);
      T * novimfirstfree=novimdata+size();
      T * novimend=novimdata+novaduljina;

      for(size_t i=0; i<size();++i)
          alloc.construct(novimdata+i,mdata[i]);

      free();

      mdata=novimdata;
      mfirst_free=novimfirstfree;
      mend=novimend;
}

    template<typename T>
  void Vect<T>::free()
  {
      if(mdata!=nullptr)
      {
          for(auto i=size();i>0;--i)
              alloc.destroy(mdata+i-1);

          alloc.deallocate(mdata,capacity());

      }

}



template <typename T>
  ostream& operator<<(ostream& out,  Vect<T> const & v)
  {
      out<<"[";
      for(size_t i=0;i<v.size();++i)
      {
          out<<v[i];
          if(i+1<v.size()) out<<",";
      }
      out<<"]";
      return out;
  }





//template<typename T>
// Vect<T> operator+( Vect<T> const & x, Vect<T>const & y)
// {


//         Vect<T> z;
//         for(size_t i=0;i<x.size();++i)
//             z[i]=x[i]+y[i];


//     return z;


// }


// template<typename T>
//  Vect<T> operator-(const Vect<T> & x,const Vect<T> & y)
//  {


//          Vect<T> z(x.size());
//          for(size_t i=0;i<x.size();++i)
//              z[i]=x[i]-y[i];


//      return z;


//  }



  template <typename T>
  Vect<T> & Vect<T>::operator+(const Vect<T>& y)
  {

      for(size_t i=0;i<size();++i)
          mdata[i]+=y.mdata[i];



      return *this;
  }





 template <typename T>
 Vect<T> & Vect<T>::operator-(const Vect<T>& y)
 {


     for(size_t i=0;i<size();++i)
         mdata[i]-=y.mdata[i];



     return *this;
 }





  template<typename T>
  Vect<T>& Vect<T>::operator+=(const Vect<T>& y)
  {

      for(size_t i=0;i<size();++i)
          mdata[i]+=y.mdata[i];

      return *this;
  }


  template<typename T>
  Vect<T>& Vect<T>::operator-=(const Vect<T>& y)
  {

      for(size_t i=0;i<size();++i)
          mdata[i]-=y.mdata[i];

      return *this;
  }
















