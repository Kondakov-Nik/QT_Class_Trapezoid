// Вычисление объёма куба и площади его боковой поверхности
// @author Кондакаков Н.С.

#include "calc.h"


/// получить сторону куба
float Cube::getA() const{
    return a;
}

/// задать сторону куба
void Cube::setA(float newA){
    if (newA <= 0)
        throw std::invalid_argument("");
    a = newA;
}

/// вычисление объема куба
float Cube::v_kub(){
    return a*a*a;
}

/// вычисление площади боковой поверхности куба
float Cube::s_kub() {
    return 6*(a*a);
}

Cube::Cube()
{
    a = 0;
}

Cube::Cube(float a1)
{
    setA(a1);
}
