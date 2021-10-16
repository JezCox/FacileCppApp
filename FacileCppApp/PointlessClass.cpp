#include "PointlessClass.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <array>
#include <functional>
#include <set>

void SomewhatFacile::PointlessClass::IncAndWriteMember() 
{
	_intMember++;
	std::cout << "PointlessClass::_intMember = " << _intMember << std::endl;
}

void SomewhatFacile::PointlessClass::DecAndWriteMember()
{
	_intMember -= 4;
	std::cout << "PointlessClass::_intMember = " << _intMember << std::endl;
}


void SomewhatFacile::PointlessClass::UseStdMap()
{
	std::map<int, std::string> myMap;
	myMap.insert(std::pair<int, std::string>(1, "This is one"));
	myMap[2] = "This is two";

	std::map<int, std::string>::iterator it = myMap.find(2);
	std::cout << "At " << it->first << ": " << it->second << std::endl;

	myMap.insert(std::pair<int, std::string>(5, "And 5"));
	for (std::map<int, std::string>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		std::cout << iter->first << "-->" << iter->second << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;

	myMap.insert(std::pair<int, std::string>(20, "I'm 20"));
	for (auto& el : myMap)
	{
		std::cout << el.first << "-->" << el.second << std::endl;
	}

}

void SomewhatFacile::PointlessClass::StringAppending()
{
	std::string myStr;
	myStr.append("A preamble...");
	myStr += std::to_string(4);
	std::cout << "myStr:" << myStr << std::endl;

	int anotherInt = 56;
	std::ostringstream oss;
	oss << anotherInt;

	myStr.append(oss.str());

	std::cout << "myStr now: " << myStr << std::endl;
}

void SomewhatFacile::PointlessClass::VectorAlt()
{
	std::vector nums{ 1,2,3,4,5,6 };
	for (std::vector<int>::iterator it = begin(nums); it !=  end(nums); ++it)
	{
		std::cout << *it << std::endl;
	}
}


void SomewhatFacile::PointlessClass::UseGenerateN()
{

	std::vector<int> v;
	int i = 0;

	std::generate_n(std::back_inserter(v), 5, [&]() {return i++; });

	for (const auto& x : v)
	{
		std::cout << " " << x;
	}
	std::cout << std::endl;

	int total = std::accumulate(begin(v), end(v), 0);
	std::cout << "total:" << total << std::endl;

	int count4 = std::count(begin(v), end(v), 4);	// just one equal to 4
	std::cout << "count4:" << count4 << std::endl;

	// remove_if with erase
	auto v4 = v;
	auto endv4 = std::remove_if(begin(v4), end(v4), [](int elem) {return elem == 3; });
	v4.erase(endv4, end(v4));	// N.B. remove_if not enough
	std::for_each(begin(v4), end(v4), [](int elem) {std::cout << " " << elem; });

	// more usually
	//v4.erase(std::remove_if(begin(v4), end(v4), [](int elem) {return elem == 3; }), end(v4));	// remove_if with erase idiom

	bool allPositive = std::all_of(begin(v4), end(v4), [](int elem) {return elem >= 0; });
	std::cout << "v4 allPositive = " << allPositive << std::endl;

	v4.push_back(16);
	v4.push_back(10);
	v4.push_back(-6);
	std::cout << "v4:presort:";
	std::for_each(begin(v4), end(v4), [](int elem) {std::cout << " " << elem; });
	std::cout << std::endl;
	std::sort(begin(v4), end(v4));
	std::cout << "v4:postsort:";
	std::for_each(begin(v4), end(v4), [](int elem) {std::cout << " " << elem; });
	std::cout << std::endl;
}

void SomewhatFacile::PointlessClass::UseQueue()
{
	std::queue<std::string> aQueue;
	aQueue.push("humpty");
	aQueue.push("dumpty");
	aQueue.push("sat");
	aQueue.push("on");
	aQueue.push("a");
	aQueue.push("wall");

	while (!aQueue.empty()) 
	{
		std::cout << "->" << aQueue.front() << std::endl;
		aQueue.pop();
	}
}

void SomewhatFacile::PointlessClass::UseStack()
{
	std::stack<std::string> aStack;
	aStack.push("humpty");
	aStack.push("dumpty");
	aStack.push("sat");
	aStack.push("on");
	aStack.push("a");
	aStack.push("wall");

	while (!aStack.empty())
	{
		std::cout << "-->" << aStack.top() << std::endl;
		aStack.pop();
	}
}

void SomewhatFacile::PointlessClass::StringPlay()
{
	std::string aString = "This is a string";
	for (auto& c : aString)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;

	char ch8 = aString.at(8);
	std::cout << "At 8:" << ch8 << std::endl;
}

void SomewhatFacile::PointlessClass::ArrayPlay()
{
	int arrayOfInts[] = { 2, 3, 5, 8, 9 };
	for (int i = 0; i < sizeof(arrayOfInts)/sizeof(arrayOfInts[0]); ++i)
	{
		std::cout << arrayOfInts[i] << std::endl;
	}

	std::array<std::string, 3> strArray = { std::string("this"), "that", "the other" };
	for (int i = 0; i < strArray.size(); ++i)
	{
		std::cout << strArray[i] << std::endl;
	}
}


void SomewhatFacile::PointlessClass::MapSort()
{
	std::map<std::string, int> aMap{
		{"aaa", 5},
		{"bbb", 2},
		{"ggg", 6},
		{"ccc", 1}
	};

	for (const auto& kv : aMap)
	{
		std::cout << kv.first << "--" << kv.second << std::endl;
	}
	std::cout << "--------------------------" << std::endl;

	typedef std::function<int(int, int)> Takes2IntsAndReturnsInt;
	Takes2IntsAndReturnsInt someLambda = [](int x, int y) {return x + y; };
	typedef std::function<std::string(std::string, std::string, std::string)> Takes3StringsAndReturnsAString;
	Takes3StringsAndReturnsAString someLambda2 = [](std::string s1, std::string s2, std::string s3)
	{
		return s1.substr(0, 2) + s2 + s3;
	};


	typedef std::function<bool(std::pair<std::string, int>, std::pair <std::string, int>)> CompFn;
	CompFn sortDescLambda = [](std::pair<std::string, int> el1, std::pair<std::string, int> el2)
	{
		return (el1.second > el2.second);
	};
	CompFn sortAscLambda = [](std::pair<std::string, int> el1, std::pair<std::string, int> el2)
	{
		return (el1.second < el2.second);
	};


	std::set<std::pair<std::string, int>, CompFn > setSortedDesc{ aMap.begin(), aMap.end(),  sortDescLambda };
	for (const auto& p : setSortedDesc) {
		std::cout << p.first << "-->" << p.second << std::endl;
	}
	std::cout << "--------------------------" << std::endl;

	std::set<std::pair<std::string, int>, CompFn> setSortedAsc(aMap.begin(), aMap.end(), sortAscLambda);
	for (const auto& p : setSortedAsc) {
		std::cout << p.first << "-->" << p.second << std::endl;
	}
}


//void SomewhatFacile::PointlessClass::TryoutTemp()
//{
//	using namespace std;
//	int n, q;
//	char space;
//	cin >> n >> q;
//	int** a = new int* [n];
//	string line;
//	getline(cin, line);
//	for (int i = 0; i < n; i++)
//	{
//		vector<int> vArray;
//		string line;
//		int arrSize;
//		cin >> arrSize;
//		for (int j = 0; j < arrSize; ++j)
//		{
//			int num;
//			cin >> num;
//			vArray.push_back(num);
//		}
//
//		a[i] = new int[vArray.size()];
//		int k = 0;
//		for (vector<int>::iterator it = vArray.begin(); it != vArray.end(); ++it)
//		{
//			a[i][k] = *it;
//			k++;
//		}
//
//	}
//
//	for (int idx = 0; idx < q; ++idx)
//	{
//		int i, j;
//		cin >> i >> j;
//		cout << a[i][j] << endl;
//	}
//}