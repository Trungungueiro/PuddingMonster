// Luis Paulo Reis, "Same Game with Console 
// Interface", University of Minho, 2012
// adapted From: Ben Marchant, "The Same Game: 
// A Simple Game from Start to Finish", 2005

#include <cstdlib>
#include <iostream>
#include "Pudding_monster.h"
#include <time.h> 
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
	
int aux, a=0;
CPudding_monster same;  
while (a==0){

cout<< "Escolha O tipo de Jogo"<< endl;
cout<<"Jogo Humano  1"<< endl << "Jogo PC  2" <<endl;
cin>> aux;
if (aux == 1){
a = 1;
same.Game();	
} 
else if(aux==2){
a==1;
same.GetPCMove();	
}
	
}
  	
   
   return 0;
}
