/**
 * got a lot of help from this youtube chanel - https://www.youtube.com/c/TheChernoProject
 * for example from this video - https://www.youtube.com/watch?v=9RJTQmK0YPI
 * and for example from this video - https://www.youtube.com/watch?v=mS9755gF66w&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=40
 * 
 */


#include <iostream>
#include <vector>


namespace zich {
    class Matrix {
    private:
        int row, column;
        std::vector<double> mat;

        int matrixSummer() const; // to sum a matrix 

    public:
        Matrix(std::vector<double> matValues, int r, int c);
        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator*(const Matrix &other) const;
        Matrix operator*(double number) const;
        Matrix operator-();
        Matrix operator+();
        Matrix &operator++(); 
        Matrix operator++(int); 
        Matrix &operator--(); 
        Matrix operator--(int); 
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix &operator*=(const Matrix &other);
        Matrix &operator*=(double number);
        bool operator==(const Matrix &other) const;
        bool operator!=(const Matrix &other) const;
        bool operator>=(const Matrix &other) const;
        bool operator<=(const Matrix &other) const;
        bool operator<(const Matrix &other) const;
        bool operator>(const Matrix &other) const;
        friend Matrix operator*(int number, Matrix mat);
        friend std::istream &operator>>(std::istream &input, Matrix &mat);
        friend std::ostream &operator<<(std::ostream &output, const Matrix &mat);
    };

}
