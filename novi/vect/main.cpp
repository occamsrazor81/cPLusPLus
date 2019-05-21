#include "vect.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include<cmath>
#include<sstream>

using namespace std;

int main()
{
    // Vaši testovi dolaze ovdje.
    Vect<int>v1(3.8);
    Vect<int>v2(3);
    v2.push_back(4);
    v1.push_back(9);
    v2.push_back(18);
    v1.push_back(3);
    v1+=v2;

    Vect<int>v3(5.3);
    Vect<int>v4(5);
    v2.push_back(6);
    v1.push_back(93);
    v2.push_back(182);
    v1.push_back(34);
 Vect<int>v5;
 v5=v1+v2;







    return 0;
}
