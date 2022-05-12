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

struct player
{
    int X; // �÷��̾� �ʱ� X��ǥ ����
    int Y; // �÷��̾� �ʱ� Y��ǥ ����
    COORD Pos;
    HANDLE h;

}player, bullet;

void main() 
{
    player.X = 0; // �÷��̾� �ʱ� X��ǥ ����
    player.Y = 0; // �÷��̾� �ʱ� Y��ǥ ����

    bullet.X = 0; // �Ѿ��ʱ� X��ǥ ����
    bullet.Y = 0; // �Ѿ��ʱ� Y��ǥ ����
    clock_t s_prevTick = 0; // �Ѿ� �߻� ������ ��� ���� ����

    int bulletPosCount = 0; // �ҷ� �������� ������Ű�� ���� ���� ����
    bool isBullet = false; // �ҷ��� �߻� �Ǿ�����, true, �ƴϸ� false

    while(1)
    {
        clock_t currentTick = clock(); // ���� �ð��� �ʱ�ȭ �Ѵ�.
        system("cls"); // ȭ���� �ʱ�ȭ �����ش�. 

        // Ű�� �ϳ��� ������ �� [�Է�]
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
        { 
            player.X--;
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
        { 
            player.X++;
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000) 
        { 
            player.Y--;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000) 
        { 
            player.Y++;
        }

        // Ű �ΰ� ���ÿ� �������� [�Է�]
        if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_UP))
        {
            player.X--;
            player.Y--;
        }
  
        if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_DOWN))
        {
            player.X--;
            player.Y++;
        }

        if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_DOWN))
        {
            player.X++;
            player.Y++;
        }

        if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_UP))
        {
            player.X++;
            player.Y--;
        }

        // Ű �ΰ� ���ÿ� �������� / �Ѿ� �߻���°� Ȱ��ȭ ���°� �ƴҶ� [�Է�]
        if (GetAsyncKeyState(VK_SPACE) & 0x8000 && isBullet != true)
        {
            bullet.X = player.X; // �Ѿ� �ʱ���ǥ�� ���� �÷��̾� ��ǥ�� �����Ѵ�.
            bullet.Y = player.Y; // �Ѿ� �ʱ���ǥ�� ���� �÷��̾� ��ǥ�� �����Ѵ�.
            s_prevTick = clock(); // �Ѿ��� ó�� �߻� ������, �ʱ�ð��� ��´�.
            isBullet = true;  // �Ѿ� �߻���¸� Ȱ��ȭ ��Ų��.
        }


        // [ó��]
        COORD playerPos = { player.X, player.Y }; // ������ ������Ʈ
        HANDLE hPlayerPos = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ鰪 ���� ���.
        SetConsoleCursorPosition(hPlayerPos, playerPos); // ��ǥ �ʱ�ȭ
        printf("P"); // �÷��̾� ��ǥ�� printf�� ������ �ش�.[���]


        if (isBullet) // �����̽��ٰ� ������ isBullet �����̸�
        {
            float deltatime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC; // �Ѿ��� ����ð����� �ʱ�ð��� �����ؼ� ��Ÿ Ÿ���� ���Ѵ�

            COORD BulletPos = { bullet.X + bulletPosCount, bullet.Y }; // �ҷ���ǥ�� ���ؼ� �ǽð����� ������Ʈ ��Ų��.
            HANDLE hBulletPos = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ鰪 ���� ���.
            SetConsoleCursorPosition(hBulletPos, BulletPos); // ��ǥ �ʱ�ȭ
            printf("��"); // �Ѿ��� ������ش�.[���]

            if (deltatime > 3.0f) // ����ð��� 3���̻��� �Ǹ�
            {

                bulletPosCount = 0; // bulletcount�� 0���� �ʱ�ȭ
                s_prevTick = currentTick; // ����ð��� �ʱ�ȭ ��Ų��.
                isBullet = false; // �Ѿ� �߻���¸� ��Ȱ��ȭ ��Ų��.
            }

            ++bulletPosCount; // 3�ʰ� �ɶ����� bulletPosCount�� �����ش�.
        }

    }
}

