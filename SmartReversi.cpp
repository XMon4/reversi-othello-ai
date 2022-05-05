#include <iostream>
#define default_attributes "\33[0m"
#include <fstream>
#include <windows.h>
#include <time.h>
using namespace std;
char box[10][10]={{'X','X','X','X','X','X','X','X','X','X'},{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},{'X','X','X','X','X','X','X','X','X','X'}};
bool move;
int  gameover,Obesty,Obestx,besty,bestx,option;
int m[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
int tm[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;


void board(){//Draw board
system("cls");
SetConsoleTextAttribute(color, 68);
cout<<"---------------------------------------------------------";
SetConsoleTextAttribute(color, 76);
cout<<"\n      1     2     3     4     5     6     7     8        \n   ";
SetConsoleTextAttribute(color, 34);
cout<<"  ________________________________________________";
for(int y=0;y<8;y++){
		SetConsoleTextAttribute(color, 34);
		cout<<" ";
		SetConsoleTextAttribute(color, 76);
	   	cout<<"   ";
		SetConsoleTextAttribute(color, 34);
		cout<<endl;
		SetConsoleTextAttribute(color, 73);
		cout<<" "<<y+1;
		SetConsoleTextAttribute(color, 71);
		cout<<" ";
		SetConsoleTextAttribute(color, 34);
		cout<<" |";	
    for(int x=0;x<8;x++){
    	if(box[y+1][x+1]==' '){SetConsoleTextAttribute(color, 170);}	
		if(box[y+1][x+1]=='@'){SetConsoleTextAttribute(color, 0);}
		if(box[y+1][x+1]=='O'){SetConsoleTextAttribute(color, 255);}
		cout<<" "<<box[y+1][x+1]<<"   ";
		SetConsoleTextAttribute(color, 34);
		cout<<"|";	}	
	SetConsoleTextAttribute(color, 34);
	cout<<" ";
	SetConsoleTextAttribute(color, 76);
	cout<<"   ";	
	SetConsoleTextAttribute(color, 34);
	cout<<endl;
	SetConsoleTextAttribute(color, 71);
	cout<<"   ";
	SetConsoleTextAttribute(color, 34);
	cout<<"  ";
	for(int s=0;s<8;s++){
    	if(box[y+1][s+1]==' '){SetConsoleTextAttribute(color, 170);}	
		if(box[y+1][s+1]=='@'){SetConsoleTextAttribute(color, 0);}
		if(box[y+1][s+1]=='O'){		SetConsoleTextAttribute(color, 240);}		
		cout<<"     ";
		SetConsoleTextAttribute(color, 34);
		cout<<"|"; }
	cout<<" ";
	SetConsoleTextAttribute(color, 76);
	cout<<"   ";	
	SetConsoleTextAttribute(color, 34);
	cout<<endl;
	SetConsoleTextAttribute(color, 71);
	cout<<"   ";
	SetConsoleTextAttribute(color, 34);
	cout<<"--------------------------------------------------";	} 		
SetConsoleTextAttribute(color, 34);
cout<<" ";
SetConsoleTextAttribute(color,68);
cout<<"   ";
SetConsoleTextAttribute(color,2);
}
void reversi2(int y, int x){//check if @ player can score
	if(box[y][x]==' '){
	if(box[y+1][x]=='O'){
 if(box[y+2][x]=='@'){
 move=true;
 box[y][x]='@';
 box[y+1][x]='@';}
 else if(box[y+2][x]=='O'){
     if(box[y+3][x]=='@'){
     	 move=true;
 box[y][x]='@';
         box[y+1][x]='@';
         box[y+2][x]='@';}
       else if(box[y+3][x]=='O'){
           if(box[y+4][x]=='@'){
           	 move=true;
 box[y][x]='@';
               box[y+1][x]='@';
               box[y+2][x]='@';
               box[y+3][x]='@';}
               else if(box[y+4][x]=='O'){
                   if(box[y+5][x]=='@'){
                   	 move=true;
 box[y][x]='@';
                       box[y+1][x]='@';
                       box[y+2][x]='@';
                       box[y+3][x]='@';
                       box[y+4][x]='@';}
                       else if(box[y+5][x]=='O'){
                           if(box[y+6][x]=='@'){
                           	 move=true;
 box[y][x]='@';
                              box[y+1][x]='@';
                            box[y+2][x]='@';
                            box[y+3][x]='@';
                            box[y+4][x]='@';  
                            box[y+5][x]='@';}
                            else if(box[y+6][x]=='O'){
                                if(box[y+7][x]=='@'){
                                	 move=true;
 box[y][x]='@';
                                     box[y+1][x]='@';
                                    box[y+2][x]='@';
                                    box[y+3][x]='@';
                                    box[y+4][x]='@';
                                    box[y+5][x]='@';
                                    box[y+6][x]='@';}}}}}}
}
if(box[y+1][x+1]=='O'){
 if(box[y+2][x+2]=='@'){
 	 move=true;
 box[y][x]='@';
 box[y+1][x+1]='@';}
 else if(box[y+2][x+2]=='O'){
     if(box[y+3][x+3]=='@'){
     	 move=true;
 box[y][x]='@';
         box[y+1][x+1]='@';
         box[y+2][x+2]='@';}
       else if(box[y+3][x+3]=='O'){
           if(box[y+4][x+4]=='@'){
           	 move=true;
 box[y][x]='@';
               box[y+1][x+1]='@';
               box[y+2][x+2]='@';
               box[y+3][x+3]='@';}
               else if(box[y+4][x+4]=='O'){
                   if(box[y+5][x+5]=='@'){
                   	 move=true;
 box[y][x]='@';
                       box[y+1][x+1]='@';
                       box[y+2][x+2]='@';
                       box[y+3][x+3]='@';
                       box[y+4][x+4]='@';}
                       else if(box[y+5][x+5]=='O'){
                           if(box[y+6][x+6]=='@'){
                           	 move=true;
 box[y][x]='@';
                              box[y+1][x+1]='@';
                            box[y+2][x+2]='@';
                            box[y+3][x+3]='@';
                            box[y+4][x+4]='@';  
                            box[y+5][x+5]='@';}
                            else if(box[y+6][x+6]=='O'){
                                if(box[y+7][x+7]=='@'){
                                	 move=true;
 box[y][x]='@';
                                     box[y+1][x+1]='@';
                                    box[y+2][x+2]='@';
                                    box[y+3][x+3]='@';
                                    box[y+4][x+4]='@';
                                    box[y+5][x+5]='@';
                                    box[y+6][x+6]='@';}}}}}}
}
if(box[y][x+1]=='O'){
 if(box[y][x+2]=='@'){
 	 move=true;
 box[y][x]='@';
 box[y][x+1]='@';}
 else if(box[y][x+2]=='O'){
     if(box[y][x+3]=='@'){
     	 move=true;
 box[y][x]='@';
         box[y][x+1]='@';
         box[y][x+2]='@';}
       else if(box[y][x+3]=='O'){
           if(box[y][x+4]=='@'){
           	 move=true;
 box[y][x]='@';
               box[y][x+1]='@';
               box[y][x+2]='@';
               box[y][x+3]='@';}
               else if(box[y][x+4]=='O'){
                   if(box[y][x+5]=='@'){
                   	 move=true;
 box[y][x]='@';
                       box[y][x+1]='@';
                       box[y][x+2]='@';
                       box[y][x+3]='@';
                       box[y][x+4]='@';}
                       else if(box[y][x+5]=='O'){
                           if(box[y][x+6]=='@'){
                           	 move=true;
 box[y][x]='@';
                              box[y][x+1]='@';
                            box[y][x+2]='@';
                            box[y][x+3]='@';
                            box[y][x+4]='@';  
                            box[y][x+5]='@';}
                            else if(box[y][x+6]=='O'){
                                if(box[y][x+7]=='@'){
                                	 move=true;
 box[y][x]='@';
                                     box[y][x+1]='@';
                                    box[y][x+2]='@';
                                    box[y][x+3]='@';
                                    box[y][x+4]='@';
                                    box[y][x+5]='@';
                                    box[y][x+6]='@';}}}}}}
}
if(box[y-1][x-1]=='O'){
 if(box[y-2][x-2]=='@'){
 	 move=true;
 box[y][x]='@';
 box[y-1][x-1]='@';}
 else if(box[y-2][x-2]=='O'){
     if(box[y-3][x-3]=='@'){
     	 move=true;
 box[y][x]='@';
         box[y-1][x-1]='@';
         box[y-2][x-2]='@';}
       else if(box[y-3][x-3]=='O'){
           if(box[y-4][x-4]=='@'){
           	 move=true;
 box[y][x]='@';
               box[y-1][x-1]='@';
               box[y-2][x-2]='@';
               box[y-3][x-3]='@';}
               else if(box[y-4][x-4]=='O'){
                   if(box[y-5][x-5]=='@'){
                   	 move=true;
 box[y][x]='@';
                       box[y-1][x-1]='@';
                       box[y-2][x-2]='@';
                       box[y-3][x-3]='@';
                       box[y-4][x-4]='@';}
                       else if(box[y-5][x-5]=='O'){
                           if(box[y-6][x-6]=='@'){
                           	 move=true;
 box[y][x]='@';
                              box[y-1][x-1]='@';
                            box[y-2][x-2]='@';
                            box[y-3][x-3]='@';
                            box[y-4][x-4]='@';  
                            box[y-5][x-5]='@';}
                            else if(box[y-6][x-6]=='O'){
                                if(box[y-7][x-7]=='@'){
                                	 move=true;
 box[y][x]='@';
                                     box[y-1][x-1]='@';
                                    box[y-2][x-2]='@';
                                    box[y-3][x-3]='@';
                                    box[y-4][x-4]='@';
                                    box[y-5][x-5]='@';
                                    box[y-6][x-6]='@';}}}}}}
}
if(box[y-1][x]=='O'){
 if(box[y-2][x]=='@'){
 	 move=true;
 box[y][x]='@';
 box[y-1][x]='@';}
 else if(box[y-2][x]=='O'){
     if(box[y-3][x]=='@'){
     	 move=true;
 box[y][x]='@';
         box[y-1][x]='@';
         box[y-2][x]='@';}
       else if(box[y-3][x]=='O'){
           if(box[y-4][x]=='@'){
           	 move=true;
 box[y][x]='@';
               box[y-1][x]='@';
               box[y-2][x]='@';
               box[y-3][x]='@';}
               else if(box[y-4][x]=='O'){
                   if(box[y-5][x]=='@'){
                   	 move=true;
 box[y][x]='@';
                       box[y-1][x]='@';
                       box[y-2][x]='@';
                       box[y-3][x]='@';
                       box[y-4][x]='@';}
                       else if(box[y-5][x]=='O'){
                           if(box[y-6][x]=='@'){
                           	 move=true;
 box[y][x]='@';
                              box[y-1][x]='@';
                            box[y-2][x]='@';
                            box[y-3][x]='@';
                            box[y-4][x]='@';  
                            box[y-5][x]='@';}
                            else if(box[y-6][x]=='O'){
                                if(box[y-7][x]=='@'){
                                	 move=true;
 box[y][x]='@';
                                     box[y-1][x]='@';
                                    box[y-2][x]='@';
                                    box[y-3][x]='@';
                                    box[y-4][x]='@';
                                    box[y-5][x]='@';
                                    box[y-6][x]='@';}}}}}}
}
if(box[y][x-1]=='O'){
 if(box[y][x-2]=='@'){
 	 move=true;
 box[y][x]='@';
 box[y][x-1]='@';}
 else if(box[y][x-2]=='O'){
     if(box[y][x-3]=='@'){
     	 move=true;
 box[y][x]='@';
         box[y][x-1]='@';
         box[y][x-2]='@';}
       else if(box[y][x-3]=='O'){
           if(box[y][x-4]=='@'){
           	 move=true;
 box[y][x]='@';
               box[y][x-1]='@';
               box[y][x-2]='@';
               box[y][x-3]='@';}
               else if(box[y][x-4]=='O'){
                   if(box[y][x-5]=='@'){
                   	 move=true;
 box[y][x]='@';
                       box[y][x-1]='@';
                       box[y][x-2]='@';
                       box[y][x-3]='@';
                       box[y][x-4]='@';}
                       else if(box[y][x-5]=='O'){
                           if(box[y][x-6]=='@'){
                           	 move=true;
 box[y][x]='@';
                              box[y][x-1]='@';
                            box[y][x-2]='@';
                            box[y][x-3]='@';
                            box[y][x-4]='@';  
                            box[y][x-5]='@';}
                            else if(box[y][x-6]=='O'){
                                if(box[y][x-7]=='@'){
                                	 move=true;
 box[y][x]='@';
                                     box[y][x-1]='@';
                                    box[y][x-2]='@';
                                    box[y][x-3]='@';
                                    box[y][x-4]='@';
                                    box[y][x-5]='@';
                                    box[y][x-6]='@';}}}}}}
}
if(box[y+1][x-1]=='O'){
 if(box[y+2][x-2]=='@'){
 	 move=true;
 box[y][x]='@';
 box[y+1][x-1]='@';}
 else if(box[y+2][x-2]=='O'){
     if(box[y+3][x-3]=='@'){
     	 move=true;
 box[y][x]='@';
         box[y+1][x-1]='@';
         box[y+2][x-2]='@';}
       else if(box[y+3][x-3]=='O'){
           if(box[y+4][x-4]=='@'){
           	 move=true;
 box[y][x]='@';
               box[y+1][x-1]='@';
               box[y+2][x-2]='@';
               box[y+3][x-3]='@';}
               else if(box[y+4][x-4]=='O'){
                   if(box[y+5][x-5]=='@'){
                   	 move=true;
 box[y][x]='@';
                       box[y+1][x-1]='@';
                       box[y+2][x-2]='@';
                       box[y+3][x-3]='@';
                       box[y+4][x-4]='@';}
                       else if(box[y+5][x-5]=='O'){
                           if(box[y+6][x-6]=='@'){
                           	 move=true;
 box[y][x]='@';
                              box[y+1][x-1]='@';
                            box[y+2][x-2]='@';
                            box[y+3][x-3]='@';
                            box[y+4][x-4]='@';  
                            box[y+5][x-5]='@';}
                            else if(box[y+6][x-6]=='O'){
                                if(box[y+7][x-7]=='@'){
                                	 move=true;
 box[y][x]='@';
                                     box[y+1][x-1]='@';
                                    box[y+2][x-2]='@';
                                    box[y+3][x-3]='@';
                                    box[y+4][x-4]='@';
                                    box[y+5][x-5]='@';
                                    box[y+6][x-6]='@';}}}}}}
}
if(box[y-1][x+1]=='O'){
 if(box[y-2][x+2]=='@'){
 	 move=true;
 box[y][x]='@';
 box[y-1][x+1]='@';}
 else if(box[y-2][x+2]=='O'){
     if(box[y-3][x+3]=='@'){
     	 move=true;
 box[y][x]='@';
         box[y-1][x+1]='@';
         box[y-2][x+2]='@';}
       else if(box[y-3][x+3]=='O'){
           if(box[y-4][x+4]=='@'){
           	 move=true;
 box[y][x]='@';
               box[y-1][x+1]='@';
               box[y-2][x+2]='@';
               box[y-3][x+3]='@';}
               else if(box[y-4][x+4]=='O'){
                   if(box[y-5][x+5]=='@'){
                   	 move=true;
 box[y][x]='@';
                       box[y-1][x+1]='@';
                       box[y-2][x+2]='@';
                       box[y-3][x+3]='@';
                       box[y-4][x+4]='@';}
                       else if(box[y-5][x+5]=='O'){
                           if(box[y-6][x+6]=='@'){
                           	 move=true;
 box[y][x]='@';
                              box[y-1][x+1]='@';
                            box[y-2][x+2]='@';
                            box[y-3][x+3]='@';
                            box[y-4][x+4]='@';  
                            box[y-5][x+5]='@';}
                            else if(box[y-6][x+6]=='O'){
                                if(box[y-7][x+7]=='@'){
                                	 move=true;
 box[y][x]='@';
                                     box[y-1][x+1]='@';
                                    box[y-2][x+2]='@';
                                    box[y-3][x+3]='@';
                                    box[y-4][x+4]='@';
                                    box[y-5][x+5]='@';
                                    box[y-6][x+6]='@';}}}}}}
}}}
void reversiO(int ey, int ex){//check if player O can score
if(box[ey][ex]==' '){
	if(box[ey+1][ex]=='@'){
 if(box[ey+2][ex]=='O'){
 	 move=true;
 box[ey][ex]='O';
 box[ey+1][ex]='O';}
 else if(box[ey+2][ex]=='@'){
     if(box[ey+3][ex]=='O'){
     	 move=true;
 		box[ey][ex]='O';
         box[ey+1][ex]='O';
         box[ey+2][ex]='O';}
       else if(box[ey+3][ex]=='@'){
           if(box[ey+4][ex]=='O'){
           	move=true;
 		box[ey][ex]='O';
               box[ey+1][ex]='O';
               box[ey+2][ex]='O';
               box[ey+3][ex]='O';}
               else if(box[ey+4][ex]=='@'){
                   if(box[ey+5][ex]=='O'){
                   	move=true;
 		box[ey][ex]='O';
                       box[ey+1][ex]='O';
                       box[ey+2][ex]='O';
                       box[ey+3][ex]='O';
                       box[ey+4][ex]='O';}
                       else if(box[ey+5][ex]=='@'){
                           if(box[ey+6][ex]=='O'){
                           	move=true;
 		box[ey][ex]='O';
                              box[ey+1][ex]='O';
                            box[ey+2][ex]='O';
                            box[ey+3][ex]='O';
                            box[ey+4][ex]='O';  
                            box[ey+5][ex]='O';}
                            else if(box[ey+6][ex]=='@'){
                                if(box[ey+7][ex]=='O'){
                                	move=true;
 		box[ey][ex]='O';
                                     box[ey+1][ex]='O';
                                    box[ey+2][ex]='O';
                                    box[ey+3][ex]='O';
                                    box[ey+4][ex]='O';
                                    box[ey+5][ex]='O';
                                    box[ey+6][ex]='O';}}}}}}
}
if(box[ey+1][ex+1]=='@'){
 if(box[ey+2][ex+2]=='O'){
 	move=true;
 		box[ey][ex]='O';
 box[ey+1][ex+1]='O';}
 else if(box[ey+2][ex+2]=='@'){
     if(box[ey+3][ex+3]=='O'){
     	move=true;
 		box[ey][ex]='O';
         box[ey+1][ex+1]='O';
         box[ey+2][ex+2]='O';}
       else if(box[ey+3][ex+3]=='@'){
           if(box[ey+4][ex+4]=='O'){
           	move=true;
 		box[ey][ex]='O';
               box[ey+1][ex+1]='O';
               box[ey+2][ex+2]='O';
               box[ey+3][ex+3]='O';}
               else if(box[ey+4][ex+4]=='@'){
                   if(box[ey+5][ex+5]=='O'){
                   	move=true;
 		box[ey][ex]='O';
                       box[ey+1][ex+1]='O';
                       box[ey+2][ex+2]='O';
                       box[ey+3][ex+3]='O';
                       box[ey+4][ex+4]='O';}
                       else if(box[ey+5][ex+5]=='@'){
                           if(box[ey+6][ex+6]=='O'){
                           	move=true;
 		box[ey][ex]='O';
         box[ey+1][ex+1]='O';
                            box[ey+2][ex+2]='O';
                            box[ey+3][ex+3]='O';
                            box[ey+4][ex+4]='O';  
                            box[ey+5][ex+5]='O';}
                            else if(box[ey+6][ex+6]=='@'){
                                if(box[ey+7][ex+7]=='O'){
                                	move=true;
 		box[ey][ex]='O';
                                    box[ey+1][ex+1]='O';
                                    box[ey+2][ex+2]='O';
                                    box[ey+3][ex+3]='O';
                                    box[ey+4][ex+4]='O';
                                    box[ey+5][ex+5]='O';
                                    box[ey+6][ex+6]='O';}}}}}}
}
if(box[ey][ex+1]=='@'){
 if(box[ey][ex+2]=='O'){
 	move=true;
 		box[ey][ex]='O';
 box[ey][ex+1]='O';}
 else if(box[ey][ex+2]=='@'){
     if(box[ey][ex+3]=='O'){
     	move=true;
 		box[ey][ex]='O';
         box[ey][ex+1]='O';
         box[ey][ex+2]='O';}
       else if(box[ey][ex+3]=='@'){
           if(box[ey][ex+4]=='O'){
           	move=true;
 		box[ey][ex]='O';
               box[ey][ex+1]='O';
               box[ey][ex+2]='O';
               box[ey][ex+3]='O';}
               else if(box[ey][ex+4]=='@'){
                   if(box[ey][ex+5]=='O'){
                   	move=true;
 		box[ey][ex]='O';
                       box[ey][ex+1]='O';
                       box[ey][ex+2]='O';
                       box[ey][ex+3]='O';
                       box[ey][ex+4]='O';}
                       else if(box[ey][ex+5]=='@'){
                           if(box[ey][ex+6]=='O'){
                           	move=true;
 		box[ey][ex]='O';
                              box[ey][ex+1]='O';
                            box[ey][ex+2]='O';
                            box[ey][ex+3]='O';
                            box[ey][ex+4]='O';  
                            box[ey][ex+5]='O';}
                            else if(box[ey][ex+6]=='@'){
                                if(box[ey][ex+7]=='O'){
                                	move=true;
 		box[ey][ex]='O';
                                    box[ey][ex+1]='O';
                                    box[ey][ex+2]='O';
                                    box[ey][ex+3]='O';
                                    box[ey][ex+4]='O';
                                    box[ey][ex+5]='O';
                                    box[ey][ex+6]='O';}}}}}}
}
if(box[ey-1][ex-1]=='@'){
 if(box[ey-2][ex-2]=='O'){
 	move=true;
 		box[ey][ex]='O';
 box[ey-1][ex-1]='O';}
 else if(box[ey-2][ex-2]=='@'){
     if(box[ey-3][ex-3]=='O'){
     	move=true;
 		box[ey][ex]='O';
         box[ey-1][ex-1]='O';
         box[ey-2][ex-2]='O';}
       else if(box[ey-3][ex-3]=='@'){
           if(box[ey-4][ex-4]=='O'){
           	move=true;
 		box[ey][ex]='O';
               box[ey-1][ex-1]='O';
               box[ey-2][ex-2]='O';
               box[ey-3][ex-3]='O';}
               else if(box[ey-4][ex-4]=='@'){
                   if(box[ey-5][ex-5]=='O'){
                   	move=true;
 		box[ey][ex]='O';
                       box[ey-1][ex-1]='O';
                       box[ey-2][ex-2]='O';
                       box[ey-3][ex-3]='O';
                       box[ey-4][ex-4]='O';}
                       else if(box[ey-5][ex-5]=='@'){
                           if(box[ey-6][ex-6]=='O'){
                           	move=true;
 		box[ey][ex]='O';
                              box[ey-1][ex-1]='O';
                            box[ey-2][ex-2]='O';
                            box[ey-3][ex-3]='O';
                            box[ey-4][ex-4]='O';  
                            box[ey-5][ex-5]='O';}
                            else if(box[ey-6][ex-6]=='@'){
                                if(box[ey-7][ex-7]=='O'){
                                	move=true;
 		box[ey][ex]='O';
                                    box[ey-1][ex-1]='O';
                                    box[ey-2][ex-2]='O';
                                    box[ey-3][ex-3]='O';
                                    box[ey-4][ex-4]='O';
                                    box[ey-5][ex-5]='O';
                                    box[ey-6][ex-6]='O';}}}}}}
}
if(box[ey-1][ex]=='@'){
 if(box[ey-2][ex]=='O'){
 	move=true;
 		box[ey][ex]='O';
 box[ey-1][ex]='O';}
 else if(box[ey-2][ex]=='@'){
     if(box[ey-3][ex]=='O'){
     	move=true;
 		box[ey][ex]='O';
         box[ey-1][ex]='O';
         box[ey-2][ex]='O';}
       else if(box[ey-3][ex]=='@'){
           if(box[ey-4][ex]=='O'){
           	move=true;
 		box[ey][ex]='O';
               box[ey-1][ex]='O';
               box[ey-2][ex]='O';
               box[ey-3][ex]='O';}
               else if(box[ey-4][ex]=='@'){
                   if(box[ey-5][ex]=='O'){
                   	move=true;
 		box[ey][ex]='O';
                       box[ey-1][ex]='O';
                       box[ey-2][ex]='O';
                       box[ey-3][ex]='O';
                       box[ey-4][ex]='O';}
                       else if(box[ey-5][ex]=='@'){
                           if(box[ey-6][ex]=='O'){
                           	move=true;
 		box[ey][ex]='O';
                              box[ey-1][ex]='O';
                            box[ey-2][ex]='O';
                            box[ey-3][ex]='O';
                            box[ey-4][ex]='O';  
                            box[ey-5][ex]='O';}
                            else if(box[ey-6][ex]=='@'){
                                if(box[ey-7][ex]=='O'){
                                	move=true;
 		box[ey][ex]='O';
                                     box[ey-1][ex]='O';
                                    box[ey-2][ex]='O';
                                    box[ey-3][ex]='O';
                                    box[ey-4][ex]='O';
                                    box[ey-5][ex]='O';
                                    box[ey-6][ex]='O';}}}}}}
}
if(box[ey][ex-1]=='@'){
 if(box[ey][ex-2]=='O'){
 	move=true;
 		box[ey][ex]='O';
 box[ey][ex-1]='O';}
 else if(box[ey][ex-2]=='@'){
     if(box[ey][ex-3]=='O'){
     	move=true;
 		box[ey][ex]='O';
         box[ey][ex-1]='O';
         box[ey][ex-2]='O';}
       else if(box[ey][ex-3]=='@'){
           if(box[ey][ex-4]=='O'){
           	move=true;
 		box[ey][ex]='O';
               box[ey][ex-1]='O';
               box[ey][ex-2]='O';
               box[ey][ex-3]='O';}
               else if(box[ey][ex-4]=='@'){
                   if(box[ey][ex-5]=='O'){
                   	move=true;
 		box[ey][ex]='O';
                       box[ey][ex-1]='O';
                       box[ey][ex-2]='O';
                       box[ey][ex-3]='O';
                       box[ey][ex-4]='O';}
                       else if(box[ey][ex-5]=='@'){
                           if(box[ey][ex-6]=='O'){
                           	move=true;
 		box[ey][ex]='O';
                            box[ey][ex-1]='O';
                            box[ey][ex-2]='O';
                            box[ey][ex-3]='O';
                            box[ey][ex-4]='O';  
                            box[ey][ex-5]='O';}
                            else if(box[ey][ex-6]=='@'){
                                if(box[ey][ex-7]=='O'){
                                	move=true;
 		box[ey][ex]='O';
                                    box[ey][ex-1]='O';
                                    box[ey][ex-2]='O';
                                    box[ey][ex-3]='O';
                                    box[ey][ex-4]='O';
                                    box[ey][ex-5]='O';
                                    box[ey][ex-6]='O';}}}}}}
}
if(box[ey+1][ex-1]=='@'){
 if(box[ey+2][ex-2]=='O'){
 	move=true;
 		box[ey][ex]='O';
 box[ey+1][ex-1]='O';}
 else if(box[ey+2][ex-2]=='@'){
     if(box[ey+3][ex-3]=='O'){
     	move=true;
 		box[ey][ex]='O';
         box[ey+1][ex-1]='O';
         box[ey+2][ex-2]='O';}
       else if(box[ey+3][ex-3]=='@'){
           if(box[ey+4][ex-4]=='O'){
           	move=true;
 		box[ey][ex]='O';
               box[ey+1][ex-1]='O';
               box[ey+2][ex-2]='O';
               box[ey+3][ex-3]='O';}
               else if(box[ey+4][ex-4]=='@'){
                   if(box[ey+5][ex-5]=='O'){
                   	move=true;
 		box[ey][ex]='O';
                       box[ey+1][ex-1]='O';
                       box[ey+2][ex-2]='O';
                       box[ey+3][ex-3]='O';
                       box[ey+4][ex-4]='O';}
                       else if(box[ey+5][ex-5]=='@'){
                           if(box[ey+6][ex-6]=='O'){
                           	move=true;
 		box[ey][ex]='O';
                            box[ey+1][ex-1]='O';
                            box[ey+2][ex-2]='O';
                            box[ey+3][ex-3]='O';
                            box[ey+4][ex-4]='O';  
                            box[ey+5][ex-5]='O';}
                            else if(box[ey+6][ex-6]=='@'){
                                if(box[ey+7][ex-7]=='O'){
                                	move=true;
 		box[ey][ex]='O';
                                    box[ey+1][ex-1]='O';
                                    box[ey+2][ex-2]='O';
                                    box[ey+3][ex-3]='O';
                                    box[ey+4][ex-4]='O';
                                    box[ey+5][ex-5]='O';
                                    box[ey+6][ex-6]='O';}}}}}}
}
if(box[ey-1][ex+1]=='@'){
 if(box[ey-2][ex+2]=='O'){
 	move=true;
 		box[ey][ex]='O';
 box[ey-1][ex+1]='O';}
 else if(box[ey-2][ex+2]=='@'){
     if(box[ey-3][ex+3]=='O'){
     	move=true;
 		box[ey][ex]='O';
         box[ey-1][ex+1]='O';
         box[ey-2][ex+2]='O';}
       else if(box[ey-3][ex+3]=='@'){
           if(box[ey-4][ex+4]=='O'){
           	move=true;
 		box[ey][ex]='O';
               box[ey-1][ex+1]='O';
               box[ey-2][ex+2]='O';
               box[ey-3][ex+3]='O';}
               else if(box[ey-4][ex+4]=='@'){
                   if(box[ey-5][ex+5]=='O'){
                   	move=true;
 		box[ey][ex]='O';
                       box[ey-1][ex+1]='O';
                       box[ey-2][ex+2]='O';
                       box[ey-3][ex+3]='O';
                       box[ey-4][ex+4]='O';}
                       else if(box[ey-5][ex+5]=='@'){
                           if(box[ey-6][ex+6]=='O'){
                           	move=true;
 		box[ey][ex]='O';
                              box[ey-1][ex+1]='O';
                            box[ey-2][ex+2]='O';
                            box[ey-3][ex+3]='O';
                            box[ey-4][ex+4]='O';  
                            box[ey-5][ex+5]='O';}
                            else if(box[ey-6][ex+6]=='@'){
                                if(box[ey-7][ex+7]=='O'){
                                	move=true;
 		box[ey][ex]='O';
                                    box[ey-1][ex+1]='O';
                                    box[ey-2][ex+2]='O';
                                    box[ey-3][ex+3]='O';
                                    box[ey-4][ex+4]='O';
                                    box[ey-5][ex+5]='O';
                                    box[ey-6][ex+6]='O';}}}}}}
}}}
void checkO(){//check if there are possible moves left for O
	    for(int y=1;y<9;y++){
	   	for(int x=1;x<9;x++){
    		if(box[y][x]==' '){
			box[y][x]='O';
				if(box[y+1][x]=='@'){
 if(box[y+2][x]=='O'){
 	 move=false;}
 else if(box[y+2][x]=='@'){
     if(box[y+3][x]=='O'){
     	 move=false;}
else if(box[y+3][x]=='@'){
           if(box[y+4][x]=='O'){
           	move=false;}
 else if(box[y+4][x]=='@'){
                   if(box[y+5][x]=='O'){
                   	move=false;}
    else if(box[y+5][x]=='@'){
                           if(box[y+6][x]=='O'){
                           	move=false;}
else if(box[y+6][x]=='@'){
                                if(box[y+7][x]=='O'){
                                	move=false;}}}}}}}
if(box[y+1][x+1]=='@'){
 if(box[y+2][x+2]=='O'){
 	move=false;}
 else if(box[y+2][x+2]=='@'){
     if(box[y+3][x+3]=='O'){
     	move=false;}
 else if(box[y+3][x+3]=='@'){
           if(box[y+4][x+4]=='O'){
           	move=false;}
else if(box[y+4][x+4]=='@'){
                   if(box[y+5][x+5]=='O'){
                   	move=false;}
 else if(box[y+5][x+5]=='@'){
                           if(box[y+6][x+6]=='O'){
                           	move=false;}
else if(box[y+6][x+6]=='@'){
                                if(box[y+7][x+7]=='O'){
                                	move=false;}}}}}}}
if(box[y][x+1]=='@'){
 if(box[y][x+2]=='O'){
 	move=false;}
 else if(box[y][x+2]=='@'){
     if(box[y][x+3]=='O'){
     	move=false;}
 else if(box[y][x+3]=='@'){
           if(box[y][x+4]=='O'){
           	move=false;}
else if(box[y][x+4]=='@'){
                   if(box[y][x+5]=='O'){
                   	move=false;}
else if(box[y][x+5]=='@'){
                           if(box[y][x+6]=='O'){
                           	move=false;}
else if(box[y][x+6]=='@'){
                                if(box[y][x+7]=='O'){
                                	move=false;}}}}}}}
if(box[y-1][x-1]=='@'){
 if(box[y-2][x-2]=='O'){
 	move=false;}
 else if(box[y-2][x-2]=='@'){
     if(box[y-3][x-3]=='O'){
     	move=false; }
else if(box[y-3][x-3]=='@'){
           if(box[y-4][x-4]=='O'){
           	move=false;}
else if(box[y-4][x-4]=='@'){
                   if(box[y-5][x-5]=='O'){
                   	move=false;}
else if(box[y-5][x-5]=='@'){
                           if(box[y-6][x-6]=='O'){
                           	move=false;}
else if(box[y-6][x-6]=='@'){
                if(box[y-7][x-7]=='O'){
               	move=false;}}}}}}}
if(box[y-1][x]=='@'){
 if(box[y-2][x]=='O'){
 	move=false;}
else if(box[y-2][x]=='@'){
     if(box[y-3][x]=='O'){
     	move=false;}
 else if(box[y-3][x]=='@'){
           if(box[y-4][x]=='O'){
           	move=false;}
 else if(box[y-4][x]=='@'){
                   if(box[y-5][x]=='O'){
                   	move=false;}
else if(box[y-5][x]=='@'){
                           if(box[y-6][x]=='O'){
                           	move=false;}
 else if(box[y-6][x]=='@'){
                                if(box[y-7][x]=='O'){
                                	move=false;}}}}}}}
if(box[y][x-1]=='@'){
 if(box[y][x-2]=='O'){
 	move=false;}
 else if(box[y][x-2]=='@'){
     if(box[y][x-3]=='O'){
     	move=false;}
else if(box[y][x-3]=='@'){
           if(box[y][x-4]=='O'){
           	move=false;}
 else if(box[y][x-4]=='@'){
                   if(box[y][x-5]=='O'){
                   	move=false;}
 else if(box[y][x-5]=='@'){
                           if(box[y][x-6]=='O'){
                           	move=false;}
else if(box[y][x-6]=='@'){
                                if(box[y][x-7]=='O'){
                                	move=false;}}}}}}}
if(box[y+1][x-1]=='@'){
 if(box[y+2][x-2]=='O'){
 	move=false; }
else if(box[y+2][x-2]=='@'){
     if(box[y+3][x-3]=='O'){
     	move=false; }
else if(box[y+3][x-3]=='@'){
           if(box[y+4][x-4]=='O'){
           	move=false;}
 else if(box[y+4][x-4]=='@'){
                   if(box[y+5][x-5]=='O'){
                   	move=false;}
 else if(box[y+5][x-5]=='@'){
                           if(box[y+6][x-6]=='O'){
                           	move=false; }
else if(box[y+6][x-6]=='@'){
                                if(box[y+7][x-7]=='O'){
                                	move=false;}}}}}}}
if(box[y-1][x+1]=='@'){
 if(box[y-2][x+2]=='O'){
 	move=false;}
 else if(box[y-2][x+2]=='@'){
     if(box[y-3][x+3]=='O'){
     	move=false;}
       else if(box[y-3][x+3]=='@'){
           if(box[y-4][x+4]=='O'){
           	move=false;}
else if(box[y-4][x+4]=='@'){
                   if(box[y-5][x+5]=='O'){
                   	move=false;}
   else if(box[y-5][x+5]=='@'){
                           if(box[y-6][x+6]=='O'){
                           	move=false;}
else if(box[y-6][x+6]=='@'){
                                if(box[y-7][x+7]=='O'){
                                	move=false;}}}}}}}
				box[y][x]=' ';}}}
				if(move!=false){ Beep(500,500);
			cout<<"No possible moves! Skipping turn\n";
			Sleep(1000);
		 move=true;
			gameover++;}
}
void check2(){//checkss possibilisties for @
	    for(int y=1;y<9;y++){
	   	for(int x=1;x<9;x++){
    		if(box[y][x]==' '){
			box[y][x]='@';
if(box[y+1][x]=='O'){
 if(box[y+2][x]=='@'){
 move=false;}
else if(box[y+2][x]=='O'){
     if(box[y+3][x]=='@'){
     	 move=false;}
else if(box[y+3][x]=='O'){
           if(box[y+4][x]=='@'){
           	 move=false;}
 else if(box[y+4][x]=='O'){
                   if(box[y+5][x]=='@'){
                   	 move=false;}
else if(box[y+5][x]=='O'){
                           if(box[y+6][x]=='@'){
                           	 move=false;}
else if(box[y+6][x]=='O'){
                                if(box[y+7][x]=='@'){
                                	 move=false;}}}}}}}
if(box[y+1][x+1]=='O'){
 if(box[y+2][x+2]=='@'){
 	 move=false;}
else if(box[y+2][x+2]=='O'){
     if(box[y+3][x+3]=='@'){
     	 move=false;}
 else if(box[y+3][x+3]=='O'){
           if(box[y+4][x+4]=='@'){
           	 move=false;}
else if(box[y+4][x+4]=='O'){
                   if(box[y+5][x+5]=='@'){
                   	 move=false;}
 else if(box[y+5][x+5]=='O'){
                           if(box[y+6][x+6]=='@'){
                           	 move=false;}
 else if(box[y+6][x+6]=='O'){
                                if(box[y+7][x+7]=='@'){
                                	 move=false;}}}}}}}
 if(box[y][x+1]=='O'){
 if(box[y][x+2]=='@'){
 	 move=false;}
 else if(box[y][x+2]=='O'){
     if(box[y][x+3]=='@'){
     	 move=false;}
      else if(box[y][x+3]=='O'){
           if(box[y][x+4]=='@'){
           	 move=false;}
               else if(box[y][x+4]=='O'){
                   if(box[y][x+5]=='@'){
                   	 move=false;}
else if(box[y][x+5]=='O'){
                           if(box[y][x+6]=='@'){
                           	 move=false;}
 else if(box[y][x+6]=='O'){
                                if(box[y][x+7]=='@'){
                                	 move=false;}}}}}}}
if(box[y-1][x-1]=='O'){
 if(box[y-2][x-2]=='@'){
 	 move=false;}
 else if(box[y-2][x-2]=='O'){
     if(box[y-3][x-3]=='@'){
     	 move=false;}
 else if(box[y-3][x-3]=='O'){
           if(box[y-4][x-4]=='@'){
           	 move=false;}
 else if(box[y-4][x-4]=='O'){
                   if(box[y-5][x-5]=='@'){
                   	 move=false;}
  else if(box[y-5][x-5]=='O'){
                           if(box[y-6][x-6]=='@'){
                           	 move=false;}
else if(box[y-6][x-6]=='O'){
                                if(box[y-7][x-7]=='@'){
                                	 move=false;}}}}}}}
if(box[y-1][x]=='O'){
 if(box[y-2][x]=='@'){
 	 move=false;}
else if(box[y-2][x]=='O'){
     if(box[y-3][x]=='@'){
     	 move=false;}
else if(box[y-3][x]=='O'){
           if(box[y-4][x]=='@'){
           	 move=false;}
else if(box[y-4][x]=='O'){
                   if(box[y-5][x]=='@'){
                   	 move=false;}
else if(box[y-5][x]=='O'){
                           if(box[y-6][x]=='@'){
                           	 move=false;}
else if(box[y-6][x]=='O'){
                                if(box[y-7][x]=='@'){
                                	 move=false;}}}}}}}
if(box[y][x-1]=='O'){
 if(box[y][x-2]=='@'){
 	 move=false;}
else if(box[y][x-2]=='O'){
     if(box[y][x-3]=='@'){
     	 move=false;}
else if(box[y][x-3]=='O'){
           if(box[y][x-4]=='@'){
           	 move=false;}
else if(box[y][x-4]=='O'){
                   if(box[y][x-5]=='@'){
                   	 move=false;}
else if(box[y][x-5]=='O'){
                           if(box[y][x-6]=='@'){
                           	 move=false;}
else if(box[y][x-6]=='O'){
                                if(box[y][x-7]=='@'){
                                	 move=false;}}}}}}}
if(box[y+1][x-1]=='O'){
 if(box[y+2][x-2]=='@'){
 	 move=false;}
else if(box[y+2][x-2]=='O'){
     if(box[y+3][x-3]=='@'){
     	 move=false;}
else if(box[y+3][x-3]=='O'){
           if(box[y+4][x-4]=='@'){
           	 move=false;}
 else if(box[y+4][x-4]=='O'){
                   if(box[y+5][x-5]=='@'){
                   	 move=false;}
else if(box[y+5][x-5]=='O'){
                           if(box[y+6][x-6]=='@'){
                           	 move=false;}
else if(box[y+6][x-6]=='O'){
                                if(box[y+7][x-7]=='@'){
                                	 move=false;}}}}}}}
if(box[y-1][x+1]=='O'){
 if(box[y-2][x+2]=='@'){
 	 move=false;}
 else if(box[y-2][x+2]=='O'){
     if(box[y-3][x+3]=='@'){
     	 move=false;}
else if(box[y-3][x+3]=='O'){
           if(box[y-4][x+4]=='@'){
           	 move=false;}
else if(box[y-4][x+4]=='O'){
                   if(box[y-5][x+5]=='@'){
                   	 move=false;}
else if(box[y-5][x+5]=='O'){
                           if(box[y-6][x+6]=='@'){
                           	 move=false;}
else if(box[y-6][x+6]=='O'){
                                if(box[y-7][x+7]=='@'){
                                	 move=false;}}}}}}}
				box[y][x]=' ';}}}
				if(move!=false){ Beep(500,500);
			cout<<"No possible moves! Skipping turn \n";
			Sleep(1000);
			move=true;
			gameover++;}
}
void aiturn(){//AI DECIDE WHAT MOVE CAN BE PLAYED
int bestmove=-1000;
int p=0,ax[20],ay[20];
for(int r=0;r<20;r++){
ax[r]=0;ay[r]=0;}
   for(int x=1;x<9;x++){
	   	for(int y=1;y<9;y++){
if(box[y][x]==' '){
			box[y][x]='@';
if(box[y+1][x]=='O'){
 if(box[y+2][x]=='@'){
 ay[p]=y; ax[p]=x;
p++; }
else if(box[y+2][x]=='O'){
     if(box[y+3][x]=='@'){
     	  ay[p]=y; ax[p]=x;
p++; }
else if(box[y+3][x]=='O'){
           if(box[y+4][x]=='@'){
           	  ay[p]=y; ax[p]=x;
 p++;
}
 else if(box[y+4][x]=='O'){
                   if(box[y+5][x]=='@'){
                   	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y+5][x]=='O'){
                           if(box[y+6][x]=='@'){
                           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y+6][x]=='O'){
                                if(box[y+7][x]=='@'){
                                	  ay[p]=y; ax[p]=x;
p++;
 }}}}}}}
if(box[y+1][x+1]=='O'){
 if(box[y+2][x+2]=='@'){
 	  ay[p]=y; ax[p]=x;
 p++;
}
else if(box[y+2][x+2]=='O'){
     if(box[y+3][x+3]=='@'){
     	  ay[p]=y; ax[p]=x;
 p++;
}
 else if(box[y+3][x+3]=='O'){
           if(box[y+4][x+4]=='@'){
           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y+4][x+4]=='O'){
                   if(box[y+5][x+5]=='@'){
                   	  ay[p]=y; ax[p]=x;
p++;
 }
 else if(box[y+5][x+5]=='O'){
                           if(box[y+6][x+6]=='@'){
                           	  ay[p]=y; ax[p]=x;
 p++;
}
 else if(box[y+6][x+6]=='O'){
                                if(box[y+7][x+7]=='@'){
                                	  ay[p]=y; ax[p]=x;
 p++;
}}}}}}}
 if(box[y][x+1]=='O'){
 if(box[y][x+2]=='@'){
 	  ay[p]=y; ax[p]=x;
p++;
 }
 else if(box[y][x+2]=='O'){
     if(box[y][x+3]=='@'){
     	  ay[p]=y; ax[p]=x;
p++;
 }
      else if(box[y][x+3]=='O'){
           if(box[y][x+4]=='@'){
           	  ay[p]=y; ax[p]=x;
p++;
 }
               else if(box[y][x+4]=='O'){
                   if(box[y][x+5]=='@'){
                   	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y][x+5]=='O'){
                           if(box[y][x+6]=='@'){
                           	  ay[p]=y; ax[p]=x;
p++;
 }
 else if(box[y][x+6]=='O'){
                                if(box[y][x+7]=='@'){
                                	  ay[p]=y; ax[p]=x;
p++;
 }}}}}}}
if(box[y-1][x-1]=='O'){
 if(box[y-2][x-2]=='@'){
 	  ay[p]=y; ax[p]=x;
p++;
 }
 else if(box[y-2][x-2]=='O'){
     if(box[y-3][x-3]=='@'){
     	  ay[p]=y; ax[p]=x;
p++;
 }
 else if(box[y-3][x-3]=='O'){
           if(box[y-4][x-4]=='@'){
           	  ay[p]=y; ax[p]=x;
p++;
 }
 else if(box[y-4][x-4]=='O'){
                   if(box[y-5][x-5]=='@'){
                   	  ay[p]=y; ax[p]=x;
p++;
 }
  else if(box[y-5][x-5]=='O'){
                           if(box[y-6][x-6]=='@'){
                           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-6][x-6]=='O'){
                                if(box[y-7][x-7]=='@'){
                                	  ay[p]=y; ax[p]=x;
p++;
 }}}}}}}
if(box[y-1][x]=='O'){
 if(box[y-2][x]=='@'){
 	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-2][x]=='O'){
     if(box[y-3][x]=='@'){
     	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-3][x]=='O'){
           if(box[y-4][x]=='@'){
           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-4][x]=='O'){
                   if(box[y-5][x]=='@'){
                   	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-5][x]=='O'){
                           if(box[y-6][x]=='@'){
                           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-6][x]=='O'){
                                if(box[y-7][x]=='@'){
                                	  ay[p]=y; ax[p]=x;
p++;
 }}}}}}}
