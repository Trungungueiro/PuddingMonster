// SameGameBoard.cpp : implementation of the CSameGameBoard class

#include "Pudding_monsterBoard.h"
#include <fstream>
#include <windows.h>
 CPudding_monsterBoard::CPudding_monsterBoard(void)
: m_arrBoard(NULL), m_nColumns(10), m_nRows(10), m_nRemaining(0), m_nColors(3)
{
  m_arrChars[0] = 0 ; m_arrChars[1] ='S'; m_arrChars[2] = 'Z';
  m_arrChars[3] ='G'; m_arrChars[4] ='-'; m_arrChars[5] = '#';
  m_arrChars[6] ='!'; m_arrChars[7] ='*'; m_arrChars[8] = '&'; 
  level =0;
  SetupBoard(); //  Create and setup the board
  
}

CPudding_monsterBoard::CPudding_monsterBoard(const CPudding_monsterBoard & board)
{
  //  Copy all of the regular data members
  m_nColumns = board.m_nColumns; m_nRows = board.m_nRows;
  //m_nHeight = board.m_nHeight; m_nWidth = board.m_nWidth;
  m_nRemaining = board.m_nRemaining;
  m_nColors = board.m_nColors;
  //for (int i = 0; i < 8; i++ ) m_arrColors[i] = board.m_arrColors[i];
  m_arrBoard = NULL;
  CreateBoard();  //  Create a new game board of the same size
  //  Copy the contents of the game board
  for(int row = 0; row < m_nRows; row++)
    for(int col = 0; col < m_nColumns; col++)
      m_arrBoard[row][col] = board.m_arrBoard[row][col];
}

 void CPudding_monsterBoard::numeros(int n) {
  printf("   "); 
  for(int i=0; i<n; i++)
      printf(" %2d ",i);
	  cout << endl;   
} 
// Função para fazer uma linha 
 void CPudding_monsterBoard::linha(int n, int d) {
   for(int i=0; i<=n; i++) {
      printf("%c%c%c%c",45,45,45,45);    
   }    
} 
void CPudding_monsterBoard::loadGame (const char *filename)
{
    ifstream input(filename);
if (!input) { cerr << "Error :  Can't Open File! "; return; }
   	
	while (!input.eof()) {
 for(int row = 0; row < m_nRows; row++)
    for(int col = 0; col < m_nColumns; col++)
 input>> m_arrBoard[row][col];
    }

}

 
 void CPudding_monsterBoard::SaveBoard(const char *filename)
 {
 	 ofstream output(filename);
	 if (!output) { cerr << "Error :  Can't save File! "; return; }
     for(int row = 0; row < m_nRows; row++){
          for(int col = 0; col < m_nColumns; col++)
          output << m_arrBoard[row][col]<<" ";
           output<<endl;}
     
    
 }

void CPudding_monsterBoard::SetNumColors(int nColors)
{
  //  Set the number of colors first and reset the game board
  m_nColors = (nColors >= 2 && nColors <= 9) ? nColors : m_nColors; 
  SetupBoard();
}

CPudding_monsterBoard::~CPudding_monsterBoard(void)
{
  DeleteBoard();  //  Simply delete the board
}

//entendido 
void CPudding_monsterBoard::SetupBoard()
{
  //  Create the board if needed
   if(m_arrBoard == NULL) CreateBoard();	
   char *teste1,*teste2,*teste3,*teste4,*teste5,*teste6,*teste7,*teste8,*teste9,*teste10,*teste11,*teste12,*teste13,*teste14,*teste15;
   
    switch (level){ 	        
                   case 1:loadGame ("teste1.txt");  break;
                   case 2:loadGame ("teste2.txt");  break;
                   case 3:loadGame ("teste3.txt");  break;
                   case 4:loadGame ("teste4.txt");  break;
                   case 5:loadGame ("teste5.txt");  break;
                   case 6:loadGame ("teste6.txt");  break;
                   case 7:loadGame ("teste7.txt");  break;
                   case 8:loadGame ("teste8.txt");  break;
                   case 9:loadGame ("teste9.txt");  break;
                   case 10:loadGame ("teste10.txt");break;
                   case 11:loadGame ("teste11.txt");break; 
                   default:loadGame ("teste2.txt"); 
    }
    
  //  Set the number of spaces remaining
     m_nRemaining = m_nRows * m_nColumns;
  
}
 
 
int CPudding_monsterBoard::GetBoardSpace(int row, int col)
{
  if(row<0 || row>=m_nRows || col<0 || col>=m_nColumns) return 0;
  return m_arrBoard[row][col];
}

