/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: meti
 *
 * Created on 6 stycznia 2016, 21:07
 */

#ifndef BOARD_H
#define BOARD_H

#include <sstream>
#include "Utils.h"

using namespace std;

class Board {
public:

    Board(int _height, int _width, int **_board) : height(_height), width(_width), board(_board) {

    }

    Board(string fileName) {
        loadBoard(fileName);
    }

    ~Board() {
    };

    void clear() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                board[i][j] = 0;
            }
        }
    }

    void setValue(int i, int j, int value) {
        if (i >= 0 && i < height && j >= 0 && j < width) {
            board[i][j] = value;
        }
    }

    int getValue(int i, int j) {
        if (i >= 0 && i < height && j >= 0 && j < width) {
            return board[i][j];
        }
        return 0;
    }
    
    int ** getBoard() {
        return board;
    }

    int getHeight() {
        return height;
    }

    int getWidth() {
        return width;
    }

protected:
    int height;
    int width;
    int **board;

private:

    void loadBoard(string fileName) {

        BITMAPINFOHEADER bitmapInfoHeader;

        unsigned char * bmp = Utils::loadBitmapFile(fileName.c_str(), &bitmapInfoHeader);

        width = bitmapInfoHeader.biWidth;
        height = bitmapInfoHeader.biHeight;
        int length = (int) (bitmapInfoHeader.biSizeImage / height);

        board = Utils::create2DArrayOfInt(height, width);

        for (int c = 0; c < height; c++) {
            for (int w = 0; w < width; w++) {
                int i = w * 3 + c * length;
                board[height - 1 - c][w] = (bmp[i] == 0 && bmp[i + 1] == 0 && bmp[i + 2] == 0) ? 0 : 1;
            }
        }
    };

};

#endif /* BOARD_H */