if(box[y][x-1]=='O'){
 if(box[y][x-2]=='@'){
 	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y][x-2]=='O'){
     if(box[y][x-3]=='@'){
     	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y][x-3]=='O'){
           if(box[y][x-4]=='@'){
           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y][x-4]=='O'){
                   if(box[y][x-5]=='@'){
                   	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y][x-5]=='O'){
                           if(box[y][x-6]=='@'){
                           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y][x-6]=='O'){
                                if(box[y][x-7]=='@'){
                                	  ay[p]=y; ax[p]=x;
p++;
 }}}}}}}
if(box[y+1][x-1]=='O'){
 if(box[y+2][x-2]=='@'){
 	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y+2][x-2]=='O'){
     if(box[y+3][x-3]=='@'){
     	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y+3][x-3]=='O'){
           if(box[y+4][x-4]=='@'){
           	  ay[p]=y; ax[p]=x;
p++;
 }
 else if(box[y+4][x-4]=='O'){
                   if(box[y+5][x-5]=='@'){
                   	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y+5][x-5]=='O'){
                           if(box[y+6][x-6]=='@'){
                           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y+6][x-6]=='O'){
                                if(box[y+7][x-7]=='@'){
                                	  ay[p]=y; ax[p]=x;
p++;
 }}}}}}}
