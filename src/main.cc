#include <iostream>
#include <cstdlib>
#include "../lib/mymathfunc.hpp"

using namespace std;
MyMathFunc func;
int main()
{
    
    double a = 19.85;
    double b = 8.91;
    
    cout << "a + b = " <<
        func.add(a, b) << endl;
    cout << "a - b = " <<
        func.subtract(a, b) << endl;
    cout << "a * b = " <<
        func.multiply(a, b) << endl;
    cout << "a / b = " <<
        func.divide(a, b) << endl;
    cout << "a * a = " <<
        func.square(a) << endl;
    return 0;
}