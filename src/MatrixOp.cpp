#include "MatrixOp.h"
#include <iostream>
#include <stdexcept>
#include <string>

MatrixOp::MatrixOp(int rows, int cols){
    rows_ = rows;
    cols_ = cols;
    data_ = new double[rows_*cols_];
}

MatrixOp::~MatrixOp(){
    delete[] data_;
}

void MatrixOp::set(int i, int j, double x){
    if(i < 0 || i >= rows_)
        throw std::out_of_range("Index" + std::to_string(i) + "is out of range");
    if(j < 0 || j >= cols_)
        throw std::out_of_range("Index" + std::to_string(j) + "is out of range");
    data_[i*cols_ + j] = x;
}

double MatrixOp::get(int i, int j){
    if(i < 0 || i >= rows_)
        throw std::out_of_range("Index" + std::to_string(i) + "is out of range");
    if(j < 0 || j > cols_)
        throw std::out_of_range("Index" + std::to_string(j) + "is out of range");
 
    return data_[i*cols_ + j];
}

void MatrixOp::add(const MatrixOp *other, const MatrixOp *result) const {
    if(this->rows_ != other->rows_ || this->cols_ != other->cols_ ){
        std::cout<< "Dimensiones no compatibles\n";
        return;
    }
    for (int i = 0; i < rows_ * cols_; i++){
        result->data_[i] = this->data_[i] + other->data_[i];
    }
}

void apply(MatrixOp* a, MatrixOp* b, MatrixOp* ans, OpFunc op){
    if(a->getRows() != b->getRows() || a->getCols() != b->getCols()){
        return;
    }
    int rows = a->getRows(), cols = a->getCols();
    for(int i = 0; i<rows*cols; i++){
        ans->set(i/cols, i%cols, op(a->get(i/cols, i%cols), b->get(i/cols, i%cols)));
    }
}

void MatrixOp::printAt(int i, int j){
    std::cout<< this->get(i, j)<< " ";
}

void MatrixOp::forEachDiagonal(void (MatrixOp::* fn)(int, int)){
    int cols = this->getCols(), rows = this->getRows();
    for(int k = 0; k<std::min(rows, cols); k++){
        (this->*fn)(k, k);
    }
}