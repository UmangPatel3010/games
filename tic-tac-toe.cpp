#include<iostream>
using namespace std;
char temp='x',a[3][3];
int ch,r,c,i,j;
int main();
void reset()
{
	temp='x';
	a[0][0]='1';
	a[0][1]='2';
	a[0][2]='3';
	a[1][0]='4';
	a[1][1]='5';
	a[1][2]='6';
	a[2][0]='7';
	a[2][1]='8';
	a[2][2]='9';
}
void play_again()
{
	cout<<"enter 1 to play again:";
	cin>>i;
	if(i==1)
	{
		reset(); 
		main();
	}
	else
	{
		exit(0);
	}
}

void display()
{
		system("cls");
		cout<<"\ttick tac toe"<<endl;
		cout<<"\tplayer1[X]"<<endl;
		cout<<"\tplayer2[O]\n"<<endl;
		cout<<"\t"<<"     |     |     "<<endl;
		cout<<"\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"  "<<endl;
		cout<<"\t"<<"_____|_____|_____"<<endl;
		cout<<"\t"<<"     |     |     "<<endl;	
		cout<<"\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<"  "<<endl;
		cout<<"\t"<<"_____|_____|_____"<<endl;		
		cout<<"\t"<<"     |     |     "<<endl;
		cout<<"\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<"  "<<endl;
		cout<<"\t"<<"     |     |     "<<endl;
}

void winner()
{
	for(i=0;i<3;i++)
	if(a[i][0]==a[i][1] && a[i][0]==a[i][2])
	{
		win:
		if(temp=='o')
		{
			display();
			cout<<"\n\nplayer-1 is winner\n\n";
			play_again();
		}
		else
		{
			display();
			cout<<"\n\nplayer-2 is winner\n\n";
			play_again();
		}
	}
	
	for(i=0;i<3;i++)
	if(a[0][i]==a[1][i] && a[0][i]==a[2][i])
		goto win;
	
	if(a[0][0]==a[1][1] && a[0][0]==a[2][2])
		goto win;
		
	if(a[0][2]==a[1][1] && a[0][2]==a[2][0])
		goto win;
}
void turn()
{
	temp:
	if(temp=='x')
		cout<<"\n\nenter choise player-1 [X]:";
	else
		cout<<"\n\nenter choise player-2 [O]:";
	
	cin>>ch;
	switch(ch)
	{
		case 1:	r=c=0; break;
		case 2:	r=0; c=1; break;
		case 3: r=0; c=2; break;
		case 4:	r=1; c=0; break;
		case 5: r=c=1; break;
		case 6: r=1; c=2; break;
		case 7: r=2; c=0; break;
		case 8: r=2; c=1; break;
		case 9:	r=c=2; break;
		default:
			cout<<"enter valid choise"<<endl;
			goto temp;
	}
	if(temp=='x' && a[r][c]!='X' && a[r][c]!='O')
	{
		a[r][c]='X';
		temp='o';
	}
	else if(temp=='o' && a[r][c]!='X' && a[r][c]!='O')
	{
		a[r][c]='O';
		temp='x';
	}
	else
	{
		cout<<"box is filled by other player\nplease try again!!!"<<endl;

		turn();
	}
	winner();
}
int main()
{
	int c=1;
	reset();
	while(c!=10)
	{
		display();
		turn();
		c++;
	}
	if(c==10)
	{
		display();
		cout<<"\n\nmatch draw!!\n\n";
		play_again();
	}
}
