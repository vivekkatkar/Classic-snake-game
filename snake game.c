#include<stdio.h>
#include<conio.h>  
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define N 20   // N for rows
#define M 40   // M for colomn

		int i,j,field[N+1][M+1],flag=1;
		typedef int snake_cord,frog;
		snake_cord x,y,head,tail,temp,var,dir;   // For position of snake
		frog a,b,frog_num;
		long int sleep_num= 19999999,no;
	
void sleep_fun();	 
void frame()
{
	/*
	printf("\n\t%c",201);  // For upper left corner
	printf("\n\t%c",187);  // for upper right corner
	printf("\n\t%c",205);  // for horizontal line
	printf("\n\t%c",186);  // for vertical line
	printf("\n\t%c",200);	// For lower left corner
	printf("\n\t%c",188);	// For lower right corner
	printf("%c",177);		// for head of snake
	printf("%c",176);		// for other part of snake
	*/
	
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=M;j++)
		{
			if(field[i][j]==-1)
			{
				printf("%c",15);
			}
		    else if(i==0 && j==0)
			{
				printf("%c",201);
			}
			else if(i==N && j==0)
			{
				printf("%c",200);
			}
			else if(i==N && j==M)
			{
				printf("%c",188);
			}
			else if(i==0 && j==M)
			{
				printf("%c",187);
			}
			else if(i==0 || i==N)
			{
				printf("%c",205);
			}
			else if(j==0 || j==M)
			{
				printf("%c",186);
			}
			else if(field[i][j]>=tail && field[i][j]<=head)
			{
				if(field[i][j]==head)
					printf("%c",177);
				else
					printf("%c",176);
			}
			else if(field[i][j]==0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
}

void field_inisial()
{
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=M;j++)
		{
			field[i][j] = 0;
		}
	}
	
	frog_num = 0,dir='d';
	// Set snake position for beginning
	x = N/2;
	y = M/2;
	head = 5;			// Now snake contaion 4 box;
	tail = 1; 
	temp = y;
	y = y+4;
	// Snake part inisialization
	for(i=tail;i<=head;i++)
	{
		field[x][temp] = i;
		temp++;
	}
}

void resetScreenPosition()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut,Position);
}

void for_sleep()
{
	for(i=0;i<=sleep_num;i++)
	{
		no++;
	}
}

void frog_pos()
{
	srand(time(0));
	a = 1 + rand() % 18;   // to create a number from 1 to 19th row
	b = 1 + rand() % 38;   // to create a number from 1 to 39th row
	
	if(frog_num==0 && field[a][b]==0)
	{
		field[a][b] = -1;
		frog_num = 1;
	}
	
}

int getch_noblock()
{
	if(_kbhit())
	{
		return _getch();
	}
	else
	{
		return -1;
	}
}

void movement()
{
	var = getch_noblock();	
	var = tolower(var);   // it will convert given character to lower case
	
	if((dir=='w' && var=='x') || (dir=='x' && var=='w') || (dir=='a' && var=='d') || (dir=='d' && var=='a'))
	{
		goto down;		
	}
	if(var=='d' || var=='a' || var=='w' || var=='x')  // this if condition for continuous moving snake
	{
		dir = var;
	}
	
	down :
		
	if(dir=='d')  //for right
	{
		y++;
		if(y==M-1) 
		{
			y=0;	
		}
		
		if(field[x][y]==-1)
		{
			frog_num = 0;
			sleep_num-= 100000;
		}
		
		if(field[x][y]>=tail && field[x][y]<=head)
		{
			flag = 0;
		}
		
		head++;
		field[x][y] = head;
	}
	if(dir=='a')  // for left   
	{
		y--;
		if(y==0)
		{
			y = M-1;
		}
		if(field[x][y]==-1)
		{
			frog_num = 0;
			sleep_num-= 100000;
		}
		
		if(field[x][y]>=tail && field[x][y]<=head)
		{
			flag = 0;
		}
				
		head+=1;
		field[x][y] = head;
	}
	if(dir=='w')  // for up
	{
		x--;
		if(x==0)
		{
			x = N-1;
		}
		if(field[x][y]==-1)
		{
			frog_num = 0;
			sleep_num-= 10000;
		}
		
		if(field[x][y]>=tail && field[x][y]<=head)
		{
			flag = 0;
		}
		
		head+=1;
		field[x][y] = head;
	}
	if(dir=='x')  // for down
	{
		x++;
		if(x==N)
		{
			x = 0;
		}
		if(field[x][y]==-1)
		{
			frog_num = 0;
			sleep_num-= 10000;
		}
		
		if(field[x][y]>=tail && field[x][y]<=head)
		{
			flag = 0;
		}
		
		head+=1;
		field[x][y] = head;
	}

}

void tail_remove()
{
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=M;j++)
		{
			if(field[i][j]==tail)
			{
				field[i][j] = 0;
			}
		}
	}
	
	tail++;
}

void gameover()
{
	system("cls");
	printf("\n\n\t\t ***** GAME IS OVER *****");
}

int main()
{
	field_inisial();
	while(1)
	{
		frame();
		resetScreenPosition();
		frog_pos();
		movement();
		if(flag == 0)
		{
			sleep(1);
			gameover();
			break;
		}
		if(frog_num!=0)
		{
			tail_remove();
		}
		for_sleep();
	}
	return 0;
}
