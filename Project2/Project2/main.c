#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define DELTA_TIME (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC
#define MAX_DELTA_TIME 3.0f
#define BULLET_SPEED 20
#define PLAYER_POS_MIN 0
#define PLAYER_POS_MAX 30

struct player
{
    int X; // �÷��̾� �ʱ� X��ǥ ����
    int Y; // �÷��̾� �ʱ� Y��ǥ ����

}player, bullet;

void main() 
{
    player.X = 1; 
    player.Y = 1; 

    bullet.X = 0;
    bullet.Y = 0;
    clock_t s_prevTick = 0; 

    bool isBullet = false;

    while(1)
    {
        // ����Ű [�Է�]
        if (GetAsyncKeyState(VK_LEFT) && (player.X > PLAYER_POS_MIN))
        { 
            player.X--;
        }

        if (GetAsyncKeyState(VK_RIGHT) && (player.X < PLAYER_POS_MAX))
        { 
            player.X++;
        }

        if (GetAsyncKeyState(VK_UP) && (player.Y > PLAYER_POS_MIN))
        { 
            player.Y--;
        }

        if (GetAsyncKeyState(VK_DOWN) && (player.Y < PLAYER_POS_MAX))
        { 
            player.Y++;
        }

        // �÷��̾� �̵� [ó��]
        COORD playerPos = { player.X, player.Y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPos);
        printf("P"); // �÷��̾� ȭ�� [���]


        // �Ѿ˹߻� [�Է�]
        if (GetAsyncKeyState(VK_SPACE) && isBullet != true)
        {
            bullet.X = player.X + 1;
            bullet.Y = player.Y;
            s_prevTick = clock();
            isBullet = true;
        }

        // �Ѿ˹߻� [ó��]
        clock_t currentTick = clock();
        if (isBullet)
        {
            COORD bulletPos = { bullet.X + DELTA_TIME * BULLET_SPEED, bullet.Y };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bulletPos);
            printf("��"); // �Ѿ��� ������ش�.[���]

            if (DELTA_TIME > MAX_DELTA_TIME)
            {
                s_prevTick = currentTick;
                isBullet = false;
            }
        }

        Sleep(10);
        system("cls"); // ȭ���� �ʱ�ȭ �����ش�. 
    }
}

