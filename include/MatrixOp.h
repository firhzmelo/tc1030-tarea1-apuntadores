#ifndef MATRIXOP_H
#define MATRIXOP_H

/**
 * @file MatrixOp.h
 * @brief Definición de clase Matriz
 * @date 2026-05-18
 * @author Fernando Hernández Melo
 */



class MatrixOp{
    private:
        double* data_;
        int rows_;
        int cols_;
    public:
        MatrixOp(int, int);
        ~MatrixOp();
        void set(int, int, double);
        double get(int, int);
        void add(const MatrixOp*, const MatrixOp*) const;
        void forEachDiagonal(void (MatrixOp::*)(int, int));
        void printAt(int, int);
        int getRows() const {
            return rows_;
        }

        int getCols() const {
            return cols_;
        }
};


using OpFunc = double (*)(double, double);
void apply(MatrixOp* a, MatrixOp* b, MatrixOp* ans, OpFunc op);


#endif