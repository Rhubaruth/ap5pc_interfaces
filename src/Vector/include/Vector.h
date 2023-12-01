#include <AbstractEuclideanVector.h>
#include <iostream>
#include <cmath>

//Vytvoř třídu vektor, která implementuje výše 
//vytvořenou abstraktní třídu, vše potřebné, co říkají rozhraní, navíc výpis a floaty X,Y.
// NESMIME ZAPOMENOUT NA TO, ze Vector dedi Z AbstractEuclideanVector a ten ma interfacy ...
//a ty interfacy nas nuti pouzovat scalar a operator+ ... proto ho tu mam a mam ho
//i v c++ 
using namespace std;

class Vector : public AbstractEuclideanVector<Vector> {



public:
    float _x;
    float _y;

Vector(float x, float y) {
    _x = x;
    _y = y; 
}

    // function returning abstract class "Vector" is not allowed ... OBROVSKY BACHA na to, ze kdyz neimplementujeme 
    ///funkce z obou rozhrani, tak jsme v haji ... 
    //sčítání vektorů z interface
    Vector operator+(const Vector& other) const override {
        return Vector(_x + other._x, _y + other._y);
    }
    //scalar  z interface
    float scalar(const Vector &other) const {
        return _x * other._x + _y * other._y;
    }

    float norm () const {
        return sqrt(_x * _x +_y * _y);
    }




    friend ostream &operator<<(ostream &os, const Vector &other)
    {
    
        os << "(" << other._x << " " << other._y << ")";
        return os;
    }

};