if(box[y-1][x+1]=='O'){
 if(box[y-2][x+2]=='@'){
 	  ay[p]=y; ax[p]=x;
p++;
 }
 else if(box[y-2][x+2]=='O'){
     if(box[y-3][x+3]=='@'){
     	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-3][x+3]=='O'){
           if(box[y-4][x+4]=='@'){
           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-4][x+4]=='O'){
                   if(box[y-5][x+5]=='@'){
                   	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-5][x+5]=='O'){
                           if(box[y-6][x+6]=='@'){
                           	  ay[p]=y; ax[p]=x;
p++;
 }
else if(box[y-6][x+6]=='O'){
                                if(box[y-7][x+7]=='@'){
                                	  ay[p]=y; ax[p]=x;
p++;
 }}}}}}}
				box[y][x]=' ';}}}
				for(int my=0;my<p;my++){
					for(int mx=0;mx<p;mx++){
					if(m[ay[my]][ax[mx]]==bestmove){
				    srand((unsigned)time(NULL)); 
    				int i;
    				i = (rand()%2);
					if(i==1) {
					bestmove=m[ay[my]][ax[mx]];	}
				}
						if(m[ay[my]][ax[mx]]>bestmove){//compare value of moves based on memory matrix
							bestmove=m[ay[my]][ax[mx]];
							besty=ay[my]; bestx=ax[mx];
							if(besty>8 || bestx>8){
							m[besty][bestx]=-100;}}}}}
