#include "kakurasu.h"
#include <stdbool.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Board::Board(int n){ //Konstruktor
    dimension=n;
    int i,j;
    for (i=1;i<=dimension;i++){
        for (j=1;j<=dimension;j++){
            table[i][j]=8;
        }
    }
}

void Board::FileToBoard(int n){
/* Merepresentasikan inputan file txt ke dalam program */
    string line[n+2];
    int i=0,j;
    ifstream FileKakurasu;
    if (n==5){
        FileKakurasu.open("kakurasu5.txt",ios::in);
    } else if (n==6){
        FileKakurasu.open("kakurasu6.txt",ios::in);
    } else if (n==7){
        FileKakurasu.open("kakurasu7.txt",ios::in);
    } else if (n==8){
        FileKakurasu.open("kakurasu8.txt",ios::in);
    }
    if (FileKakurasu.is_open()){
        while (getline(FileKakurasu,line[i])){
            if (i<n+1){
                i++;
            }
        }
        FileKakurasu.close();
        for (i=1;i<=n;i++){
            if (line[i].length()==(n*3)+4){ //Jika tidak dua digit
                this->row[i]=line[i][(n*3)+3]-'0';
            } else { //Jika dua digit
                this->row[i]=(line[i][(n*3)+3]-'0')*10+line[i][(n*3)+4]-'0';
            }
        }
        for (j=1;j<=n;j++){
            if (line[n+1][(j*3)+1]==' '){ //Jika tidak dua digit
                this->col[j]=line[n+1][j*3]-'0';
            } else { //Jika dua digit
                this->col[j]=(line[n+1][j*3]-'0')*10+line[n+1][(j*3)+1]-'0';
            }
        }
    }
    else (cout << "Unable to open file!" << endl);
}

bool Board::finished(){
    bool finish=true;
    int i;
    for (i=1;i<this->dimension;i++){
        if ((sumCol(i)!=col[i])||(sumRow(i)!=row[i])){
            finish=false;
        }
    }
    return finish;
}

int Board::sumRow(int i){
    int sum=0;
    int j;
    for (j=1;j<=this->dimension;j++){
        if (table[i][j]==1) {
            sum=sum+table[i][j]*j;
        }
    }
    return sum;
}

int Board::sumCol(int j){
    int sum=0;
    int i;
    for (i=1;i<=this->dimension;i++){
        if (table[i][j]==1) {
            sum=sum+table[i][j]*i;
        }
    }
    return sum;
}

void Board::initRow(int i){
    int j;
    for (j=1;j<=this->dimension;j++){
        if (j>row[i]){
            table[i][j]=0;
        }
    }
}

void Board::initCol(int j){
    int i;
    for (i=1;i<=this->dimension;i++){
        if (i>col[j]){
            table[i][j]=0;
        }
    }
}

void Board::execRow(int i){
    int j;
    while (sumRow(i)!=row[i]){
        for (j=1;j<=this->dimension;j++){
            if (table[i][j]!=0){
                table[i][j]=1;
                if (sumRow(i)>row[i]){
                    if (j==1){
                        table[i][this->dimension]=8;
                    } else {
                        table[i][j-1]=8;
                    }
                }
            }
        }
    }
}

void Board::execCol(int j){
    int i;
    while (sumCol(j)!=col[j]){
        for (i=1;i<=this->dimension;i++){
            if (table[i][j]!=0){
                table[i][j]=1;
                if (sumCol(j)>col[j]){
                    if (i==1){
                        table[this->dimension][j]=8;
                    } else {
                        table[i-1][j]=8;
                    }
                }
            }
        }
    }
}

void Board::execution(){
    int i,j;
    while (!finished()){
        PrintToScreen();
        for (i=1;i<=this->dimension;i++){
            execRow(i);
            //PrintToScreen();
        }
        for (j=1;j<=this->dimension;j++){
            execCol(j);
            //PrintToScreen();
        }
    }
}

void Board::PrintToScreen(){
    int i,j;
    cout<<"   1  2  3  4  5  "<<endl;
    for (i=1;i<=this->dimension;i++){
        cout<<i<<"  ";
        for (j=1;j<=this->dimension;j++){
            cout<<table[i][j]<<"  ";
        }
        cout<<row[i]<<endl;
    }
    cout<<"   ";
    for (j=1;j<=this->dimension;j++){
        if (col[j]<10){
            cout<<col[j]<<"  ";
        } else {
            cout<<col[j]<<" ";
        }
    }
    cout<<endl;
}
