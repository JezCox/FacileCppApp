#include <iostream>
#include "PointlessClass.h"

int main()
{
    std::cout << "Purely for testing that I can commit a VS project to GutHub!\n";
    PointlessClass pc;
    pc.IncAndWriteMember();
    pc.DecAndWriteMember();

    return 1;
}