void CPudding_monsterBoard::DeleteBoard(void)
{
  //  Don't delete a NULL board
  if(m_arrBoard != NULL) {
    for(int row = 0; row < m_nRows; row++) {
      if(m_arrBoard[row] != NULL){
        delete [] m_arrBoard[row];  //  Delete each row first
        m_arrBoard[row] = NULL;
      }
    }
    delete [] m_arrBoard;  //  Finally delete the array of rows
    m_arrBoard = NULL;
  }
}

 
void CPudding_monsterBoard::CreateBoard(void)
{
  //  If there is already a board, delete it
  if(m_arrBoard != NULL) DeleteBoard();
  //  Create the array of rows
  m_arrBoard = new int*[m_nRows];
  //  Create each row
  for(int row = 0; row < m_nRows; row++){
    m_arrBoard[row] = new int[m_nColumns];
    //  Set each square to be empty
    for(int col = 0; col < m_nColumns; col++)
      m_arrBoard[row][col] = 0;
  }
}

 int CPudding_monsterBoard::AvaliaTab(int i, int j, int k, int l){
      int aux=0;
     
     
          if(m_arrBoard[k][l]==1||m_arrBoard[k][l]==2||m_arrBoard[k][l]==3) aux += 10;	
          if(m_arrBoard[k][l]==5||m_arrBoard[k][l]==4||m_arrBoard[k][l]==6) aux += 6;	
          if(m_arrBoard[k][l]==7) aux += 10;
  	      if (peca_eliminada==-1) aux += -1000;
 
  	
  	return aux;
  	
  }
 
 int CPudding_monsterBoard::IsValid(int i, int j){
  if (m_arrBoard[i][j]==1||m_arrBoard[i][j]==2||m_arrBoard[i][j]==8) return 0;
 	else return -1;
 }
     int CPudding_monsterBoard::IsValid2(int i, int j, int k, int l){
       if ((m_arrBoard[k][l]==0||m_arrBoard[k][l]==4||m_arrBoard[k][l]==6) && ValidMove(i,j,k,l)==0) return 0;
       else return -1;
     	
     	
     }
 
void CPudding_monsterBoard::atualiza(void) const{

	   for(int row = 0; row < m_nRows; row++){
             for(int col = 0; col < m_nColumns; col++){
                      
                 if ((m_arrBoard[row][col]==2||m_arrBoard[row][col]==3) && 
				 (m_arrBoard[row+1][col]==1 || m_arrBoard[row-1][col]==1 || m_arrBoard[row][col+1]==1|| m_arrBoard[row][col-1]==1 ))
                 m_arrBoard[row][col] = 1; 
             }
	   } 
       
}

