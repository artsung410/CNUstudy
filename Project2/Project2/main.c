#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <windows.h>

// ���� ��� : printf() / putchar()

// Ŀ�� �̵� : SetConsoleCursorPosition

// �Է� : GetAsyncKeyState()

void main() 
{
    int playerX = 0; // �÷��̾� �ʱ� X��ǥ ����
    int playerY = 0; // �÷��̾� �ʱ� Y��ǥ ����

    int prev_BulletX = 0; // �Ѿ��ʱ� X��ǥ ����
    int prev_BulletY = 0; // �Ѿ��ʱ� Y��ǥ ����
    clock_t s_prevTick = 0; // �Ѿ� �߻� ������ ��� ���� ����

    int bulletPosCount = 0; // �ҷ� �������� ������Ű�� ���� ���� ����
    bool isBullet = false; // �ҷ��� �߻� �Ǿ�����, true, �ƴϸ� false

    do
    {
        // Ű�� �ϳ��� ������ �� [�Է�]
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
        { 
            playerX--;
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
        { 
            playerX++;
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000) 
        { 
            playerY--;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000) 
        { 
            playerY++;
        }

        // Ű �ΰ� ���ÿ� �������� [�Է�]
        if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_UP))
        {
            playerX--; 
            playerY--;
        }
  
        if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_DOWN))
        {
            playerX--;
            playerY++;
        }

        if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_DOWN))
        {
            playerX++;
            playerY++;
        }

        if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_UP))
        {
            playerX++;
            playerY--;
        }

        // Ű �ΰ� ���ÿ� �������� / �Ѿ� �߻���°� Ȱ��ȭ ���°� �ƴҶ� [�Է�]
        if (GetAsyncKeyState(VK_SPACE) & 0x8000 && isBullet != true)
        {
            prev_BulletX = playerX; // �Ѿ� �ʱ���ǥ�� ���� �÷��̾� ��ǥ�� �����Ѵ�.
            prev_BulletY = playerY; // �Ѿ� �ʱ���ǥ�� ���� �÷��̾� ��ǥ�� �����Ѵ�.
            clock_t s_prevTick = clock(); // �Ѿ��� ó�� �߻� ������, �ʱ�ð��� ��´�.
            isBullet = true;  // �Ѿ� �߻���¸� Ȱ��ȭ ��Ų��.
        }

        system("cls"); // ȭ���� �ʱ�ȭ �����ش�. 

        COORD playerPos = { playerX, playerY}; // ������ ������Ʈ
        HANDLE hPlayerPos = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ鰪 ���� ���.
        SetConsoleCursorPosition(hPlayerPos, playerPos); // ��ǥ �ʱ�ȭ
        printf("P"); // �÷��̾� ��ǥ�� printf�� ������ �ش�.


        clock_t currentTick = clock(); // ���� �ð��� �ʱ�ȭ �Ѵ�.
        if (isBullet) // �����̽��ٰ� ��������
        {
            float deltatime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC; // �Ѿ��� ����ð����� �ʱ�ð��� �����ؼ� ��Ÿ Ÿ���� ���Ѵ�
            if (deltatime > 3.0f) // ����ð��� 3���̻��� �Ǹ�
            {
                bulletPosCount = 0; // bulletcount�� 0���� �ʱ�ȭ
                s_prevTick = currentTick; // ����ð��� �ʱ�ȭ ��Ų��.
                isBullet = false; // �Ѿ� �߻���¸� ��Ȱ��ȭ ��Ų��.
            }

            COORD BulletPos = { prev_BulletX + bulletPosCount, prev_BulletY }; // �ҷ���ǥ�� ���ؼ� �ǽð����� ������Ʈ ��Ų��.
            HANDLE hBulletPos = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ鰪 ���� ���.
            SetConsoleCursorPosition(hBulletPos, BulletPos); // ��ǥ �ʱ�ȭ
            printf("O"); // �Ѿ��� ������ش�.

            ++bulletPosCount; // 3�ʰ� �ɶ����� bulletPosCount�� �����ش�.
        }

    } while (1);
}