void twinturn(){
int bestmove=-1000;
int p=0,ax2[20],ay2[20];
for(int r=0;r<20;r++){
ax2[r]=0; ay2[r]=0;}
		    for(int x=1;x<9;x++){
	   	for(int y=1;y<9;y++){
    		if(box[y][x]==' '){
			box[y][x]='O';
if(box[y+1][x]=='@'){
 if(box[y+2][x]=='O'){
 ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+2][x]=='@'){
     if(box[y+3][x]=='O'){
     	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+3][x]=='@'){
           if(box[y+4][x]=='O'){
           	  ay2[p]=y; ax2[p]=x;
 p++;
}
 else if(box[y+4][x]=='@'){
                   if(box[y+5][x]=='O'){
                   	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+5][x]=='@'){
                           if(box[y+6][x]=='O'){
                           	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+6][x]=='@'){
                                if(box[y+7][x]=='O'){
                                	  ay2[p]=y; ax2[p]=x;
p++;
 }}}}}}}
if(box[y+1][x+1]=='@'){
 if(box[y+2][x+2]=='O'){
 	  ay2[p]=y; ax2[p]=x;
 p++;
}
else if(box[y+2][x+2]=='@'){
     if(box[y+3][x+3]=='O'){
     	  ay2[p]=y; ax2[p]=x;
 p++;
}
 else if(box[y+3][x+3]=='@'){
           if(box[y+4][x+4]=='O'){
           	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+4][x+4]=='@'){
                   if(box[y+5][x+5]=='O'){
                   	  ay2[p]=y; ax2[p]=x;
p++;
 }
 else if(box[y+5][x+5]=='@'){
                           if(box[y+6][x+6]=='O'){
                           	  ay2[p]=y; ax2[p]=x;
 p++;
}
 else if(box[y+6][x+6]=='@'){
                                if(box[y+7][x+7]=='O'){
                                	  ay2[p]=y; ax2[p]=x;
 p++;
}}}}}}}
 if(box[y][x+1]=='@'){
 if(box[y][x+2]=='O'){
 	  ay2[p]=y; ax2[p]=x;
p++;
 }
 else if(box[y][x+2]=='@'){
     if(box[y][x+3]=='O'){
     	  ay2[p]=y; ax2[p]=x;
p++;
 }
      else if(box[y][x+3]=='@'){
           if(box[y][x+4]=='O'){
           	  ay2[p]=y; ax2[p]=x;
p++;
 }
               else if(box[y][x+4]=='@'){
                   if(box[y][x+5]=='O'){
                   	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y][x+5]=='@'){
                           if(box[y][x+6]=='O'){
                           	  ay2[p]=y; ax2[p]=x;
p++;
 }
 else if(box[y][x+6]=='@'){
                                if(box[y][x+7]=='O'){
                                	  ay2[p]=y; ax2[p]=x;
p++;
 }}}}}}}
