//
// Created by art on 9/2/20.
//

#ifndef MAGICCUBE2_CUBE3_H
#define MAGICCUBE2_CUBE3_H


#include <string>
#include "Cube/Cube.h"

class Cube3: public Cube{
public:
    Cube3();

    bool command(std::string commands);

    void U();
    void U_();
    void D();
    void D_();
    void R();
    void R_();
    void L();
    void L_();
    void F();
    void F_();
    void B();
    void B_();
};


#endif //MAGICCUBE2_CUBE3_H
