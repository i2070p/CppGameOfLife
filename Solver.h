/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Solver.h
 * Author: meti
 *
 * Created on 6 stycznia 2016, 21:45
 */

#ifndef SOLVER_H
#define SOLVER_H

#ifndef THRD_NUM
#define THRD_NUM 1
#endif

#include "Board.h"
#include <vector>
#include <sstream>
#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class Solver {
public:

    Solver(Board *startBoard, int steps) {
        solve(startBoard, steps);
    }

    ~Solver() {
        for (int i = 0; i < history.size(); i++) {
            history[i]->~Board();
        }
    };

    vector<Board*> getHistory() {
        return history;
    }

    Board* getLastStep() {
        return history[history.size() - 1];
    }

    double getTime() {
        return time;
    }

protected:
    vector<Board*> history;
    double time;

private:

    void solve(Board *startBoard, int steps) {

        Board *currentBoard = startBoard;
        history.push_back(currentBoard);
        double start = omp_get_wtime();

        for (int step = 0; step < steps; step++) {
            currentBoard = solveBoard(currentBoard);

            history.push_back(currentBoard);
        }

        time = omp_get_wtime() - start;
    }

    /*
     * Niestety z powodów wydajnościowych trzeba to było rożłożyć na części pierwsze
     * (wyciąganie tablic z obiektow, vector -> array itp...)
     */
    Board* solveBoard(Board *board) {

        int boardHeight = board->getHeight(), boardWidth = board->getWidth();

        int **newBoardArray = Utils::create2DArrayOfInt(boardHeight, boardWidth);
        int **boardArray = board->getBoard();

        int i = 0, j = 0, k = 0, l = 0, neighborCount, element;

#pragma omp parallel for shared(boardArray, newBoardArray, boardHeight, boardWidth) private(i, j, k, l, neighborCount, element) num_threads(THRD_NUM)
        for (i = 0; i < boardHeight; i++) {
            for (j = 0; j < boardWidth; j++) {
                neighborCount = 0;
                element = boardArray[i][j];

                for (k = i - 1; k <= i + 1; k++) {
                    for (l = j - 1; l <= j + 1; l++) {
                        if (!(k == i && l == j)) {
                            if (k >= 0 && k < boardHeight && l >= 0 && l < boardWidth) {
                                int value = boardArray[k][l];
                                neighborCount += (value == 1) ? 1 : 0;
                            }
                        }
                    }
                }
               
                if (element != 0 && element != 2) {
                    if (!(neighborCount == 2 || neighborCount == 3)) {
                        element = 2;
                    }

                } else {
                    if (neighborCount == 3) {
                        element = 1;
                    }
                }
                newBoardArray[i][j] = element;
            }
        }

        return new Board(boardHeight, boardWidth, newBoardArray);
    }
};

#endif /* SOLVER_H */

