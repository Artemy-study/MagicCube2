//
// Created by art on 9/2/20.
//

#include "Cube3.h"

Cube3::Cube3() : Cube(3){}

bool Cube3::command(std::string commands) {
    short times;
    bool isInverse;
    for (int i = 0; i < commands.size(); ++i) {
        times = 1;
        isInverse = false;
        if (commands[i] != ' ') {
            if (commands[i] == '2') {
                times = 2;
                i++;
            }
            if (commands[i + 1] == '\'') isInverse = true;
            switch (commands[i]) {
                case 'F': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?F_():F();
                    }
                    break;
                }
                case 'B': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?B_():B();
                    }
                    break;
                }
                case 'L': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?L_():L();
                    }
                    break;
                }
                case 'R': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?R_():R();
                    }
                    break;
                }
                case 'U': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?U_():U();
                    }
                    break;
                }
                case 'D': {
                    for (int j = 0; j < times; ++j) {
                        isInverse?D_():D();
                    }
                    break;
                }
                default:
                    return false;
            }
            while (commands[i] != ' ' && i < commands.size())i++;
        }
    }
    return true;
}

void Cube3::U() {
    putOnTheSide(true);
    rotateLayer(2, true);
    putOnTheSide(false);
}

void Cube3::U_() {
    putOnTheSide(true);
    rotateLayer(2, false);
    putOnTheSide(false);
}

void Cube3::D() {
    putOnTheSide(true);
    rotateLayer(0, false);
    putOnTheSide(false);
}

void Cube3::D_() {
    putOnTheSide(true);
    rotateLayer(0, false);
    putOnTheSide(false);
}

void Cube3::R() {
    rotateLayer(2, true);
}

void Cube3::R_() {
    rotateLayer(2, false);

}

void Cube3::L() {
    rotateLayer(0, false);
}

void Cube3::L_() {
    rotateLayer(0, true);
}

void Cube3::F() {
    rotateCubeHorizontally(true);
    rotateLayer(0, false);
    rotateCubeHorizontally(true);
}

void Cube3::F_() {
    rotateCubeHorizontally(true);
    rotateLayer(0, false);
    rotateCubeHorizontally(false);
}

void Cube3::B() {
    rotateCubeHorizontally(true);
    rotateLayer(2, false);
    rotateCubeHorizontally(true);
}

void Cube3::B_() {
    rotateCubeHorizontally(true);
    rotateLayer(2, false);
    rotateCubeHorizontally(false);
}

