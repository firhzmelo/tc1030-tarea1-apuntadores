#include <iostream>
#include "MatrixOp.h"
using namespace std;

double multi(double a, double b){
    return a*b;
}


int main(){
    // A1
    MatrixOp a(2, 2), b(2, 2);
    a.set(0, 0, 2);
    a.set(0, 1, 2);
    a.set(1, 0, 2);
    a.set(1, 1, 2);
    b.set(0, 0, 2);
    b.set(0, 1, 3);
    b.set(1, 0, 4);
    b.set(1, 1, 5);
    MatrixOp c(2, 2);
    // A2
    a.add(&b, &c);
    for(int i = 0; i<c.getCols(); i++){
        for(int j = 0; j<c.getRows(); j++){
            cout<< c.get(i, j)<< " ";
        }
        std::cout<< "\n";
    }
    // A3
    apply(&a, &b, &c, multi);
    for(int i = 0; i<c.getCols(); i++){
        for(int j = 0; j<c.getRows(); j++){
            cout<< c.get(i, j)<< " ";
        }
        std::cout<< "\n";
    }
    // A4
    c.forEachDiagonal(&MatrixOp::printAt);
    return 0;
}