int  CPudding_monsterBoard::IsGameOver(void) {
	int pecas=0, avalia=0; 
    if (peca_eliminada==-1) joga++;     
	if (peca_eliminada==-1) {return -1;}
	 
	 for(int row = 0; row < m_nRows; row++){
             for(int col = 0; col < m_nColumns; col++){
             	 if (m_arrBoard[row][col]==2||m_arrBoard[row][col]==3)  return 0;
                 if (m_arrBoard[row][col]==1) pecas++;
                 }
    } 
    
	for(int row = 0; row < m_nRows; row++){
         for(int col = 0; col < m_nColumns; col++){
         	
			 if (m_arrBoard[row][col]==1){
                   avalia=1; 
				   if(m_arrBoard[row+1][col]==1) {avalia++;
				         if(m_arrBoard[row+2][col]==1) {avalia++; 
			             	 if(m_arrBoard[row+3][col]==1) {avalia++;}
					    }
			      } 
				  if (row >0){ if(m_arrBoard[row-1][col]==1) {avalia++;
				      if (row >1){ if(m_arrBoard[row-2][col]==1) {avalia++;
				          if (row >2){if(m_arrBoard[row-3][col]==1) {avalia++;}
						  }
				                   }
					  }
				               }
			     }
				 if (col >0){if(m_arrBoard[row][col-1]==1) {avalia++;	
                     if (row >0){if(m_arrBoard[row-1][col-1]==1) {avalia++;
				       if (row >1){if(m_arrBoard[row-2][col-1]==1) {avalia++;
				         if (row >2){if(m_arrBoard[row-3][col-1]==1) {avalia++;}}}}}}
				    if(m_arrBoard[row+1][col-1]==1) {avalia++;
			           if(m_arrBoard[row+2][col-1]==1) {avalia++;
				          if(m_arrBoard[row+3][col-1]==1) {avalia++;}}}
			    }}
				          
				          
				       
			   if (col >1){if(m_arrBoard[row][col-2]==1) {avalia++;	
                   if (row >0){if(m_arrBoard[row-1][col-2]==1) {avalia+=1;
				      if (row >1){if(m_arrBoard[row-2][col-2]==1) {avalia+=1;
				         if (row >2){if(m_arrBoard[row-3][col-2]==1) {avalia+=1;}}}}
				    if(m_arrBoard[row+1][col-2]==1) {avalia+=1;
			           if(m_arrBoard[row+2][col-2]==1) {avalia+=1;
				          if(m_arrBoard[row+3][col-2]==1) {avalia+=1;}}}
				  }}}} 
				  
				  if(m_arrBoard[row][col+1]==1) {avalia+=1;	
                      if(m_arrBoard[row-1][col+1]==1) {avalia+=1;
				          if(m_arrBoard[row-2][col+1]==1) {avalia+=1;
				             if(m_arrBoard[row-3][col+1]==1) {avalia+=1;}}}
				      if(m_arrBoard[row+1][col+1]==1) {avalia+=1;
			              if(m_arrBoard[row+2][col+1]==1) {avalia+=1;
				             if(m_arrBoard[row+3][col+1]==1) {avalia+=1;}}}
			     }
                  if(m_arrBoard[row][col+2]==1) {avalia+=1;	
                      if(m_arrBoard[row-1][col+2]==1) {avalia+=1;
				          if(m_arrBoard[row-2][col+2]==1) {avalia+=1;
				             if(m_arrBoard[row-3][col+2]==1) {avalia+=1;}}}
				      if(m_arrBoard[row+1][col+2]==1) {avalia+=1;
			              if(m_arrBoard[row+2][col+2]==1) {avalia+=1;
				             if(m_arrBoard[row+3][col+2]==1) {avalia+=1;}}}
			     }
            }}
        } 

		if (pecas == avalia) return 1;
	 else  return 0;
}

 

