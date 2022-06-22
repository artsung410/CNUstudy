/*
L 	 Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)

D	 Ŀ���� ���������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)

B	 Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�)
	 ������ ���� Ŀ���� �� ĭ �������� �̵��� ��ó�� ��Ÿ������, ������ Ŀ���� �����ʿ� �ִ� ���ڴ� �״����

P $	 $��� ���ڸ� Ŀ�� ���ʿ� �߰���

��, ��ɾ ����Ǳ� �� Ŀ���� ������ �ǵ�

ù°�� �ԷµǴ� ���ڿ�
	���̰� N <= 100000

��°�� �Է��� ��ɾ� ����
	���� 1 <= M <= 500000

��°�� �Է��� ��ɾ� �������
	M�� �Է��Ѵ�

���
	��� ��ɾ ������ ���ڿ� ����Ѵ�.
*/

#include <iostream>
#include <list>

// ��������Ʈ ���� �߰������� �� �� �����Ҷ� ��ȿ�����̹Ƿ� ���Ḯ��Ʈ�� ����


// �˰������� Ǯ�� ���������� ����ϸ� ���ϴ�
std::string s;
int M;

int main()
{
	// ����� �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// 1. ���ڿ��� �Է¹޴´�
	std::cin >> s;

	// 2. ��ɾ��� ���� �Է�
	std::cin >> M;

	// 3. ��ɾ� ó��
	std::list<char> lst(s.begin(), s.end());
	std::list<char>::iterator cursor = lst.end();

	while (M--)
	{
		// 3-1 ��ɾ� �Է¹޴´�
		char op;
		std::cin >> op;

		// 3-2 �� ��ɾ �°� ����
		switch (op)
		{
		case 'L':
			if (cursor != lst.begin())
			{
				--cursor;
			}
			break;
		case 'D':
			if (cursor != lst.end())
			{
				++cursor;
			}
			break;
		case 'B':
			if (cursor != lst.begin())
			{
				--cursor;
				cursor = lst.erase(cursor); // �ݺ��ڰ� ��ȿȭ �� �� �ִ�.
			}
			
			break;
		case 'P':
			char ch;
			std::cin >> ch;

			cursor = lst.insert(cursor, ch); //  inserts value before pos
			++cursor;

			break;
		default:
			break;
		}
	}

	for (std::list<char>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		std::cout << *iter;
	}
}