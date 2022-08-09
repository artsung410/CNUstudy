#include "Set.h"
#include <initializer_list>
#include <iostream>

using namespace std;

int main()
{
	auto initList = { 10, 5, 1, 6, 17, 14, 21 };

	Set s;
	for (int elem : initList)
	{
		s.insert(elem);
	}
	
	cout << "������ȸ\n";
	s.traverseByPreorder();
	cout << endl;
	cout << endl;

	cout << "������ȸ\n";
	s.traverseByInorder();
	cout << endl;
	cout << endl;

	cout << "������ȸ\n";
	s.traverseByPostorder();
	cout << endl;
	cout << endl;

	cout << "������ȸ\n";
	s.traverseByLevelorder();
	cout << endl;

	/*Set s;

	for (int i = 0; i < 5; i++)
	{
		s.insert(i);
	}*/

	std::cout << s.height() << " " << s.height2();

}