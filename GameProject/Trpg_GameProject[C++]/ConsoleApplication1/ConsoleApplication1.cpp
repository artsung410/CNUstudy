#include <iostream>
#include <time.h>

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

int main()
{

    bool isMainMenu = true;
    while (true)
    {
        int iMenu;
        cin >> iMenu;

        cout << "1. ��" << endl;
        cout << "2. ����" << endl;
        cout << "3. �κ��丮" << endl;
        cout << "4. ����" << endl;

        if (iMenu == MM_MAP)
        {
            cout << "1. �����1" << endl;
            cout << "2. �����2" << endl;
            cout << "3. �����3" << endl;
            cout << "4. ����" << endl;
            cout << "5. �κ��丮" << endl;
        }
        if (iMenu == MM_STORE)


        if (iMenu == MM_INVENTORY)


        if (iMenu == MM_EXIT)
            break;
    }

    return 0;
}