int CPudding_monsterBoard::ExecuteMove(int row, int col, int rowf, int colf)
{
  
  if (row == rowf && col < colf) { 
		    for(int i = col+1 ; i <= m_nColumns-1; i++){
	             if (m_arrBoard[row][i]==0||m_arrBoard[row][i]==4||m_arrBoard[row][i]==6) { 
	             
	                  if (m_arrBoard[row][i-1]==3){
				         m_arrBoard[row][i] = m_arrBoard[row][i-1]; m_arrBoard[row][i-1]=4;
	        	       } 
 	   		          else if (i>0){ if (m_arrBoard[row][i-1]==1){ 
					        m_arrBoard[row][i] = m_arrBoard[row][i-1]; m_arrBoard[row][i-1]=0;
 	   		       	   	    if (i>1){if (m_arrBoard[row][i-2]==1){m_arrBoard[row][i-1] = m_arrBoard[row][i-2]; m_arrBoard[row][i-2]=0;}}  
						    if (i>2){if (m_arrBoard[row][i-3]==1){m_arrBoard[row][i-2] = m_arrBoard[row][i-3]; m_arrBoard[row][i-3]=0;}}
					    
 	   		       	   	    if (row>0){ if (m_arrBoard[row-1][i-1]==1){m_arrBoard[row-1][i] = m_arrBoard[row-1][i-1]; m_arrBoard[row-1][i-1]=0; 
 	   		                    if (i>1){if (m_arrBoard[row-1][i-2]==1){m_arrBoard[row-1][i-1] = m_arrBoard[row-1][i-2]; m_arrBoard[row-1][i-2]=0;}}
						        if (i>2){ if (m_arrBoard[row-1][i-3]==1){m_arrBoard[row-1][i-2] = m_arrBoard[row-1][i-3]; m_arrBoard[row-1][i-3]=0;}} 
				         }}
						    if (m_arrBoard[row+1][i-1]==1){m_arrBoard[row+1][i] = m_arrBoard[row+1][i-1]; m_arrBoard[row+1][i-1]=0;
							  if (i>1){ if (m_arrBoard[row+1][i-2]==1){m_arrBoard[row+1][i-1] = m_arrBoard[row+1][i-2]; m_arrBoard[row+1][i-2]=0;}}		   
							  if (i>2){ if (m_arrBoard[row+1][i-3]==1){m_arrBoard[row+1][i-2] = m_arrBoard[row+1][i-3]; m_arrBoard[row+1][i-3]=0;}}		   
					    	}    }}      
	        	          
	             }
	             else break;     
			     if (i== m_nColumns-1) {m_arrBoard[row][i]=0; peca_eliminada = -1;}  
				 else if   ((m_arrBoard[row][i+1]==6 || m_arrBoard[row][i+1]==4) && m_arrBoard[row][i]==3 ) 
				 { m_arrBoard[row][i+1]=m_arrBoard[row][i]; m_arrBoard[row][i]=4;}  
				  else if (m_arrBoard[row][i+1]==6||m_arrBoard[row][i+1]==4 && m_arrBoard[row][i]!=3) 
				  { m_arrBoard[row][i+1]= m_arrBoard[row][i]; m_arrBoard[row][i]=0;} 
				 
	        }	 
  } 
 
   else if (row == rowf && col > colf){
		for(int i = col-1 ; i >= 0; i--){
	        if (m_arrBoard[row][i]== 0||m_arrBoard[row][i]==4||m_arrBoard[row][i]==6){
	        	if (m_arrBoard[row][i+1]== 3){
				    m_arrBoard[row][i] = m_arrBoard[row][i+1]; m_arrBoard[row][i+1]=4;
	        	}  
				else if (m_arrBoard[row][i+1]==1){ 
					        m_arrBoard[row][i] = m_arrBoard[row][i+1]; m_arrBoard[row][i+1]=0;
 	   		       	   	    if (m_arrBoard[row][i+2]==1){m_arrBoard[row][i+1] = m_arrBoard[row][i+2]; m_arrBoard[row][i+2]=0;  
							   if (m_arrBoard[row][i+3]==1){m_arrBoard[row][i+2] = m_arrBoard[row][i+3]; m_arrBoard[row][i+3]=0;}
							} 
 	   		       	   	    if (m_arrBoard[row-1][i+1]==1){m_arrBoard[row-1][i] = m_arrBoard[row-1][i+1]; m_arrBoard[row-1][i+1]=0; 
 	   		                    if (m_arrBoard[row-1][i+2]==1){m_arrBoard[row-1][i+1] = m_arrBoard[row-1][i+2]; m_arrBoard[row-1][i+2]=0;
						        if (m_arrBoard[row-1][i+3]==1){m_arrBoard[row-1][i+2] = m_arrBoard[row-1][i+3]; m_arrBoard[row-1][i+3]=0;}} 
						    } 	
						    if (m_arrBoard[row+1][i+1]==1){m_arrBoard[row+1][i] = m_arrBoard[row+1][i+1]; m_arrBoard[row+1][i+1]=0;
							    if (m_arrBoard[row+1][i+2]==1){m_arrBoard[row+1][i+1] = m_arrBoard[row+1][i+2]; m_arrBoard[row+1][i+2]=0;		   
							    if (m_arrBoard[row+1][i+3]==1){m_arrBoard[row+1][i-2] = m_arrBoard[row+1][i+3]; m_arrBoard[row+1][i+3]=0;}}		   
					    	}         
	            }  
	        }
	        
		        else break; 
		         if ((i) == 0){m_arrBoard[row][i]=0; peca_eliminada = -1; } 
		   
		          else if ((m_arrBoard[row][i-1]==6 || m_arrBoard[row][i-1]==4) && m_arrBoard[row][i]==3 ) 
				          { m_arrBoard[row][i-1]=m_arrBoard[row][i]; m_arrBoard[row][i]=4;}  
				  else if (m_arrBoard[row][i-1]==6||m_arrBoard[row][i-1]==4 && m_arrBoard[row][i]!=3) 
				          { m_arrBoard[row][i-1]= m_arrBoard[row][i]; m_arrBoard[row][i]=0;}    
	   }	 
  } 
  
  
  else if (col == colf && row < rowf){
		for(int i = row+1 ; i <= m_nRows-1; i++){
	        if (m_arrBoard[i][col]== 0||m_arrBoard[i][col]==4||m_arrBoard[i][col]==6){ 
	             if (m_arrBoard[i-1][col]==3){
				     m_arrBoard[i][col] = m_arrBoard[i-1][col];m_arrBoard[i-1][col]=6;
	        	}
	        	
			else if (m_arrBoard[i-1][col]==1){
				     m_arrBoard[i][col] = m_arrBoard[i-1][col];m_arrBoard[i-1][col]=0;
				if (i>1){if (m_arrBoard[i-2][col]==1){ m_arrBoard[i-1][col] = m_arrBoard[i-2][col];m_arrBoard[i-2][col]=0;
				     if (i>2){if (m_arrBoard[i-3][col]==1){ m_arrBoard[i-2][col] = m_arrBoard[i-3][col];m_arrBoard[i-3][col]=0;}}
		                 }
			    }
		    	if (m_arrBoard[i-1][col+1]==1){  m_arrBoard[i][col+1] = m_arrBoard[i-1][col+1];m_arrBoard[i-1][col+1]=0;
		            if (i>1){if (m_arrBoard[i-2][col+1]==1){ m_arrBoard[i-1][col+1] = m_arrBoard[i-2][col+1];m_arrBoard[i-2][col+1]=0;
			        if (i>2){if (m_arrBoard[i-3][col+1]==1){ m_arrBoard[i-2][col+1] = m_arrBoard[i-3][col+1];m_arrBoard[i-3][col+1]=0;}}
			        }
				 }
		    	}
			    if (m_arrBoard[i-1][col-1]==1){  m_arrBoard[i][col-1] = m_arrBoard[i-1][col-1];m_arrBoard[i-1][col-1]=0;
		            if (i>1){if (m_arrBoard[i-2][col-1]==1){ m_arrBoard[i-1][col-1] = m_arrBoard[i-2][col-1];m_arrBoard[i-2][col-1]=0;
			        if (i>2){if (m_arrBoard[i-3][col-1]==1){ m_arrBoard[i-2][col-1] = m_arrBoard[i-3][col-1];m_arrBoard[i-3][col-1]=0;}}
					        }
				   }
		       }    
	        } 
		}		   
		    else break; 
		     if ((i) == m_nRows-1){ m_arrBoard[i][col]=0; peca_eliminada = -1; }
		     else if ((m_arrBoard[i+1][col]==6 || m_arrBoard[i+1][col]==4) && m_arrBoard[i][col]==3 ) 
			     { m_arrBoard[i+1][col]=m_arrBoard[i][col]; m_arrBoard[i][col]=4;}  
				  else if (m_arrBoard[i+1][col]==6||m_arrBoard[i+1][col]==4 && m_arrBoard[i][col]!=3) 
				          { m_arrBoard[i+1][col]= m_arrBoard[i][col]; m_arrBoard[i][col]=0;}  
	   }	 
  }
   
  else if (col == colf && row > rowf){
		for(int i = row-1 ; i >= 0; i--){
	        if (m_arrBoard[i][col]== 0||m_arrBoard[i][col]==4||m_arrBoard[i][col]==6){
	            	if (m_arrBoard[i+1][col]== 3){
					m_arrBoard[i][col] = m_arrBoard[i+1][col]; m_arrBoard[i+1][col]=6;
	        	}
			    	else if (m_arrBoard[i+1][col]==1){
				          m_arrBoard[i][col] = m_arrBoard[i+1][col];m_arrBoard[i+1][col]=0;
				          if (m_arrBoard[i+2][col]==1){ m_arrBoard[i+1][col] = m_arrBoard[i+2][col];m_arrBoard[i+2][col]=0;
				            if (m_arrBoard[i+3][col]==1){ m_arrBoard[i+2][col] = m_arrBoard[i+3][col];m_arrBoard[i+3][col]=0;}
		                 } 
		                        
		            	if (m_arrBoard[i+1][col+1]==1){  m_arrBoard[i][col+1] = m_arrBoard[i+1][col+1];m_arrBoard[i+1][col+1]=0;
		                   if (m_arrBoard[i+2][col+1]==1){ m_arrBoard[i+1][col+1] = m_arrBoard[i+2][col+1];m_arrBoard[i+2][col+1]=0;
			                 if (m_arrBoard[i+3][col+1]==1){ m_arrBoard[i+2][col+1] = m_arrBoard[i+3][col+1];m_arrBoard[i+3][col+1]=0;}
			               }
				        }
		    	
			            if (m_arrBoard[i+1][col-1]==1){  m_arrBoard[i][col-1] = m_arrBoard[i+1][col-1];m_arrBoard[i+1][col-1]=0;
		                    if (m_arrBoard[i+2][col-1]==1){ m_arrBoard[i+1][col-1] = m_arrBoard[i+2][col-1];m_arrBoard[i+2][col-1]=0;
			                    if (m_arrBoard[i+3][col-1]==1){ m_arrBoard[i+2][col-1] = m_arrBoard[i+3][col-1];m_arrBoard[i+3][col-1]=0;}
					        }
				        }
		           } 
	       }		   
	    
		    else break;
		    if ((i) == 0) { m_arrBoard[i][col]=0; peca_eliminada = -1; }
		    else if ((m_arrBoard[i-1][col]==6 || m_arrBoard[i-1][col]==4) && m_arrBoard[i][col]==3 ) 
			     { m_arrBoard[i-1][col]=m_arrBoard[i][col]; m_arrBoard[i][col]=4;}  
				  else if (m_arrBoard[i-1][col]==6||m_arrBoard[i-1][col]==4 && m_arrBoard[i][col]!=3) 
				          { m_arrBoard[i-1][col]= m_arrBoard[i][col]; m_arrBoard[i][col]=0;}  
    	}
 	
}
}
     
    
	 

