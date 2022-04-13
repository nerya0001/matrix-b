/**
 * got a lot of help from this youtube chanel - https://www.youtube.com/c/TheChernoProject
 * for example from this video - https://www.youtube.com/watch?v=mS9755gF66w&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=40
 * 
 */


#include <iostream>
#include "Matrix.hpp"
#include <string>
#include <vector>

namespace zich
{

    /**
     * @brief this function sum the matrix 
     * 
     * @return int 
     */
    int Matrix::matrixSummer() const {

        int counter = 0;
        for (size_t i = 0; i < this->row * this->column; ++i) {
            counter += this->mat[i];
        }
        return counter;
    }

    /**
     * @brief function to check if the validity of the input 
     * 
     * @goal to not get thrown out by exaption
     * 
     * @param inputMat (string)
     */
    void inputCheck(std::string inputMat) {

        bool flag = false; // to check where we are in the input
        for (size_t i = 0; i < inputMat.length(); ++i) {
            if ((inputMat[i] == ']' && !flag) || (inputMat[i] == '[' && flag)) {
                throw std::invalid_argument("invalid input");
            }
            if (inputMat[i] == ']' && flag) {
                flag = false;
            }
            if (inputMat[i] == '[') {
                flag = true;
            }
            if ((inputMat[i] == ',' && inputMat[i - 1] != ']') || (inputMat[i] == ',' && inputMat[i + 1] != ' ')) {
                throw std::invalid_argument("invalid input!");
            }
        }
    }

    /**
     * @brief Construct a new Matrix:: Matrix object
     * 
     * @param matValues 
     * @param row 
     * @param column 
     */
    Matrix::Matrix(std::vector<double> matValues, int row, int column) {

        if (row < 1 || column < 1 || matValues.size() != row * column) {
            throw std::invalid_argument("matrix too small");
        }
        this->row = row;
        this->column = column;
        this->mat.resize((size_t)row * (size_t)column);
        for (size_t i = 0; i < row * column; ++i) {
            this->mat[i] = matValues[i];
        }
    }

    /**
     * @brief sum of two matrices
     * 
     * @param other 
     * @return Matrix 
     */
    Matrix Matrix::operator+(const Matrix &other) const {

        if (other.row != this->row || other.column != this->column) {
            throw std::invalid_argument("matrix size not right");
        }
        std::vector<double> toAdd((size_t)(this->row * this->column));
        for (size_t i = 0; i < this->row * this->column; ++i) {
            toAdd[i] = mat[i] + other.mat[i];
        }
        return Matrix(toAdd, this->row, this->column);
    }

    /**
     * @brief difference of two matrices
     * 
     * @param other 
     * @return Matrix 
     */
    Matrix Matrix::operator-(const Matrix &other) const {

        if (other.row != this->row || other.column != this->column) {
            throw std::invalid_argument("matrix size not right");
        }
        std::vector<double> toSub((size_t)(this->row * this->column));
        for (size_t i = 0; i < this->row * this->column; ++i) {
            toSub[i] = mat[i] - other.mat[i];
        }
        return Matrix(toSub, this->row, this->column);
    }

    /**
     * @brief matrix scalar multiplication
     * 
     * @param number 
     * @return Matrix 
     */
    Matrix Matrix::operator*(double number) const {

        std::vector<double> toMultiply((size_t)(this->row * this->column));
        for (size_t i = 0; i < this->row * this->column; ++i) {
            toMultiply[i] = this->mat[i] * number;
        }
        return Matrix(toMultiply, this->row, this->column);
    }

    /**
     * @brief matrix multiplication
     * 
     * @param other 
     * @return Matrix 
     */
    Matrix Matrix::operator*(const Matrix &other) const {

        if (this->column != other.row) {
            throw std::invalid_argument("matrix size not right");
        }
        std::vector<double> toMultiply((size_t)(this->row * other.column));

        for (size_t i = 0; i < this->row; ++i) {
            for (size_t j = 0; j < other.column; ++j) {
                toMultiply[i * (size_t)other.column + j] = 0;
                for (size_t k = 0; k < other.row; ++k) {
                    toMultiply[i * (size_t)other.column + j] += this->mat[i * (size_t)this->column + k] * other.mat[k * (size_t)other.column + j];
                }
            }
        }
        return Matrix(toMultiply, this->row, other.column);
    }

    /**
     * @brief unary negation
     * 
     * @return Matrix 
     */
    Matrix Matrix::operator-() {

        std::vector<double> subUnary((size_t)(this->row * this->column));
        for (size_t i = 0; i < this->row * this->column; ++i) {
            if (this->mat[i] == 0) {
                continue;
            }
            subUnary[i] = this->mat[i] * -1;
        }
        return Matrix(subUnary, this->row, this->column);
    }

    /**
     * @brief unary positive
     * 
     * @return Matrix 
     */
    Matrix Matrix::operator+() {
        return *this;
    }

    /**
     * @brief increment a matrix
     * 
     * @return Matrix& 
     */
    Matrix &Matrix::operator++() {
        for (size_t i = 0; i < this->row * this->column; ++i) {
            this->mat[i] += 1;
        }
        return *this;
    }

    /**
     * @brief increment a matrix
     * 
     * @return Matrix 
     */
    Matrix Matrix::operator++(int) {
        // pretty much a deep copy
        Matrix copy(this->mat, this->row, this->column); 
        for (uint i = 0; i < this->row * this->column; ++i) {
            this->mat[i] += 1;
        }
        return copy;
    }

    /**
     * @brief decrement a matrix
     * 
     * @return Matrix& 
     */
    Matrix &Matrix::operator--() {

        for (uint i = 0; i < this->row * this->column; ++i) {
            this->mat[i] -= 1;
        }
        return *this;
    }

