#pragma once

#include <iostream>
#include <Windows.h>
#include <string>

#define Size 10

struct Tile
{
	char field = '*';
	char forest = '#';
	char swamp = '~';
}tile;

struct Monster
{
	std::string name;
	char shape = 'M';
	int hp = 50;
	int exp = 10;
	int dorpGold = 100;
}monster;

struct Hero
{
	std::string Name;
	char shape = 'P';
	int Hp = 100;
	int Mp = 50;
	int Posion = 3;
	int gold = 0;
	int heroExp = 0;

}hero;


/// <summary>
/// ���� �׸���
/// </summary>
void PrintMap();

/// <summary>
/// ��������, Ÿ������, ���� ���� ������ ǥ�õȴ�
/// </summary>
void Information();

/// <summary>
/// ���� �̵����� �Լ�
/// </summary>
void heroMove();

/// <summary>
/// ���� �̿���� �Լ�
/// </summary>
void UseShop();

/// <summary>
/// ������ Ŭ���� ���� �Լ�
/// </summary>
/// <returns></returns>
bool GameEnding();

/// <summary>
/// Ŭ���� �� �׾����� �Լ�
/// </summary>
/// <returns></returns>
bool GameOver();

/// <summary>
/// �������� �Լ�
/// </summary>
void Battle();

/// <summary>
/// ������ġ�� ��� �����ִ� �Լ�
/// </summary>
void BattleResult();

// ���� ���� ���� bool��
bool gameOver = false;