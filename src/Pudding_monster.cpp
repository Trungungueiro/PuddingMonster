// SameGame.cpp : implementation of the CSameGame class

#include "Pudding_monster.h"

// CSameGame construction
CPudding_monster::CPudding_monster()
{
  m_nmoves = 0;
}

// CSameGame destruction
CPudding_monster::~CPudding_monster()
{
}

void CPudding_monster::NewGame()
{
	
  SetupBoard();  //  Set (or reset) the game board
  m_nmoves = 0;
  
}

  
void CPudding_monster::InputGameParameters()
{  
   //Simple Input. Add Menu to control game parameters
  
   SetNumColors(4); 
   SetColumns(4); 
   SetRows(7); 
}


void CPudding_monster::SaveName (const char *filename)
{
    ofstream output(filename);
	if (!output) { cerr << "Error :  Can't save File! "; return; }
	for(int i=0; i< Records.size(); i++) {
	    output << Records[i].Cnomes << " " << Records[i].Cnivel << " "<< endl;}
  	}
	    

void CPudding_monster::LoadName (const char *filename)
{
    ifstream input(filename);
	if (!input) { cerr << "Error :  Can't Open File! "; return; }
    Cdados ch;
	while (!input.eof()) {
			input >> ch.Cnomes >> ch.Cnivel;
			Records.push_back(ch);
    }
}