if(box[y-1][x-1]=='@'){
 if(box[y-2][x-2]=='O'){
 	  ay2[p]=y; ax2[p]=x;
p++;
 }
 else if(box[y-2][x-2]=='@'){
     if(box[y-3][x-3]=='O'){
     	  ay2[p]=y; ax2[p]=x;
p++;
 }
 else if(box[y-3][x-3]=='@'){
           if(box[y-4][x-4]=='O'){
           	  ay2[p]=y; ax2[p]=x;
p++;
 }
 else if(box[y-4][x-4]=='@'){
                   if(box[y-5][x-5]=='O'){
                   	  ay2[p]=y; ax2[p]=x;
p++;
 }
  else if(box[y-5][x-5]=='@'){
                           if(box[y-6][x-6]=='O'){
                           	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-6][x-6]=='@'){
                                if(box[y-7][x-7]=='O'){
                                	  ay2[p]=y; ax2[p]=x;
p++;
 }}}}}}}
if(box[y-1][x]=='@'){
 if(box[y-2][x]=='O'){
 	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-2][x]=='@'){
     if(box[y-3][x]=='O'){
     	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-3][x]=='@'){
           if(box[y-4][x]=='O'){
           	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-4][x]=='@'){
                   if(box[y-5][x]=='O'){
                   	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-5][x]=='@'){
                           if(box[y-6][x]=='O'){
                           	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-6][x]=='@'){
                                if(box[y-7][x]=='O'){
                                	  ay2[p]=y; ax2[p]=x;
p++;
 }}}}}}}
