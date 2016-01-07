/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: meti
 *
 * Created on 6 stycznia 2016, 18:12
 */
#define THRD_NUM 4

#include <cstdlib>
#include "Board.h"
#include <vector>
#include "Solver.h"
#include "ASCIIDisplay.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc != 3) {
        cout << "Poprawne wywolanie: " << argv[0] << " nazwa_pliku.bmp liczba_krokow" << argc << endl;

        return 0;
    }

    int steps = atoi(argv[2]);

    Board *board = new Board(string(argv[1]));
    Solver *solver = new Solver(board, steps);
    
    AbstractDisplay *display = new ASCIIDisplay();
    
    display->display(solver);

    return 0;
}

