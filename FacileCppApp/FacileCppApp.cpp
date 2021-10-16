#include <iostream>
#include "PointlessClass.h"

using namespace SomewhatFacile;

int main()
{
    std::cout << "Purely for testing that I can commit a VS project to GutHub!\n";
    PointlessClass pc;
    pc.IncAndWriteMember();
    pc.DecAndWriteMember();

    pc.UseStdMap();
    pc.StringAppending();
    pc.VectorAlt();
    pc.UseGenerateN();
    pc.UseQueue();
    pc.UseStack();
    pc.StringPlay();
    pc.ArrayPlay();
    pc.MapSort();
    //pc.TryoutTemp();



    return 1;
}