if(box[y][x-1]=='@'){
 if(box[y][x-2]=='O'){
 	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y][x-2]=='@'){
     if(box[y][x-3]=='O'){
     	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y][x-3]=='@'){
           if(box[y][x-4]=='O'){
           	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y][x-4]=='@'){
                   if(box[y][x-5]=='O'){
            ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y][x-5]=='@'){
                           if(box[y][x-6]=='O'){
    	ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y][x-6]=='@'){
                if(box[y][x-7]=='O'){
            	  ay2[p]=y; ax2[p]=x;
p++;
 }}}}}}}
if(box[y+1][x-1]=='@'){
 if(box[y+2][x-2]=='O'){
 	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+2][x-2]=='@'){
     if(box[y+3][x-3]=='O'){
     	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+3][x-3]=='@'){
           if(box[y+4][x-4]=='O'){
           	  ay2[p]=y; ax2[p]=x;
p++;
 }
 else if(box[y+4][x-4]=='@'){
                   if(box[y+5][x-5]=='O'){
              ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+5][x-5]=='@'){
                 if(box[y+6][x-6]=='O'){
                     ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y+6][x-6]=='@'){
                   if(box[y+7][x-7]=='O'){
                      ay2[p]=y; ax2[p]=x;
p++;
 }}}}}}}
if(box[y-1][x+1]=='@'){
 if(box[y-2][x+2]=='O'){
 	  ay2[p]=y; ax2[p]=x;
p++;
 }
 else if(box[y-2][x+2]=='@'){
     if(box[y-3][x+3]=='O'){
     	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-3][x+3]=='@'){
           if(box[y-4][x+4]=='O'){
           	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-4][x+4]=='@'){
           if(box[y-5][x+5]=='O'){
             ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-5][x+5]=='@'){
              if(box[y-6][x+6]=='O'){
          	  ay2[p]=y; ax2[p]=x;
p++;
 }
else if(box[y-6][x+6]=='@'){
              if(box[y-7][x+7]=='O'){
             	  ay2[p]=y; ax2[p]=x;
p++;
 }}}}}}}
				box[y][x]=' ';}}}
				for(int my=0;my<p;my++){
					for(int mx=0;mx<p;mx++){
					if(tm[ay2[my]][ax2[mx]]==bestmove){
				    srand((unsigned)time(NULL)); 
    				int i;
    				i = (rand()%2);
					if(i==1) {
					bestmove=tm[ay2[my]][ax2[mx]];	}
				}
						if(tm[ay2[my]][ax2[mx]]>bestmove){//compare value of moves based on memory matrix
							bestmove=tm[ay2[my]][ax2[mx]];
							Obesty=ay2[my]; Obestx=ax2[mx];
							if(Obesty>8 || Obestx>8){
							tm[Obesty][Obestx]=-100;}
						}}}}
