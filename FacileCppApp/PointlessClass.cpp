#include "PointlessClass.h"
#include <iostream>

void PointlessClass::IncAndWriteMember() 
{
	_intMember++;
	std::cout << "PointlessClass::_intMember = " << _intMember << std::endl;
}

void PointlessClass::DecAndWriteMember()
{
	_intMember -= 4;
	std::cout << "PointlessClass::_intMember = " << _intMember << std::endl;
}
