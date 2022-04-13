/**

 *
 * AUTHORS: Nerya Bigon
 * // got a lot of help from this youtube chanel - https://www.youtube.com/c/TheChernoProject
 * 
 * // and from this video - https://www.youtube.com/watch?v=eH1CxEC29l8

 */

#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace zich;

TEST_CASE("invalid inputs")
{

    SUBCASE("invalid Matrix size")
    {
        vector<double> matValue_1 = {5, 6, 8, 2, 7, 4, 1, 7, 9};
        Matrix mat1(matValue_1, 3, 3);
        vector<double> matValue_2 = {5, 6, 8, 2, 7, 4, 1, 7, 9, 8, 9, 3};
        Matrix mat2(matValue_2, 4, 3);
        bool none;
        CHECK_THROWS(mat1 + mat2);
        CHECK_THROWS(mat1 - mat2);
        CHECK_THROWS(mat1 * mat2);
        CHECK_THROWS(mat1 += mat2);
        CHECK_THROWS(mat1 -= mat2);
        CHECK_THROWS(mat1 *= mat2);
        CHECK_THROWS(none = mat1 == mat2);
        CHECK_THROWS(none = mat1 != mat2);
        CHECK_THROWS(none = mat1 > mat2);
        CHECK_THROWS(none = mat1 < mat2);
        CHECK_THROWS(none = mat1 <= mat2);
        CHECK_THROWS(none = mat1 >= mat2);
    }
}

TEST_CASE ("valid inputs") {

    SUBCASE("operators ERROR") {
        vector<double> matValue_1 = {5, 6, 8, 2, 7, 4, 1, 7, 9};
        Matrix mat1(matValue_1, 3, 3);
        vector<double> matValue_2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        Matrix mat2(matValue_2, 3, 3);
        bool none;
        CHECK_NOTHROW(mat1 + mat2);
        CHECK_NOTHROW(mat1 - mat2);
        CHECK_NOTHROW(mat1 * mat2);
        CHECK_NOTHROW(mat1 += mat2);
        CHECK_NOTHROW(mat1 -= mat2);
        CHECK_NOTHROW(mat1 *= mat2);
        CHECK_NOTHROW(none = mat1 == mat2); 
        CHECK_NOTHROW(none = mat1 != mat2);
        CHECK_NOTHROW(none = mat1 > mat2);
        CHECK_NOTHROW(none = mat1 < mat2);
        CHECK_NOTHROW(none = mat1 <= mat2);
        CHECK_NOTHROW(none = mat1 >= mat2);
    }
}