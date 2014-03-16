#pragma once

#include <fstream>
#include "arrayspiraldisplayer.h"

using std::fstream;

class FileDisplayer : public ArraySpiralDisplayer
{
public:
    void displaySpiral(int **array, unsigned int arraySize);
};
