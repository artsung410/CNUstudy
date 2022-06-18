#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <vector>

enum SceneType
{
    VILIAGE,
    PORTION_SHOP,
    WEAPON_SHOP,

    // ����;�
    GRASSLAND,
    FOREST,
    LAVA,
    SWAMP,
    DUNGEON,

    // ���θ޴� ��
    MENU,

    // �κ��丮 ��
    INVENTORY,

    // ������
    COMBAT,
    COMBATRESULT,

    // ��������
    EXIT
};

enum weapon
{
    FireSword,
    FishSpike,
    ChainSaw,
    SilverDawn,
};

enum Portion
{
    HpPortion,
    MpPortion,
    StrongMilk,
    ManaElixir
};

class player
{
    player() = default;
    player(const player& other) = delete;
    player& operator=(const player& other) = delete;
    ~player() = default;

    int getPlayerHP()
    {
        return _hp;
    }

    int getPlayerMp()
    {
        return _mp;
    }

private:
    int _gold = 1000;
    int _hp = 50;
    int _mp = 50;
    int _Experience = 0;
    int _Level = 0;
    bool _isPosion[4]; //1. HP����, 2. MP����, 3. �������, 4. ����������
    bool _isWeapon[4]; //1. ȭ����, 2. ������ۻ�, 3. ������, 4. ��������
    bool _isEpicWeapon[10];

};

enum textIndex
{
    SWORD,
    WIZARD,
    PUNCH
};

struct GameData
{
    std::string HeroName[3];
    int HeroLevel[3];
    int HeroCurrentExperience[3];
    int HeroTotalExperience[3];
    int HeroHealth[3];
    int HeroMana[3];
    int PlayerGold;
    int HeroInfoPosCount;
    std::vector<std::string> playerItem;
    std::string SceneName[14];

    bool isNoMoney;
};

static SceneType s_currentScene;
static SceneType s_prevScene;

GameData Data;
textIndex hDataindex;

void Init()
{
    // �� ������ �ʱ�ȭ
    s_currentScene = VILIAGE;
    s_prevScene = VILIAGE; 
    // ���� ĳ���� ���� �ʱ�ȭ
    hDataindex = SWORD; 

    // ĳ���� ���� �ʱ�ȭ
    Data.HeroName[SWORD] = " �˻� ";
    Data.HeroName[WIZARD] = "������";
    Data.HeroName[PUNCH] = "������";
    Data.PlayerGold = 1500;

    for (int i = 0; i < 3; i++) { Data.HeroLevel[i] = 1; }
    for (int i = 0; i < 3; i++) { Data.HeroCurrentExperience[i] = 0; }
    for (int i = 0; i < 3; i++) { Data.HeroTotalExperience[i] = 1000; }
    for (int i = 0; i < 3; i++) { Data.HeroHealth[i] = 60; }
    for (int i = 0; i < 3; i++) { Data.HeroMana[i] = 60; }

    Data.HeroInfoPosCount = 0;

    // �� �̸� �ʱ�ȭ
    Data.SceneName[0] = "����";
    Data.SceneName[1] = "���� ����";
    Data.SceneName[2] = "���� ����";
    Data.SceneName[3] = "�ʿ� ����";
    Data.SceneName[4] = "����� ��";
    Data.SceneName[5] = "��� ����";
    Data.SceneName[6] = "�� ����";
    Data.SceneName[7] = "����";
    Data.SceneName[8] = "�޴�";
    Data.SceneName[9] = "�κ��丮";
    Data.SceneName[10] = "����";
    Data.SceneName[11] = "���� ���";
}

void Render()
{

}

void Release()
{

}