    /**
     * @brief decrement a matrix
     * 
     * @return Matrix& 
     */
    Matrix Matrix::operator--(int) {

        Matrix copy(this->mat, this->row, this->column); 
        for (size_t i = 0; i < this->row * this->column; ++i) {
            this->mat[i] -= 1;
        }
        return copy;
    }

    /**
     * @brief augmented addition
     * 
     * @param other 
     * @return Matrix& 
     */
    Matrix &Matrix::operator+=(const Matrix &other) {

        if (other.row != this->row || other.column != this->column) {
            throw std::invalid_argument("matrix size not right");
        }
        for (size_t i = 0; i < this->row * this->column; ++i) {
            this->mat[i] += other.mat[i];
        }
        return *this;
    }

    /**
     * @brief augmented subtraction
     * 
     * @param other 
     * @return Matrix& 
     */
    Matrix &Matrix::operator-=(const Matrix &other) {

        if (other.row != this->row || other.column != this->column) {
            throw std::invalid_argument("matrix size not right");
        }
        for (size_t i = 0; i < this->row * this->column; ++i) {
            this->mat[i] -= other.mat[i];
        }
        return *this;
    }

    /**
     * @brief augmented matrix multiplication
     * 
     * @param other 
     * @return Matrix& 
     */
    Matrix &Matrix::operator*=(const Matrix &other) {

        if (this->column != other.row) {
            throw std::invalid_argument("matrix size not right");
        }
        *this = *this*other;
        return *this;
    }

    /**
     * @brief augmented scalar multiplication
     * 
     * @param number 
     * @return Matrix& 
     */
    Matrix &Matrix::operator*=(double number) {

        for (size_t i = 0; i < this->row * this->column; ++i) {
            if (this->mat[i] == 0) {
                continue;
            }
            this->mat[i] *= number;
        }
        return *this;
    }

    /**
     * @brief equals
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool Matrix::operator==(const Matrix &other) const {

        if (other.row != this->row || other.column != this->column) {

            throw std::invalid_argument("matrix size not right");
        }
        for (size_t i = 0; i < this->row * this->column; ++i) {
            if (this->mat[i] != other.mat[i]) {
                return false;
            }
        }
        return true;
    }


    /**
     * @brief not equals
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool Matrix::operator!=(const Matrix &other) const {

        if (other.row != this->row || other.column != this->column){
            throw std::invalid_argument("matrix size not right");
        }
        for (size_t i = 0; i < this->row * this->column; ++i) {
            if (this->mat[i] != other.mat[i]) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief greater than or equal to
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool Matrix::operator>=(const Matrix &other) const {

        if (other.row != this->row || other.column != this->column) {
            throw std::invalid_argument("matrix size not right");
        }
        return other.matrixSummer() <= this->matrixSummer();
    }

    /**
     * @brief less than or equal to
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool Matrix::operator<=(const Matrix &other) const {

        if (other.row != this->row || other.column != this->column) {
            throw std::invalid_argument("matrix size not right");
        }
        return other.matrixSummer() >= this->matrixSummer();
    }

    /**
     * @brief less than 
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool Matrix::operator<(const Matrix &other) const {

        if (other.row != this->row || other.column != this->column) {
            throw std::invalid_argument("matrix size not right");
        }
        return other.matrixSummer() > this->matrixSummer();
    }

    /**
     * @brief greater than 
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool Matrix::operator>(const Matrix &other) const {

        if (other.row != this->row || other.column != this->column) {
            throw std::invalid_argument("matrix size not right");
        }
        return other.matrixSummer() < this->matrixSummer();
    }

    /**
     * @brief matrix scalar multiplication when the scalar is on the left
     * 
     * @param number 
     * @param mat 
     * @return Matrix 
     */
    Matrix operator*(int number, Matrix mat) {

        std::vector<double> toMultiply((size_t)(mat.row * mat.column));
        for (size_t i = 0; i < mat.row * mat.column; ++i) {
            toMultiply[i] = mat.mat[i] * number;
        }
        return Matrix(toMultiply, mat.row, mat.column);
    }

    /**
     * @brief handle the input validity and parsing
     * 
     * @param input 
     * @param mat 
     * @return std::istream& 
     */
    std::istream &operator>>(std::istream &input, Matrix &mat) {

        std::string inputMat;
        std::getline(input, inputMat);
        inputCheck(inputMat);
        int row = 0;
         // check how many row by counting comas
        for (size_t i = 0; i < inputMat.size(); i++) {
            if (inputMat[i] == ',') {
                ++row;
            }
        }
        row++;

        std::vector<double> result;
        for (size_t i = 0, j = 0; i < inputMat.length(); j = ++i) {
            while (isdigit(inputMat[i]) != 0) {
                ++i;
            }
            if (i != j) {
                result.push_back(std::stod(inputMat.substr(j, i - j)));
            }
        }
        mat = Matrix(result, row, int(result.size()) / row);
        return input;
    }

    /**
     * @brief handle the output parsing
     * 
     * @param output 
     * @param mat 
     * @return std::ostream& 
     */
    std::ostream &operator<<(std::ostream &output, const Matrix &mat) {

        for (size_t i = 0; i < mat.row; ++i) {
            output << "[";
            for (size_t j = 0; j < mat.column; ++j) {
                output << mat.mat[(size_t)mat.column * i + j];
                if (j != mat.column - 1) {
                    output << " ";
                }
            }
            output << "]";
            if (i != mat.row - 1) {
                output << "\n";
            }
        }
        return output;
    }
}