int CPudding_monsterBoard::DeleteNeighborBlocks(int row, int col, int color,
                                         Direction direction)
{
  //  Check if it is on the board
  if(row < 0 || row >= m_nRows || col < 0 || col >= m_nColumns) return 0;
  //  Check if it has the same color
  if(m_arrBoard[row][col] != color) return 0;
  int nCount = 1;
  m_arrBoard[row][col] = 0;
  //  If we weren't told to not go back up, check up
  if(direction != DUP)
    nCount += DeleteNeighborBlocks(row - 1, col, color, DDOWN);
  //  If we weren't told to not go back down, check down
  if(direction != DDOWN)
    nCount += DeleteNeighborBlocks(row + 1, col, color, DUP);
  //  If we wer en't told to not go back left, check left
  if(direction != DLEFT)
    nCount += DeleteNeighborBlocks(row, col - 1, color, DRIGHT);
  //  If we weren't told to not go back right, check right
  if(direction != DRIGHT)
    nCount += DeleteNeighborBlocks(row, col + 1, color, DLEFT);
  //  Return the total number of pieces deleted
  return nCount;
}

void CPudding_monsterBoard::CompactBoard(void)
{
  //  First move everything down
  for(int col = 0; col < m_nColumns; col++) {
    int nNextEmptyRow = m_nRows - 1;
    int nNextOccupiedRow = nNextEmptyRow;
    while(nNextOccupiedRow >= 0 && nNextEmptyRow >= 0)
    {
      //  First find the next empty row
      while(nNextEmptyRow >= 0 && m_arrBoard[nNextEmptyRow][col] != 0)
        nNextEmptyRow--;
      if(nNextEmptyRow >= 0) {
        //  Then find the next occupied row from the next empty row
        nNextOccupiedRow = nNextEmptyRow - 1;
        while(nNextOccupiedRow >= 0 && m_arrBoard[nNextOccupiedRow][col] == 0)
          nNextOccupiedRow--;
        if(nNextOccupiedRow >= 0) {
          //  Now move the block from occupied to empty
          m_arrBoard[nNextEmptyRow][col] = m_arrBoard[nNextOccupiedRow][col];
          m_arrBoard[nNextOccupiedRow][col] = 0;
        }
      }
    }
  }
  //  Then move everything from right to left
  int nNextEmptyCol = 0;
  int nNextOccupiedCol = nNextEmptyCol;
  while(nNextEmptyCol < m_nColumns && nNextOccupiedCol < m_nColumns)
  {
    //  First find the next empty column
    while(nNextEmptyCol < m_nColumns && m_arrBoard[m_nRows - 1][nNextEmptyCol] != 0)
      nNextEmptyCol++;
    if(nNextEmptyCol < m_nColumns){
      //  Then find the next column with something in it
      nNextOccupiedCol = nNextEmptyCol + 1;
      while(nNextOccupiedCol < m_nColumns && m_arrBoard[m_nRows - 1][nNextOccupiedCol] == 0)
        nNextOccupiedCol++;
      if(nNextOccupiedCol < m_nColumns) {
        //  Move entire column to the left
        for(int row = 0; row < m_nRows; row++){
          m_arrBoard[row][nNextEmptyCol] = m_arrBoard[row][nNextOccupiedCol];
          m_arrBoard[row][nNextOccupiedCol] = 0;
        }
      }
    }
  }
}

