
#ifndef MATRIX_SANDBOX_MATRIX_H
#define MATRIX_SANDBOX_MATRIX_H

class Matrix {
private:
    int width;
    int height;
    double **table;

    /**
     * Можно ли складывать матрицы
     * @param other другая матрица
     * @return true, если действие разрешено
     */
    bool canAdd(Matrix &other) {
        return this->getColumnSize() == other.getColumnSize() && other.getRowSize() == this->getRowSize();
    }

    /**
     * Можно ли умножить матрицы
     * @param other другая матрица
     * @return true, если действие разрешено
     */
    bool canMultiply(Matrix &other) {
        //(m x k1) (k1 x n)
        // =>
        return this->getColumnSize() == other.getRowSize();
    }

public:
    /***
     * Ctor
     * @param m кол-во столбцов
     * @param n кол-во строк
     */
    Matrix(int m, int n) {
        width = m;
        height = n;
        table = new double *[height];

        for (int i = 0; i < height; ++i) {
            table[i] = new double[width];

            // fill zeros
            for (int j = 0; j < width; ++j) {
                table[i][j] = 0;
            }
        }
    }


    /**
     * Всем элементам матрицы присвоить число
     * @param value значение
     * @return матрица
     */
    Matrix &operator=(double value);

    /**
     * Умножение матрицы на число
     * @param value значение
     * @return матрица
     */
    Matrix &operator*(double value);

    /**
     * Сложение матрицы на число
     * @param value значение
     * @return матрица
     */
    Matrix &operator+(double value);

    /**
     * Сложение матриц
     * @param value значение
     * @return матрица
     */
    Matrix &operator+(Matrix other);

    /**
     * Умножение матриц
     * @param value значение
     * @return матрица
     */
    Matrix &operator*(Matrix other);

    /**
     * Реализует A[i,j]
     * @param row индекс строки
     * @param column индекс колонки
     * @return значение
     */
    double get(int row, int column) {
        return table[row][column];
    }

    void set(int row, int column, double value) {
        table[row][column] = value;
    }

    /**
     * Получить размерность строк матрицы
     * @return значение
     */
    int getRowSize() {
        return height;
    }

    /**
     * Получить размерность столбцов матрицы
     * @return значение
     */
    int getColumnSize() {
        return width;
    }

    /**
     * Напечатать матрицу
     */
    void print();


};


#endif //MATRIX_SANDBOX_MATRIX_H
