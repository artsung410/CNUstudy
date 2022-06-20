#include <forward_list>
#include <iostream>

//��带 ����?

using namespace std;

void FlistPrint(std::forward_list<int> flist)
{
	for (std::forward_list<int>::iterator iter = flist.begin(); iter != flist.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::forward_list<int> flist;

	flist.push_front(1); // �Ǿջ���

	//FlistPrint(flist);

	flist.insert_after(flist.begin(), 2); // pos���� �� ����

	flist.push_front(5); // �Ǿ� ����

	FlistPrint(flist);

	if (!flist.empty())
	{
		std::cout << "flist is not empty" << std::endl;
	}

	std::forward_list<int>::iterator iter;

	//iter = flist.before_begin(); 
	// cout << *iter << endl; => ��۸������� ��ȯ�Ѵ�
	
	std::cout << flist.front() << std::endl;

	std::forward_list flist3 = { 5, 43, 2, 8, 10 };
	flist3.pop_front();
	FlistPrint(flist3);

	flist3.push_front(7);
	FlistPrint(flist3);

	//flist3.sort();
	flist3.swap(flist);
	FlistPrint(flist3);

}