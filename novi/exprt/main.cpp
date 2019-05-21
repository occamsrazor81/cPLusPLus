#include <iostream>
#include <chrono>
#include <array>
#include <algorithm>
#include "operations.h"


using std::cout;
using std::endl;
using namespace std::chrono;

template<size_t N>
void makeTridiagonalMatrix(Matrix<N,N> A, double d, double sd)
{

    for(size_t i=0; i<N; ++i)
        for(size_t j=0; j<N; ++j)
        {
            if(i==j) A(i,j)=d;
            else if(abs(i-j)==1) A(i,j)=sd;
            else A(i,j)=0;
        }
}



int main()
{
    // Vaši testovi i test brzine
    const size_t max = 4;
    Matrix<max,max> A;

    // Napravi tridijagonalnu matricu s 2 na dijagonali i -1 na sporednim dijagonalama.
    makeTridiagonalMatrix(A,2.0,-1.0);

    Vector<max>  x, y(2.0), z(3.0);
    x[0]=1.0; x[1]= 1.5; x[2]=1;
    z = A*x;
    z = A*x +y;
    z = A*(x*3.0 + y);
		
    return 0;
}

