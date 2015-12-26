#include "kakurasu.h"
#include <iostream>
#include <stdbool.h>
#include <string>
#include <fstream>
using namespace std;

int main(){
    int i,j;
    Board B(5);
    B.FileToBoard(5);
    for (i=1;i<=B.dimension;i++){
        B.initRow(i);
    }
    for (j=1;j<=B.dimension;j++){
        B.initCol(j);
    }
    B.execRow(1);
    //B.execRow(2);
    //B.execution();
    B.PrintToScreen();
    return 0;
}
