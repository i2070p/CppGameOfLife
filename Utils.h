/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.h
 * Author: meti
 *
 * Created on 6 stycznia 2016, 18:13
 */

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include "stdio.h"
#include "WindowsBitmap.h"

using namespace std;

class Utils {
public:

    static int** create2DArrayOfInt(int height, int width) {
        int **result = new int*[height];
        for (int i = 0; i < height; i++) {
            result[i] = new int[width];
        }

        return result;
    }

    static unsigned char* loadBitmapFile(const char *filename, BITMAPINFOHEADER *bitmapInfoHeader) {

        FILE *filePtr;
        BITMAPFILEHEADER bitmapFileHeader;
        unsigned char *bitmapImage;
        int imageIdx = 0;

        filePtr = fopen(filename, "rb");
        if (filePtr == NULL)
            return NULL;

        fread(&bitmapFileHeader, sizeof (BITMAPFILEHEADER), 1, filePtr);

        fread(bitmapInfoHeader, sizeof (BITMAPINFOHEADER), 1, filePtr);

        fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

        bitmapImage = (unsigned char*) malloc(bitmapInfoHeader->biSizeImage);

        if (!bitmapImage) {
            free(bitmapImage);
            fclose(filePtr);
            return NULL;
        }

        fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
        if (bitmapImage == NULL) {
            fclose(filePtr);
            return NULL;
        }

        fclose(filePtr);
        return bitmapImage;
    }

};

#endif /* UTILS_H */

