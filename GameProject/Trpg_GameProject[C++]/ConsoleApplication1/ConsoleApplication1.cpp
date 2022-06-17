#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

enum Scene
{
    SceneNULL,
    Title,
    Narration,
    Viliage,
    PortionShop,
    WeaponShop,

    // ����;�
    Map_Grassland,
    Map_Forest,
    Map_Lava,
    Map_Swamp,
    Map_Dungeon,

    // ���θ޴� ��
    MainMenu,
    
    // �κ��丮 ��
    Inventory,

    // ������
    Combat,
    CombatResult,

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

struct HerosData
{
    string HeroName[3];
    int HeroLevel[3];
    int HeroCurrentExperience[3];
    int HeroTotalExperience[3];
    int HeroHealth[3];
    int HeroMana[3];
    int HeroGold;
};


int main()
{

    bool isMainMenu = true;

    cout << "��Ʈ���� �������." << endl;

    Sleep(1000);
    system("cls");

    cout << "���ʿ� ���� 3���� �����Ͽ���." << endl;
    cout << "�̵��� �˻�, ������, �������� ���� ������ ���Ǹ� �ξ���." << endl;
    cout << "�̵��� �������� ���ϴµ� ..���ڱ� ��ǳ�� �����ƴ�." << endl;
    cout << "������ �����Ϸ��� �ƹ�Ű�� �����ÿ�. (Press Any Key)" << endl;
    Sleep(1000);
    system("cls");



    // ���� ������ �ʱ�ȭ
    HerosData hData;

    hData.HeroName[SWORD] = " �˻� ";
    hData.HeroName[WIZARD] = "������";
    hData.HeroName[PUNCH] = "������";
    hData.HeroGold = 1500;

    for (int i = 0; i < 3; i++){ hData.HeroLevel[i] = 1; }
    for (int i = 0; i < 3; i++){ hData.HeroCurrentExperience[i] = 0; }
    for (int i = 0; i < 3; i++){ hData.HeroTotalExperience[i] = 1000; }
    for (int i = 0; i < 3; i++){ hData.HeroHealth[i] = 60; }
    for (int i = 0; i < 3; i++){ hData.HeroMana[i] = 60; }
    // ���� ������ �ʱ�ȭ


    textIndex hDataindex = SWORD;

    int index = 0;

    while (true)
    {

        char inputChar = _getch();

        system("cls");


        if (inputChar == 'a')
        {
            ++index;

            if (index == 3)
            {
                index = 0;
            }

            hDataindex = (textIndex)index;
        }

        for (int i = 0; i < 3; i++)
        {
            if (hDataindex == i)
            {
                cout << "INFO: <" << hData.HeroName[i] << ">" << " ���� " << hData.HeroLevel[i] << " | " << "����ġ " << hData.HeroCurrentExperience[i]
                    << " / " << hData.HeroTotalExperience[i] << " | " << "ü�� " << hData.HeroHealth[i] << " | " << "���� " << hData.HeroMana[i] << " | " << "��� " << hData.HeroGold << endl;
            }
        }

        cout << "1. ���ǻ���" << endl;
        cout << "2. �������" << endl;
        cout << "3. �����" << endl;
        cout << "4. ���θ޴�" << endl;


    }

    return 0;
}