int menu(){
system("cls");
Sleep(500);
SetConsoleTextAttribute(color,2);
cout<<"\n\n\n\n\n\n                    ___________________________________________________________________________";
Beep(150,200);Beep(300,500);
Sleep(700);
coord.X=0; coord.Y=0;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
SetConsoleTextAttribute(color,2);		
cout<<"\n                         _/_/_/    _/_/_/_/  _/      _/  _/_/_/_/  _/_/_/      _/_/_/  _/_/_/   \n                        _/    _/  _/        _/      _/  _/        _/    _/  _/          _/      \n                       _/_/_/    _/_/_/    _/      _/  _/_/_/    _/_/_/      _/_/      _/       \n                      _/    _/  _/          _/  _/    _/        _/    _/        _/    _/        \n                     _/    _/  _/_/_/_/      _/      _/_/_/_/  _/    _/  _/_/_/    _/_/_/       \n                    ____________________________________________________________________________";
Beep(400,500);
Sleep(1000);
coord.X=0; coord.Y=0;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
SetConsoleTextAttribute(color, 32);	
			coord.X=19;coord.Y=0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"                                                                            ";
	coord.Y=1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"     _/_/_/    _/_/_/_/  _/      _/  _/_/_/_/  _/_/_/      _/_/_/  _/_/_/   ";
coord.Y=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"    _/    _/  _/        _/      _/  _/        _/    _/  _/          _/      ";
coord.Y=3;	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"   _/_/_/    _/_/_/    _/      _/  _/_/_/    _/_/_/      _/_/      _/       ";
coord.Y=4;	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"  _/    _/  _/          _/  _/    _/        _/    _/        _/    _/        ";
coord.Y=5;	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<" _/    _/  _/_/_/_/      _/      _/_/_/_/  _/    _/  _/_/_/    _/_/_/       ";

SetConsoleTextAttribute(color, 32);
coord.Y=6;	
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"____________________________________________________________________________";
Beep(600,200);Beep(400,400);
SetConsoleTextAttribute(color, 2);
cout<<" \nReversi";
	SetConsoleTextAttribute(color, 12);
cout<<"            By Mon S.\n";
	SetConsoleTextAttribute(color, 2);
cout<<"(AKA Othello)\n\n                                             ";
	SetConsoleTextAttribute(color, 32);
coord.X=43;coord.Y=9;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"    Main Menu     ";
SetConsoleTextAttribute(color, 2);
coord.X=44;coord.Y=11;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"1)Player V Player";
coord.Y=13;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"2)Player V AI";
coord.Y=15;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"3)Train (AI V AI)";
coord.Y=17;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"4)Display Learning Matrix";
coord.Y=19;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
cout<<"5)Exit\n";
cin>>option;
system("cls");
}

