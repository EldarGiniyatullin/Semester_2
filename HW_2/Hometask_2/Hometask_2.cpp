#include <iostream>
#include "arraysoft.h"
#include "consoledisplayer.h"
#include "filedisplayer.h"
#include "arrayspiraldisplayer.h"

using namespace std;

int main()
{
    int **array = randomArray(5);
    arrayPrinter(array, 5);
    ArraySpiralDisplayer *a = new ConsoleDisplayer;
    ArraySpiralDisplayer *b = new FileDisplayer;
    a->displaySpiral(array, 5);
    b->displaySpiral(array, 5);
    delete a;
    delete b;
    deleteArray(array, 5);
}