int main()
{
    // Ÿ��Ʋ â ����.
    std::cout << "��Ʈ���� �������." << std::endl;

    Sleep(2000);

    // ���� ������ �ʱ�ȭ
    Init();

    while (true)
    {
        system("cls");
        switch (s_currentScene)
        {
// ����
#pragma region VILIAGE
        case VILIAGE:
            s_prevScene = VILIAGE;
            std::cout << "[[[[[" << Data.SceneName[VILIAGE] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "a. ���ǻ���" << std::endl;
            std::cout << "b. �������" << std::endl;
            std::cout << "c. �����" << std::endl;
            std::cout << "d. ���θ޴�" << std::endl;

            switch (_getch())
            {
            case 'a':
                s_currentScene = PORTION_SHOP;
                break;
            case 'b':
                s_currentScene = WEAPON_SHOP;
                break;
            case 'c':
                s_currentScene = GRASSLAND;
                break;
            case 'd':
                s_currentScene = MENU;
                break;
            }
            break;
#pragma endregion

// ����
#pragma region [Viliage] PORTION_SHOP
        case PORTION_SHOP:
            std::cout << "[[[[[" << Data.SceneName[PORTION_SHOP] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "a. HP���� 50 GOLD" << "            " << "���� ���� ��� : "<< Data.PlayerGold << std::endl;
            std::cout << "b. MP���� 50 GOLD" << std::endl;
            std::cout << "c. ������� 500 GOLD" << std::endl;
            std::cout << "d. ���������� 500 GOLD" << std::endl;
            std::cout << "e. ������" << std::endl;

            switch (_getch())
            {
            case 'a':
                if (Data.PlayerGold > 50) { Data.PlayerGold -= 50; }
                break;
            case 'b':
                if (Data.PlayerGold > 50){ Data.PlayerGold -= 50; }
                break;
            case 'c':
                if (Data.PlayerGold > 500){ Data.PlayerGold -= 500; }
                break;
            case 'd':
                if (Data.PlayerGold > 500){ Data.PlayerGold -= 500; }
                break;
            case 'e':
                s_currentScene = VILIAGE;
                break;
            }
            break;

            if (Data.isNoMoney)
            {
               std::cout << "�����ݾ��� �����մϴ�" << std::endl;
            }

#pragma endregion

#pragma region [Viliage] WEAPON_SHOP
        case WEAPON_SHOP:

            std::cout << "[[[[[" << Data.SceneName[WEAPON_SHOP] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "a. ȭ���� 500 GOLD" << std::endl;
            std::cout << "b. ����� �ۻ� 1000 GOLD" << std::endl;
            std::cout << "c. ������ 1500 GOLD" << std::endl;
            std::cout << "d. ���� ���� 2000GOLD" << std::endl;
            std::cout << "e. ������" << std::endl;

            switch (_getch())
            {
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                s_currentScene = VILIAGE;
                break;
            }
            break;
#pragma endregion


// �����
#pragma region [Hunting Ground] GRASSLAND 
        case GRASSLAND:

            s_prevScene = GRASSLAND;
            std::cout << "[[[[[" << Data.SceneName[GRASSLAND] << "]]]]]" << std::endl;
            std::cout << std::endl;

            // ���� ���� qŰ ���������� ����
            for (int i = 0; i < 3; i++)
            {
                if (hDataindex == i)
                {
                    std::cout << "INFO: <" << Data.HeroName[i] << ">" << " ���� " << Data.HeroLevel[i] << " | " << "����ġ " << Data.HeroCurrentExperience[i]
                        << " / " << Data.HeroTotalExperience[i] << " | " << "ü�� " << Data.HeroHealth[i] << " | " << "���� " << Data.HeroMana[i] << " | " << "��� " << Data.PlayerGold << std::endl;
                }
            }

            std::cout << std::endl;
            std::cout << "####&#####" << std::endl;
            std::cout << "#######M##" << std::endl;
            std::cout << "##########" << std::endl;
            std::cout << "&########&" << std::endl;
            std::cout << "##P#######" << std::endl;
            std::cout << "##########" << std::endl;
            std::cout << "####&#####" << std::endl;

            std::cout << std::endl;

            std::cout << "a. �κ��丮" << std::endl;
            std::cout << "b. ������ ���ư���" << std::endl;
            std::cout << "c. ���θ޴�" << std::endl;
            std::cout << "d. �ٸ���� ����" << std::endl;

            switch (_getch())
            {
            case 'a':
                s_currentScene = INVENTORY;
                break;
            case 'b':
                s_currentScene = VILIAGE;
                break;
            case 'c':
                s_currentScene = MENU;
            case 'd':
                ++Data.HeroInfoPosCount;

                if (Data.HeroInfoPosCount == 3)
                {
                    Data.HeroInfoPosCount = 0;
                }

                hDataindex = (textIndex)Data.HeroInfoPosCount;
                break;
            }
            break;
#pragma endregion

//���θ޴�
#pragma region MENU
        case MENU:

            switch (s_prevScene)
            {
            case VILIAGE:
                std::cout << "[[[[[" << Data.SceneName[VILIAGE] << "]]]]]" << std::endl;
                break;
            case GRASSLAND:
                std::cout << "[[[[[" << Data.SceneName[GRASSLAND] << "]]]]]" << std::endl;
                break;
            case FOREST:
                std::cout << "[[[[[" << Data.SceneName[FOREST] << "]]]]]" << std::endl;
                break;
            case LAVA:
                std::cout << "[[[[[" << Data.SceneName[LAVA] << "]]]]]" << std::endl;
                break;
            case SWAMP:
                std::cout << "[[[[[" << Data.SceneName[SWAMP] << "]]]]]" << std::endl;
                break;
            case DUNGEON:
                std::cout << "[[[[[" << Data.SceneName[DUNGEON] << "]]]]]" << std::endl;
                break;
            }

            std::cout << std::endl;

            std::cout << "a. ���ư���" << std::endl;
            std::cout << "b. ��������" << std::endl;
            std::cout << "c. ����" << std::endl;

            switch (_getch())
            {
            case 'a':
                s_currentScene = s_prevScene;
                break;

            case 'b':
                break;
            case 'c':
                return 0;
                break;
            }
#pragma endregion

//�κ��丮
#pragma region INVENTORY
        case INVENTORY:
            switch (s_prevScene)
            {
            case VILIAGE:
                std::cout << "[[[[[" << Data.SceneName[VILIAGE] << "]]]]]" << std::endl;
                break;
            case GRASSLAND:
                std::cout << "[[[[[" << Data.SceneName[GRASSLAND] << "]]]]]" << std::endl;
                break;
            case FOREST:
                std::cout << "[[[[[" << Data.SceneName[FOREST] << "]]]]]" << std::endl;
                break;
            case LAVA:
                std::cout << "[[[[[" << Data.SceneName[LAVA] << "]]]]]" << std::endl;
                break;
            case SWAMP:
                std::cout << "[[[[[" << Data.SceneName[SWAMP] << "]]]]]" << std::endl;
                break;
            case DUNGEON:
                std::cout << "[[[[[" << Data.SceneName[DUNGEON] << "]]]]]" << std::endl;
                break;
            }
            std::cout << std::endl;
            std::cout << "[���]" << std::endl;
            std::cout << "���� : �㸧�� ���� �Ҹ�" << std::endl;
            std::cout << "���� : �㸧�� ���� ����" << std::endl;
            std::cout << "���� : �߱������" << std::endl;
            std::cout << std::endl;
            std::cout << "[������]" << std::endl;
            std::cout << "HP���� 15" << std::endl;
            std::cout << "MP���� 5" << std::endl;
            std::cout << std::endl;
            std::cout << "a.���ư���" << std::endl;

            switch (_getch())
            {
            case 'a':
                s_currentScene = s_prevScene;
                break;
            }
#pragma endregion

        }
    }

    return 0;
}
