// Luis Paulo Reis, "Same Game with Console 
// Interface", University of Minho, 2012
// adapted From: Ben Marchant, "The Same Game: 
// A Simple Game from Start to Finish", 2005
// SameGame.h : interface of the CSameGame class

#include "Pudding_monsterBoard.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack> 
#include <fstream>
#include <windows.h>
#include <vector>
#include <conio.h>
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
using namespace std;

	
class Cdados{
	public:
	string Cnomes;
	int Cnivel;
	
friend class CPudding_monster;
};

class CPudding_monster: public CPudding_monsterBoard 
{
public:
	
  friend class CPudding_monsterBoard;
  CPudding_monster();
  ~CPudding_monster();
  void InputGameParameters();
  char GetMove(int &row, int &col,int &rowf, int &colf);
  char GetPCMove(void);
  void DrawBoard();
  void NewGame();
  void Game();
  void PCDicas();
  void start();
  void SaveName (const char *filename);
  void LoadName (const char *filename);
 
 
  vector <Cdados> Records;
  
  	string Nome2;
	int Nivel2;
	int Njogo;
	Cdados Aux;

 
  bool SaveGame();
  bool LoadGame();
  
private:
	
  CPudding_monsterBoard* m_arrboard;
  int m_nmoves;
 
};
