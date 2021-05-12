// Luis Paulo Reis, "Same Game with Console 
// Interface", University of Minho, 2012
// adapted From: Ben Marchant, "The Same Game: 
// A Simple Game from Start to Finish", 2005

// Pudding_monsterBoard.h : interface of the CSameGameBoard class
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

class CMatriz{
	public:
	int X;
	int Y;
	friend class CPudding_monsterBoard;
 };

class CPudding_monsterBoard
{
public:
    CPudding_monsterBoard(void);   // Default Constructor
    CPudding_monsterBoard(const CPudding_monsterBoard& board);  //  Copy Constructor 
    ~CPudding_monsterBoard(void);  //  Destructor
    void SetupBoard();  // Function to randomly setup the board
    int GetBoardSpace(int row, int col); // Get the color at row,col
    void numeros(int n);
    void SetupBoard2(int op);
    void linha(int n, int d); 
	bool Frentpecas(int x, int y, int dir);
    int joga;
     int AvaliaTab(int i, int j, int k, int l);
     int IsValid(int i, int j);
     int IsValid2(int i, int j, int k, int l);
    //  Accessor functions to get/set board size information 
    int GetColumns(void) const { return m_nColumns; }
    void SetColumns(int nColumns)  { m_nColumns = (nColumns >= 5) ? nColumns : 5; }
    int GetRows(void) const { return m_nRows; }
    void SetRows(int nRows)  { m_nRows = (nRows >= 7) ? nRows : 7; }
    //  Function to delete the board and free memory
    void DeleteBoard(void);
    int IsGameOver(void);  //  Is the game over?
    int GetNumColors(void) { return m_nColors; } //  Functions to get and set the number of colors
    void SetNumColors(int nColors);
    int GetRemainingCount(void) const { return m_nRemaining; } //  Get the number of blocks remaining
    int ExecuteMove(int row, int col,int rowf, int colf );  //  Function to delete all adjacent blocks
    void DrawBoard(void);
    
    void NumLigadas(int x, int y , int dir);
    vector <CMatriz> ligadas;
    // Function to see if a move is valid
    // TODO (#1#): 
    int ValidMove(int row, int col,int rowf, int colf);
    void SaveBoard(const char *filename);
    //bool LoadBoard();
    void loadGame (const char *filename);
    void atualiza(void) const;
    int peca_eliminada;
    void Peca_eliminada(void){ peca_eliminada = 0;}
    void Setlevel(int nivel){ level = nivel;}
    int level,aux;
 private:
    void CreateBoard(void); //Function to create the board and allocate memory
  // Direction enumeration for deleting blocks
  enum Direction { DUP, DDOWN, DLEFT, DRIGHT };
  //  Recursive helper function for deleting blocks
  int DeleteNeighborBlocks(int row, int col, int color,Direction direction);
  // Function to compact the board after blocks are eliminated
  void CompactBoard(void);
// Class Data
  int** m_arrBoard; // 2D array pointer
  //  Board size information
  char m_arrChars[10];
  int m_nColumns;
  int m_nRows;
  int m_nRemaining;  // Number of blocks remaining
  int m_nColors;     // Number of colors
    
};
