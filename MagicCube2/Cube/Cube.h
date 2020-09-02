//
// Created by art on 9/2/20.
//

#ifndef MAGICCUBE2_CUBE_H
#define MAGICCUBE2_CUBE_H


#include <string>

class Cube {
private:
    short **matrix;   ///< Main Matrix
    int size;         ///< Cube dimensions
    const short white = 1, yellow = 2, red = 3, orange = 4, blue = 5, green = 6;

public:

    void rotateMatrix(short **matrix);

    // Положить кубик на бок (правый или левый)
    ///\brief Put a cube on the side
    ///\param direction if true - put on the right side; false - on the left
    void putOnTheSide(bool direction);

    // Тот самый поворот цветов вокруг центра, но только для левой и право сторон
    ///\brief Rotate of the side elements;
    ///\details Rotation of colors around an axis
    ///\param direction true - clockwise; false - anticlockwise
    void rotateSide(bool direction, bool side);

    ///\brief Constructor
    ///\param n Cube dimensions
    Cube(int n);

    // Просто поворот слоя вертикально. Самое простое, что было...................
    ///\brief Rotate the vertical layer
    ///\param number number of the layer
    ///\param direction rotating direction: true - up, false - down
    void rotateLayer(int number, bool direction);

    //Те самые повороты, из-за которых нужно крутить цвета
    ///\brief Rotate the Cube vertically
    ///\param direction rotating direction: true - up, false - down
    void rotateCubeVertically(bool direction);

    //Те самые повороты, из-за которых нужно крутить цвета
    ///\brief Rotate the Cube horizontally
    ///\param direction rotating direction: true - right, false - left
    void rotateCubeHorizontally(bool direction);

    ///\brief Get color at indexes i,j
    ///\param i row number
    ///\param j column number
    ///\return color at matrix[i][j]
    short getColor(int i, int j) const;

    ///\brief Getter for size;
    ///\return size
    int getSize() const;

    ///\brief Converts the matrix to a string
    std::string print()const;

};


#endif //MAGICCUBE2_CUBE_H
