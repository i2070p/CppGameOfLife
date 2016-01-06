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

class ASCIIDisplay : public AbstractDisplay {
public:

    void display(Solver* solver) {
        int delay = 250000; //[us]

        vector<Board*> history = solver->getHistory();

        for (int i = 0; i < history.size(); i++) {
            cout << "Step: " << i << endl << history[i]->toString() << endl;
            usleep(delay);
        }
    }
};

#endif /* ASCIIDISPLAY_H */

