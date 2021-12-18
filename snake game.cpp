#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
using namespace std;
bool gameover,temp;
const int w = 75;
const int h = 24;
int x,y,f_x,f_y,score,flag;
int t_x[100],t_y[100],t_n;
int i,j,k;
enum direction {stop=0,Left,Right,Up,Down};
direction dir;
void reset()
{
	gameover=false;
	flag=1;
	dir= stop;
	x=w/2;
	y=h/2;
	f_x= rand() % w;
	f_y= rand() % h;
	score=0;
}
void play_area()
{
	system("cls");
	for(i=0;i<w+2;i++)
		cout<<"#";
		cout<<endl;
 	for(i=0;i<h;i++)
	{
	 	for(j=0;j<w;j++)
	 	{
	 		if(j==0)
	 			cout<<"#";
			if(i==y && j==x)
			{
				if(flag==1)
					cout<<"^";
				if(flag==2)
					cout<<"v";
				if(flag==3)
					cout<<"<";
				if(flag==4)
					cout<<">";
			}
//	 			cout<<">";
	 		else if(i==f_y &&j==f_x)
				cout<<"o";
			else
			{
				temp = false;
			 	for(k=0;k<t_n;k++)
				{
						if(t_x[k]==j&&t_y[k]==i)
						{
							cout<<"o";
							temp = true;
						}						
				}	
				if(!temp)
					cout<<" ";	
			}
			if(j==w-1)
				cout<<"#";
		 }
		 cout<<endl;
	}
	for(i=0;i<w+2;i++)
		cout<<"#";
	cout<<endl;
	cout<<"score:"<<score;
}
void check()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'i':
				flag=1;
				dir = Up;
				break;
			case 'k':
				flag=2;
				dir = Down;
				break;
			case 'j':
				flag=3;
				dir = Left;
				break;
			case 'l':
				flag=4;
				dir = Right;
				break;
			case 'q':
				gameover=true;
				break;
			default:
				cout<<"enter valid input";
				break;
		}
	}
}
void function()
{
	int l_x=t_x[0];
	int l_y=t_y[0];
	int l2_x,l2_y;
	t_x[0]=x;
	t_y[0]=y;
	for(i=1;i<t_n;i++)
	{
		l2_x=t_x[i];
		l2_y=t_y[i];
		t_x[i]=l_x;
		t_y[i]=l_y;
		l_x=l2_x;
		l_y=l2_y;
	}
	switch(dir)
		{
			case Up:
				y--;
				break;
			case Down:
				y++;
				break;
			case Left:
				x--;
				break;
			case Right:
				x++;
				break;				
			default:
				break;	
		}
		if(x==f_x && y==f_y)
		{
			score=score+5;
			f_x= rand() % w;
			f_y= rand() % h;
			t_n++;
		}	
			
//		if(x==w-2||x==-1||y==-1||y==h)
//			gameover=true;
		    if(x>=w) 
				x=0; 
			if(x<0) 
				x=w-1;
     		if (y>=h) 
			   y=0;
			if (y<0) 
				y=h-1;		
		for(k=0;k<t_n;k++)
			if(t_x[k]==x&&t_y[k]==y)
				gameover=true;		
}
int main()
{
	reset();
//	play_area();
	while(!gameover)
	{
		play_area();
		check();
		function();
		Sleep(20);
	}
	
}
