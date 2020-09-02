//
// Created by art on 9/2/20.
//

#include "Cube.h"

Cube::Cube(int n) {
    matrix = new short *[4 * n];
    for (int i = 0; i < 4 * n; ++i) {
        matrix[i] = new short[3 * n];
        for (int j = 0; j < 3 * n; ++j) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            matrix[i][j] = yellow;
        }
        for (int j = n; j < 2 * n; ++j) {
            matrix[i + n][j] = red;
        }
        for (int j = n; j < 2 * n; ++j) {
            matrix[i + 2 * n][j] = white;
        }
        for (int j = n; j < 2 * n; ++j) {
            matrix[i + 3 * n][j] = orange;
        }
    }

    for (int i = 2 * n; i < 3 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = blue;
        }
        for (int j = 2 * n; j < 3 * n; ++j) {
            matrix[i][j] = green;
        }
    }

    size = n;
}

void Cube::rotateLayer(int number, bool direction) {
    short temp;
    if (direction) {
        for (int i = 0; i < size; ++i) {
            temp = matrix[0][size + number];
            for (int j = 0; j < 4 * size - 1; ++j) {
                matrix[j][size + number] = matrix[j + 1][size + number];
            }
            matrix[4 * size - 1][size + number] = temp;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            temp = matrix[4 * size - 1][size + number];
            for (int j = 4 * size - 1; j > 0; --j) {
                matrix[j][size + number] = matrix[j - 1][size + number];
            }
            matrix[0][size + number] = temp;
        }
    }
    if (number == 0) rotateSide(direction, false);
    else if (number == size - 1) rotateSide(direction, true);
}

void Cube::rotateCubeVertically(bool direction) {
    for (int i = 0; i < size; ++i) {
        rotateLayer(i, direction);
    }
    rotateSide(direction, true);
    rotateSide(direction, false);
}

void Cube::rotateCubeHorizontally(bool direction) {
    putOnTheSide(true);
    for (int i = 0; i < size; ++i) {
        rotateLayer(i, !direction);
    }
    putOnTheSide(false);
}

void Cube::putOnTheSide(bool direction) {
    short **temp;
    temp = new short *[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = new short[size];
        for (int j = 0; j < size; ++j) {
            temp[i][j] = matrix[size + i][size + j];
        }
    }
    if (direction) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[size + i][size + j] = matrix[2 * size + i][2 * size + j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][2 * size + j] = matrix[3 * size + i][size + j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[3 * size + i][size + j] = matrix[2 * size + i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][j] = temp[i][j];
            }
        }
    } else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[size + i][size + j] = matrix[2 * size + i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][j] = matrix[3 * size + i][size + j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[3 * size + i][size + j] = matrix[2 * size + i][2 * size + j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[2 * size + i][2 * size + j] = temp[i][j];
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
}

short Cube::getColor(int i, int j) const {
    return matrix[i][j];
}

int Cube::getSize() const {
    return size;
}

std::string Cube::print() const {
    std::string result;
    for (int i = 0; i < 4 * size; ++i) {
        for (int j = 0; j < 3 * size; ++j) {
            result += std::to_string(matrix[i][j]) + "  ";
        }
        result += '\n';
    }
    return result;
}

void Cube::rotateSide(bool direction, bool side) {
    short **original = new short *[size];

    if (side) {
        for (int k = 0; k < size; ++k) {
            original[k] = new short[size];
            for (int i = 0; i < size; ++i) {
                original[k][i] = matrix[2 * size + k][i];
            }
        }
        if (direction) {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    matrix[3 * size - 1 - j][i] = original[i][j];
                }
            }
        } else {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    matrix[3 * size - 1 - j][size - 1 - i] = original[i][j];
                }
            }
        }
    } else {
        for (int k = 0; k < size; ++k) {
            original[k] = new short[size];
            for (int i = 0; i < size; ++i) {
                original[k][i] = matrix[2 * size + k][2 * size + i];
            }
        }
        if (direction) {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    matrix[3 * size - 1 - j][2 * size + i] = original[i][j];
                }
            }
        } else {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    matrix[3 * size - 1 - j][3 * size - 1 - i] = original[i][j];
                }
            }
        }
    }

    for (int l = 0; l < 3; ++l) {
        delete[] original[l];
    }
    delete[] original;
}

void Cube::rotateMatrix(short **matrix) {
    short **original = new short *[size];
    for (int i = 0; i <size; ++i) {
        original[i] = new short[size];
        for (int j = 0; j < size; ++j) {
            original[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[j][size - 1 - i] = original[i][j];
        }
    }
}