int  CPudding_monsterBoard::ValidMove(int row, int col, int rowf, int colf){
	
     int color = m_arrBoard[row][col];
     if (color==0) return 1; 
      // else if (row != rowf && col != colf) return 2;
       else if (color == 2) return 3;
       else if (color == 5) return 4; 
       else if(row < 0 || row >= m_nRows || col < 0 || col >= m_nColumns) return 5;
     
	  return 0;
    // if (row>0 && m_arrBoard[row-1][col]==color) return true;
    // if (row<m_nRows-1 && m_arrBoard[row+1][col]==color) return true;
    // if (col>0 && m_arrBoard[row][col-1]==color) return true;
    // if (col<m_nColumns-1 && m_arrBoard[row][col+1]==color) return true;
     //return false;
     
}

//feito_desenhar o tabuleiro  
void CPudding_monsterBoard::DrawBoard(void)
{   
   cout << "      PUDDING MONSTER " << endl << endl;
   numeros(m_nColumns);
    cout << "  ";  linha(m_nColumns,203);  cout << endl;
    for(int row = 0; row < m_nRows; row++){
    printf(" %2d%c",row,179);
    for(int col = 0; col < m_nColumns; col++){
    	if (m_arrChars[GetBoardSpace(row, col)]==1);
    	else if (m_arrChars[GetBoardSpace(row, col)]==2);
    	else if (m_arrChars[GetBoardSpace(row, col)]==5);
         cout << " " <<  m_arrChars[GetBoardSpace(row, col)];
    printf(" %c",179);
     }
     printf("%2d",row);
	 cout << endl;
	 cout << "  "; linha(m_nColumns,203);
     cout <<endl;
     
}
   numeros(m_nColumns);
   cout<< endl<<endl;

}

