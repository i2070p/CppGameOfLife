/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ASCIIDisplay.h
 * Author: meti
 *
 * Created on 7 stycznia 2016, 00:24
 */

#ifndef ASCIIDISPLAY_H
#define ASCIIDISPLAY_H

#include "AbstractDisplay.h"
#include <unistd.h>
#include "Board.h"

class ASCIIDisplay : public AbstractDisplay {
public:

    void display(Solver* solver) {
        int delay = 100000; //[us]

        vector<Board*> history = solver->getHistory();
        Board *board = NULL;

        for (int i = 0; i < history.size(); i++) {

            cout << "Step: " << i << endl;
            board = history[i];

            for (int k = 0; k < board->getHeight(); k++) {
                for (int l = 0; l < board->getWidth(); l++) {
                    int value = board->getValue(k, l);
                    string sign = "░";
                    switch (value) {
                        case 0:
                            sign = ".";
                            break;
                        case 1:
                            sign = "█";
                            break;
                            /*case 2:
                                sign = "░";
                                break;
                            case 3:
                                sign = "@";
                                break;       
                            case 4:
                                sign = "+";
                                break;   */
                    }
                    cout << sign; //░
                }
                cout << endl;
            }

            usleep(delay);
        }

        cout << "Czas generowania stanów: " << solver->getTime() << endl;
    }
};

#endif /* ASCIIDISPLAY_H */

