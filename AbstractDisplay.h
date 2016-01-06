/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractDisplay.h
 * Author: meti
 *
 * Created on 7 stycznia 2016, 00:23
 */

#ifndef ABSTRACTDISPLAY_H
#define ABSTRACTDISPLAY_H

#include "Solver.h"

class AbstractDisplay {
public:
    virtual void display(Solver* solver) = 0;
};

#endif /* ABSTRACTDISPLAY_H */

