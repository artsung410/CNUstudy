#include <unordered_map> // key������ hash value�� ã�µ� �ð��� ���԰ɸ� ��� O(1) ���� ����ϴ� hash �ڷᱸ��
#include <map> // key�� �������� ���ĵ�����. ����Ž��Ʈ���� �����Ǹ鼭 �����ϹǷ� value���� ã�µ� unordered���� �����ɸ����ִ�.
#include <string>
#include <iostream>

enum Gender
{
	MALE,
	FEMALE,
};

struct Student
{
	bool IsOnGlasses;
	Gender Gender;
	bool IsCodingGosu;
	int Age;
};

using namespace std;

ostream& operator<<(ostream& out, const Student& student)
{
	out << "=========================================\n";
	if (student.IsOnGlasses)
	{
		out << "�� �л��� �Ȱ��� �����ϴ�.\n";
	}
	else
	{
		out << "�� �л��� �Ȱ��� �� �����ϴ�.\n";
	}

	if (student.Gender == MALE)
	{
		out << "����\n";
	}
	else
	{
		out << "����\n";
	}

	if (student.IsCodingGosu)
	{
		out << "�ڵ�����Դϴ�.\n";
	}
	else
	{
		out << "�����������\n";
	}

	if (student.Age)
	{
		out << "���̴� " << student.Age << "�� �Դϴ�.\n";
	}
	out << "=========================================\n";

	return out;
}

int main()
{
	// assosiative? key-value ������ �̷����

	unordered_map<string, Student> hashTable;

	std::hash<string> hash; // stringŸ���� �ؽð��� �����ϴ� ����. �ؽ�Ÿ�Կ��� ȣ�⿬���� operator()�� �����ε��Ǿ��־� �Լ�ó�� ����Ҽ��ִ�.
	size_t value = hash("�ּ���"); // ����� �ֵ��� ���� size_t(8����Ʈ)������ ���´�

	hashTable["�ּ���"] = { false, FEMALE, true, 22 };
	hashTable["ȫ�¿�"] = { false, MALE, false, 30 };
	hashTable["���ǹ�"] = { false, MALE, false, 35 };
	hashTable["�赿��"] = { true, MALE, false, 28 };

	cout << hashTable["�ּ���"];
	cout << hashTable["ȫ�¿�"];
	cout << hashTable["���ǹ�"];
	cout << hashTable["�赿��"];

}