#include <iostream>
#include "Cube3.h"

int main() {
    /* Todo
     * Сдался на вращении кубика в пространстве
     * Скорее всего, не понял твою идею
     * Возникла проблемы с вращением цветов вокруг центра при повороте кубика, а отсюда
     * проблема с повротами сторон, которые выражаются через повороты кубика (F, B, U, D)
     *
     * По сути, нормально работают только:
     * конструктор
     * повороты L и R
     * вывод
     * */
    Cube3 cb3;
    std::cout << cb3.print();
    cb3.L();
    cb3.putOnTheSide(true);
    std::cout << std::endl << cb3.print();
    return 0;
}