int main(int argc, char** argv) {
int point2=0,pointO=0;
fstream imemory,omemory;
char yesno;
bool keep;
bool record[10][10];
bool recordtwin[10][10];
//Take data from text file
imemory.open("brain.txt",ios::in);
if(imemory){
	int fy=0,fx=0;
	for(int fy=0;fy<8;fy++){
		for(int fx=0;fx<8;fx++){
	imemory>>m[fy][fx];}}	}	
	imemory.close();
	imemory.clear();
	imemory.open("twinbrain.txt", ios::in);
if(imemory){
	int fy=0,fx=0;
	for(int fy=0;fy<8;fy++){
		for(int fx=0;fx<8;fx++){
	imemory>>tm[fy][fx];}}	}	
imemory.close();
imemory.clear();
menu();
switch(option){
////////////////////////////////////////////////////////////////////////////////////////////////////////	
	case 1:
	do{
		//Reset board
	for(int ry=1;ry<9;ry++){
	for(int rx=1;rx<9;rx++){
		box[ry][rx]=' ';}}
		pointO=0; point2=0;
		//Game starts
gameover=0;
	int X,Y;

    box[4][4]='@';
    box[4][5]='O';
    box[5][4]='O';
    box[5][5]='@';

    board();
    while(gameover<2){
   	SetConsoleTextAttribute(color, 244);   	
 cout<<"\nPlayer O" ;
 SetConsoleTextAttribute(color,68);
 cout<<"-------------------------------------------------\n                                                         ";
 SetConsoleTextAttribute(color, 2);
cout<<endl;
checkO();
 while(move==false){
	cout<<"Choose row: ";
	cin>>Y;
	cout<<"Choose column: ";
	cin>>X;	
	reversiO(Y,X);
	gameover=0;
 	SetConsoleTextAttribute(color, 2);
		if(move==false) {
			Beep(500,500);
	cout<<"\nCan't place there!\n";
	}}
board();
SetConsoleTextAttribute(color, 4);
cout<<"\nPlayer @";
 SetConsoleTextAttribute(color,68);
 cout<<"-------------------------------------------------\n                                                         ";
 SetConsoleTextAttribute(color, 2);
cout<<endl;
check2();
while(move==false){
	cout<<"Choose row: ";
	cin>>Y;
	cout<<"Choose column: ";
	cin>>X;	
reversi2(Y,X);
gameover=0;
	if(move==false) {
	Beep(500,500);
	cout<<"\nCan't place there!\n";
}}
board();}
for(int y=1;y<9;y++){
for(int x=1;x<9;x++){
	   		if(box[y][x]=='O'){
	   			pointO++;
			   }
			if(box[y][x]=='@'){
				point2++;
			}}}
cout<<"Game over!\n";
SetConsoleTextAttribute(color,64);
"Player @";
SetConsoleTextAttribute(color, 2);
cout<<" has "<<point2<<" points\n";
SetConsoleTextAttribute(color, 79);
"Player O";
SetConsoleTextAttribute(color, 2);
cout<<" has "<<pointO<<" points\n\n";
if(pointO>point2) {
SetConsoleTextAttribute(color, 244);
cout<<"Player O wins!";
SetConsoleTextAttribute(color, 71);}
else if(point2>pointO){
SetConsoleTextAttribute(color, 4);
 cout<<"Player @ wins!";
 SetConsoleTextAttribute(color, 71);}
else if(point2==pointO) cout<<"It's a draw!";
	cout<<"\n\nWould you like to play again? [y]es/[n]o\n";
	cin>>yesno; if(yesno=='y'){
	keep=true;}else{
	keep=false;} }while(keep==true);
break;
///////////////////////////////////////////////////////////////////////////////////////////////////
	case 2:
	loop2:
		char corp;
		cout<<"[P]layer go first or [C]omputer? ";
		cin>>corp;
		//Reset board
	for(int ry=1;ry<9;ry++){
	for(int rx=1;rx<9;rx++){
		record[ry][rx]=false;
		recordtwin[rx][ry]=false;
		box[ry][rx]=' ';}}
		pointO=0; point2=0;
		//Game starts
gameover=0;
	int X,Y;

    box[4][4]='@';
    box[4][5]='O';
    box[5][4]='O';
    box[5][5]='@';

    board();
    if(corp=='p'){
    while(gameover<2){
   	SetConsoleTextAttribute(color, 244);   	
 cout<<"\nPlayer O" ;
 SetConsoleTextAttribute(color,68);
 cout<<"-------------------------------------------------\n                                                         ";
 SetConsoleTextAttribute(color, 2);
cout<<endl;
checkO();
while(move==false){
	cout<<"Choose row: ";
	cin>>Y;
	cout<<"Choose column: ";
	cin>>X;	
	reversiO(Y,X);
	gameover=0;
		if(move==false) {
			Beep(500,500);
	cout<<"\nCan't place there!\n";
	}}
	recordtwin[Y][X]=true;
board();
SetConsoleTextAttribute(color, 4);
cout<<"\nPlayer @";
 SetConsoleTextAttribute(color,68);
 cout<<"-------------------------------------------------\n                                                         ";
 SetConsoleTextAttribute(color, 2);
cout<<endl;
cout<<"Choosing.";
Sleep(500);		cout<<".";
check2();
while(move==false){
aiturn();
reversi2(besty,bestx);
gameover=0;
	if(move==false) {
Sleep(300); cout<<".";
	m[besty][bestx]--;
}}
record[besty][bestx]=true;
board();}}
/////////////////////////////////////////////////////////////////////////
else if(corp=='c'){
while(gameover<2){
   	SetConsoleTextAttribute(color, 244);   	
 cout<<"\nPlayer O" ;
 SetConsoleTextAttribute(color,68);
 cout<<"-------------------------------------------------\n                                                         ";
 SetConsoleTextAttribute(color, 2);
cout<<endl;
 cout<<"Choosing." ;
 Sleep(500);
cout<<"."; 
checkO();
while(move==false){
 	twinturn();
	reversiO(Obesty,Obestx);
	gameover=0;
		if(move==false) {
			Sleep(300);
	cout<<".";
		tm[Obesty][Obestx]--;
	}}
	recordtwin[Obesty][Obestx]=true;
board();
SetConsoleTextAttribute(color, 4);
cout<<"\nPlayer @";
 SetConsoleTextAttribute(color,68);
 cout<<"-------------------------------------------------\n                                                         ";
 SetConsoleTextAttribute(color, 2);
cout<<endl;
check2();
while(move==false){
	cout<<"Choose row: ";
	cin>>Y;
	cout<<"Choose column: ";
	cin>>X;	
reversi2(Y,X);
gameover=0;
	if(move==false) {
		Beep(500,500);
	cout<<"\nCan't place there!\n";
}}
record[Y][X]=true;
board();}}	else{cout<<"\nSomething is wrong, try again (answer in lower cases only)\n";
goto loop2;}
for(int y=1;y<9;y++){
for(int x=1;x<9;x++){
	   		if(box[y][x]=='O'){
	   			pointO++;}
			if(box[y][x]=='@'){
				point2++;
			}}}
cout<<"Game over!\n";
SetConsoleTextAttribute(color, 64);
cout<<"Player @";
SetConsoleTextAttribute(color, 2);
cout<<" has "<<point2<<" points\n";
SetConsoleTextAttribute(color, 79);
cout<<"Player O";
SetConsoleTextAttribute(color, 2);
cout<<" has "<<pointO<<" points\n\n";
if(pointO>point2) {
SetConsoleTextAttribute(color, 79);
cout<<"Player O wins!";
SetConsoleTextAttribute(color, 2);}
else if(point2>pointO) {
SetConsoleTextAttribute(color, 64);
cout<<"Player @ wins!";
SetConsoleTextAttribute(color, 2);}
else if(point2==pointO) cout<<"It's a draw!";
if(corp=='p'){
	//Change weights of recorded moves based on result
omemory.open("brain.txt",ios::out);
	if(omemory){
			if(point2>pointO){
		for(int fy=0;fy<8;fy++){
			for(int fx=0;fx<8;fx++){
				if(record[fy][fx]==true){
				m[fy][fx]+=10;}
				omemory<<m[fy][fx]<<endl;
			}}	}
	else if(pointO>point2){
		for(int fy=0;fy<8;fy++){
			for(int fx=0;fx<8;fx++){
				if(record[fy][fx]==true){
				m[fy][fx]--;}
				omemory<<m[fy][fx]<<endl;}}}}
			omemory.close();
			omemory.clear();}	
else if(corp=='c'){
	omemory.open("twinbrain.txt",ios::out);
	if(omemory){
		if(pointO>point2){
		for(int fy=0;fy<8;fy++){
			for(int fx=0;fx<8;fx++){
				if(recordtwin[fy][fx]==true){
				tm[fy][fx]+=10;}
				omemory<<m[fy][fx]<<endl;			}}	}
	else if(point2>pointO){
		for(int fy=0;fy<8;fy++){
			for(int fx=0;fx<8;fx++){
				if(recordtwin[fy][fx]==true){
				tm[fy][fx]--;}
				omemory<<tm[fy][fx]<<endl;		}}}}
	omemory.close();
	omemory.clear();}
	cout<<"\n\nWould you like to play again? [y]es/[n]o\n";
	cin>>yesno; if(yesno=='y'){
	keep=true;}else{
	keep=false;} if(keep==true){goto loop2;}
	
break;
//////////////////////////////////////////////////////////////////////////////////////////
	case 3:
	do{
		//Reset board
	for(int ry=1;ry<9;ry++){
	for(int rx=1;rx<9;rx++){
		record[ry][rx]=false;
		recordtwin[rx][ry]=false;
		box[ry][rx]=' ';}}
		pointO=0; point2=0;
		//Game starts
	gameover=0;
	box[4][4]='@';
    box[4][5]='O';
    box[5][4]='O';
    box[5][5]='@';
    board();
    while(gameover<2){
	checkO();
	 while(move==false){
	twinturn();
	gameover=0;
	reversiO(Obesty,Obestx);
		if(move==false) {
		tm[Obesty][Obestx]--;
	}}
	recordtwin[Obesty][Obestx]=true;
board();
check2();
while(move==false){
aiturn();
reversi2(besty,bestx);
gameover=0;
if(move==false) {
	m[besty][bestx]--;
}}
record[besty][bestx]=true;
board();}
	    for(int y=1;y<9;y++){
	   	for(int x=1;x<9;x++){
	   	if(box[y][x]=='O'){
	   		pointO++; }
if(box[y][x]=='@'){point2++;}}}
//Change weights of recorded moves based on result
omemory.open("brain.txt",ios::out);
if(omemory){
if(point2>pointO){
	for(int fy=0;fy<8;fy++){
	for(int fx=0;fx<8;fx++){
		if(record[fy][fx]==true){
		m[fy][fx]+=10;}
		omemory<<m[fy][fx]<<endl;}}	}
	else if(pointO>point2){
			for(int fy=0;fy<8;fy++){
			for(int fx=0;fx<8;fx++){
			if(record[fy][fx]==true){
			m[fy][fx]--;}
			omemory<<m[fy][fx]<<endl;}}}}
omemory.close();
omemory.clear();
omemory.open("twinbrain.txt",ios::out);
	if(omemory){
			if(pointO>point2){
		for(int fy=0;fy<8;fy++){
			for(int fx=0;fx<8;fx++){
				if(recordtwin[fy][fx]==true){
				tm[fy][fx]+=10;}
				omemory<<m[fy][fx]<<endl;			}}	}
	else if(point2>pointO){
		for(int fy=0;fy<8;fy++){
			for(int fx=0;fx<8;fx++){
				if(recordtwin[fy][fx]==true){
				tm[fy][fx]--;}
				omemory<<tm[fy][fx]<<endl;		}}}}
	omemory.close();
	omemory.clear();
cout<<"\n\n\nPlay again?[y]es/[n]o?";
cin>>yesno;
if(yesno=='y'){
	keep=true;}
	else{keep=false;}
	}while(keep==true);
break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 4:
	cout<<"\nMatrix of AI playing first:\n";
	for(int y=0;y<8;y++){	for(int x=0;x<8;x++){	cout<<m[y][x]<<" "; }cout<<endl;}
	cout<<"\nMatrix of AI playing second:\n";
  	for(int y=0;y<8;y++){	for(int x=0;x<8;x++){ cout<<tm[y][x]<<" ";}cout<<endl;}
  		break;
////////////////////////////////////////////////////////////////////////////////////	
	case 5:
		break;
}
if(option!=5){
cout<<"\n1)Return to main menu\n\n2)Exist program";
cin>>option;
if(option==1){main(argc,argv);}}
		cout<<"\nDo Widzenia!\n";

	return 0;
}

