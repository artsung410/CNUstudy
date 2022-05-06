#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// ���� ���� : ������ġ, Ż�ⱸ ��ġ

// ����(M)�� �÷������� �����̵��� ����.

// �÷��̾ 2�� ���������� ���Ͱ� 1�������̰�

int main()
{
    char map[12][22]; // �� ũ��
    char player = 'O'; // �÷��̾�
    char finish = 'F'; // ������
    char monster = 'M'; // ����
    char wall = '@'; // ��
    char base = '^'; // ���̽�
    char item = 'i';

    // �÷��̾� ��ǥ �����ϱ�
    int playerX = 1;
    int playerY = 1;

    // �����Է��� ���� �ִ밪 �ּҰ� ���� ����
    srand(time(NULL));
    int sNum = 1;
    int bNum1 = 10;
    int bNum2 = 20;

    // ���� Ż�ⱸ ��ǥ �����ϱ� (���� �ߺ����� �ʰ� �ϱ�)
    int escapeI = rand() % (bNum1 - sNum + 1) + sNum;
    int escapeJ = rand() % (bNum2 - sNum + 1) + sNum;

    // ���� ���� ��ǥ �����ϱ� (���� �ߺ����� �ʰ� �ϱ�)
    int monsterX = rand() % (bNum2 - sNum + 1) + sNum;;
    int monsterY = rand() % (bNum1 - sNum + 1) + sNum;

    // ���� ������ ��ǥ �����ϱ� (���� �ߺ����� �ʰ� �ϱ�)
    int item1X = rand() % (bNum2 - sNum + 1) + sNum;
    int item2X = rand() % (bNum2 - sNum + 1) + sNum;
    int item3X = rand() % (bNum2 - sNum + 1) + sNum;

    int item1Y = rand() % (bNum1 - sNum + 1) + sNum;
    int item2Y = rand() % (bNum1 - sNum + 1) + sNum;
    int item3Y = rand() % (bNum1 - sNum + 1) + sNum;

    bool isItem1 = true;

    // ���ӳ��� Ʈ���� ����� (while�� Ż���ϱ� ����)
    bool gameOver = false;

    // �÷��̾� �� ���.
    int playerState = 0;

    // ���ھ�
    int score = 0;


    while (!gameOver)
    {
        switch (_getch())
        {
        case 'w'/*w ��*/:
            if (playerY > 1)
            {
                --playerY;
                ++playerState;
            }
            break;

        case 'a' /*a ��*/:
            if (playerX > 1)// ���� ������ üũ
            {
                --playerX;
                ++playerState;
            }
            break;

        case 's' /*s ��*/:
            if (playerY < 10) // ���� ������ üũ
            {
                ++playerY;
                ++playerState;
            }
            break;

        case 'd' /*d ��*/:
            if (playerX < 20) // ���� ������ üũ
            {
                ++playerX;
                ++playerState;
            }
            break;

        default:
            break;
        }

        system("cls"); // ������ �ѹ� ���� ȭ���� �ʱ�ȭ ��Ų��.


        // ���ʱ�ȭ
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 22; j++)
            {
                map[i][j] = base; // �迭�� ������ map[][]�� #���
                map[escapeI][escapeJ] = finish; // ������ ��ġ ���� (����)
                map[playerY][playerX] = player; // �÷��̾� ��ġ ���� (����)
                map[monsterY][monsterX] = monster; // ���� ��ġ ���� (����)

                if (isItem1)
                    map[item1Y][item1X] = item;

                if (i == 0 || i == 11 || j == 0 || j == 21)
                {
                    map[i][j] = wall; // i, j�� �� ���κп� ��ġ�Ҷ����� �� ����
                }
                cout << map[i][j]; // ���� �� ���� ���
            }
            cout << "" << endl; // ���� �� ���� ���
        }

        // �÷��̾ 2�Ͽ����̸� ���͵� �����̵��� ���ǹ� ����
        if (playerState == 2)
        {
            playerState = 0; // �÷��̾ 2�Ͽ����̸� playerState �� 0���� �ʱ�ȭ
            if ((monsterX > playerX) && !(monsterX == 1))
            {
                --monsterX;
            }
            else if ((monsterX < playerX) && !(monsterX == 20))
            {
                ++monsterX;
            }
            else if ((monsterY > playerY) && !(monsterX == 1))
            {
                --monsterY;
            }
            else if ((monsterY < playerY) && !(monsterX == 20))
            {
                ++monsterY;
            }
        }

        // �÷��̾� �� ������ ��ǥ�� ������ ���� ����.
        if (map[playerY][playerX] == map[monsterY][monsterX])
        {
            cout << "Game Over" << endl;
            gameOver = true;
        }

        // �÷��̾� ��ǥ�� ������ ��ǥ�� ������ ���� �¸�.
        if (map[playerY][playerX] == map[escapeI][escapeJ])
        {
            cout << "���ӿ��� �¸��ϼ̽��ϴ�." << endl;
            gameOver = true;
        }

        if (map[playerY][playerX] == map[item1Y][item1X])
        {
            isItem1 = false;
            map[item1Y][item1X] = base;
            score += 50;
        }

        cout << "---------------------------" << endl;
        cout << "���� �� : " << playerState << endl;
        cout << "Score : " << score << endl;
        cout << "---------------------------" << endl;

    }
}