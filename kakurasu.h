#ifndef KAKURASU_H
#define KAKURASU_H
#include <stdbool.h>
class Board{
public:
    int dimension;
    int table[12][12];
    int col[12];
    int row[12];
    Board(int);
    bool finished();
    int sumCol(int);
    int sumRow(int);
    void initCol(int);
    void initRow(int);
    void execCol(int);
    void execRow(int);
    void execution();
    void FileToBoard(int);
    void PrintToScreen();
    /*int valCol(int);
    int valRow(int);*/
};
#endif // KAKURASU_H