// Simple Game for Human Player
void CPudding_monster::Game()
{
	
   char *RECORDS;
   LoadName ("RECORDS.txt");  
   int x, y,xf, yf,a=1;
   char und;
   InputGameParameters();
   
   cout<<"                    WELCOME TO PUDDING MONSTER"<<endl<<endl;
   cout<<"Novo Jogo"<<"            "<<"Continuar um Jogo"<<endl<<endl;
 while (a==1){
   	
   cout<<"1 para Novo Jogo" << endl<< "2 para Continuar um jogo"<<endl;
   cin >> Njogo;
  
  if (Njogo==1){
  cout<<"Introduza o Nome" << endl;
   cin >> Aux.Cnomes;
   Aux.Cnivel=1;
   Records.push_back(Aux);
   SaveName ("RECORDS.txt");
   Setlevel(Aux.Cnivel);
   a=0;
  }
  else if (Njogo==2){
         cout<<"Introduza o Nome" << endl;
         cin >> Aux.Cnomes;
             for(int i=0; i<Records.size();i++){
            	if(Records[i].Cnomes==Aux.Cnomes) {
                  	Aux.Cnivel = Records[i].Cnivel;
                     cout<<endl<<endl<<endl;
                  	 cout<<"Benvindo de Novo " <<Aux.Cnomes<< endl;
                  	 cout<<"Estas no Nivel " <<Aux.Cnivel<< endl<<endl;
                  	 break;
            	}
                else if(i==Records.size()-1){
					cout<<endl<<endl<<endl;
					cout<<"Nome Nao Existente" << endl;
					cout<<"Agora es um Novo jogador " << endl;
				Aux.Cnivel=1;
				Records.push_back(Aux);
                 break;
			  }
                
		    }
	   SaveName ("RECORDS.txt");
       Setlevel(Aux.Cnivel);
       a=0;
  }
}
   
int esquemaJogo = 0; 
        
   do{
   	        NewGame();
            DrawBoard();
       while (IsGameOver()==0) {
       	
            und = GetMove(x,y,xf,yf);
            
			switch (und) {	
               case 'u':SaveBoard("Redo.txt");loadGame ("eladio.txt"); m_nmoves--; break;
               case 'r': loadGame("Redo.txt"); m_nmoves++; break;    
			   case 'd': PCDicas();  atualiza(); 
               default: m_nmoves++ ;SaveBoard("eladio.txt");  ExecuteMove(x,y,xf,yf); atualiza(); 
            }
            DrawBoard();      
      } 
          
		   if(IsGameOver()==-1) {
           	cout <<" GAME OVER.\n\n ";
           	cout <<"Tentar Novamente 1 " <<endl<<endl<<"Sair do Jogo 2 "<< endl;
           	int avalia;
			cin>>avalia;
			if (avalia ==1 ) {peca_eliminada=0;} 
			else if (avalia ==2 ) {esquemaJogo=1;} 
           }
           
		    if(IsGameOver()==1) {
		   	cout <<" YOU WIN \n\n ";
		    cout << "Proximo nivel 1 " <<endl<<endl<< "Sair do Jogo 2 "<< endl;
           	int avalia;
			cin>>avalia;
			if (avalia ==1 ) {aux=0;level++;} 
			else if (avalia ==2 ) {esquemaJogo=1;} 
            
           }   
   
   }while (esquemaJogo==0);
 
}
 
  
char CPudding_monster::GetPCMove(void){
	
	
   InputGameParameters();
    NewGame();
    DrawBoard(); 
    do{
    	
	int aux, i1,j1,k1,l1, max = 1; 
   for(int i=0; i<7; i++){  
        for(int j=0; j<4; j++) { 
            if (IsValid(i, j)==0){  
                 for(int k=0; k<7; k++){  
                    for(int l=0; l<4; l++) { 
                         if (IsValid2(i , j, k, l)==0) { 
                            	SaveBoard("PC.txt");  ExecuteMove(i,j,k,l);  atualiza(); aux = AvaliaTab( i, j, k, l); 
             	                if (aux>max) { max = aux;  i1 = i; j1 = j, k1=k, l1=l; }
             	                loadGame ("PC.txt"); Peca_eliminada(); 
             	        }
                   }
                }
           } 
       }
  }  
  
  ExecuteMove(i1,j1,k1,l1); atualiza();   
  DrawBoard(); 
} while (IsGameOver()==0);
if (IsGameOver()==1){cout << "PC WIN"<<endl;}
if (IsGameOver()==-1){cout << "PC LOSE"<<endl;}
 
}
void CPudding_monster::PCDicas(){
	
		int aux, i1,j1,k1,l1, max = 1; 
   for(int i=0; i<7; i++){  
        for(int j=0; j<4; j++) { 
            if (IsValid(i, j)==0){  
                 for(int k=0; k<7; k++){  
                    for(int l=0; l<4; l++) { 
                         if (IsValid2(i , j, k, l)==0) { 
                            	SaveBoard("PC.txt");  ExecuteMove(i,j,k,l);  atualiza(); aux = AvaliaTab( i, j, k, l); 
             	                if (aux>max) { max = aux;  i1 = i; j1 = j, k1=k, l1=l; }
             	                loadGame ("PC.txt"); Peca_eliminada(); 
             	        }
                   }
                }
           } 
       }
  }  
 
  ExecuteMove(i1,j1,k1,l1);// atualiza();   
 // DrawBoard(); 
}
char CPudding_monster::GetMove(int &row, int &col,int &rowf,int &colf)
{
	//Very simple interface without error verification
 char c[2], r[2];   
 char aux='a';
 int tecla,x=0;
 
do{
      cout << "Posicao Inicial(XY)" << endl;
      cin >> r;
	  if (*r=='u'){aux = 'u';break;}
	  else if (*r=='r'){aux = 'r';break;}
	   else if (*r=='d'){aux = 'd';break;}
      cin>>c;
      
      row = atoi(r); col=atoi(c); 
    
  //	do{
	
      cout << "Escolha a Direcao" <<endl;
        do{
             tecla = getch();
            
           }while (tecla==224);  
           
      switch (tecla){
                   case CIMA: colf = col; rowf = row-1;break;
                   case BAIXO: colf=col; rowf = row+1; break;
                   case ESQUERDA:colf=col-1; rowf=row; break;
                   case DIREITA:colf=col+1; rowf=row;  break;
               }
             
        
	   	 if (ValidMove(row,col,rowf,colf)!=0){
	          switch (ValidMove(row,col,rowf,colf)){
                   case 1: cout <<" Escolheste um lugar vazio para movimentar, escolha uma que tenha uma peca.\n\n "; break;
                   case 2: cout <<" Direcao invalida, tente mover a peca na horizontal ou vertical.\n\n"; break;
                   case 3: cout <<" Essa peca nao possui movimento,tente uma outra.\n\n  "; break;
                   case 4: cout <<" Os oblstaculos nao se movimentam,tente uma peca.\n\n"; break;
                   case 5: cout <<" A Posicao escolhida esta fora da matriz do jogo, tente novamente. \n\n"; break;
                   default:cout <<" Jogada Invalida. \n\n"; break;
             }    
       }
      
     

}while (ValidMove(row,col,rowf,colf)!=0);

 return aux;   
}

void CPudding_monster::DrawBoard()              
{ 
     cout << "         Moves: " << m_nmoves << endl<< endl; 
     CPudding_monsterBoard::DrawBoard(); 
}


