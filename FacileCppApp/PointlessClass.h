#pragma once

class PointlessClass {
public:
	PointlessClass() = default;
	void IncAndWriteMember();
	void DecAndWriteMember();

private:
	int _intMember = 6;

};