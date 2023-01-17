// Вычисление объёма куба и площади его боковой поверхности
// @author Кондакаков Н.С.

#ifndef CALC_H
#define CALC_H

#include <stdexcept>

///  класс куб
class Cube{
    float a;        /// сторона куба

public:

    Cube();
    Cube(float a1);

    float getA() const;
    void setA(float newA);

    float v_kub(); /// объёма куба
    float s_kub(); /// площадь боковой поверхности куба
};

#endif
