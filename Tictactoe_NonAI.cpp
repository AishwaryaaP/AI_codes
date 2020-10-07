#include<iostream>
#include<stdlib.h>
using namespace std;
char **getposition(char** game,int x,int y);
void check(char** game,int count);
void printMat(char** mat);
int flag=0;
int main()
{
	char** game;
	int i,j,k,l,count=0,x,y;
	game=(char**)malloc(3*sizeof(char*));

	for(i=0;i<3;i++)
	{
		game[i]=(char*)malloc(3*sizeof(char));
		game[i][0]=game[i][1]=game[i][2]='*';
		cout<<game[i][0]<<" "<<game[i][1]<<" "<<game[i][2]<<endl;
	}
	while(1)
	{
		if(count==9)
		{
		    printMat(game);
			check(game,9);
			break;
		}
		if(count%2==0)
		{
			cout<<"Computer Turn"<<endl;
			//wait(1);
			if(!count)
			{
				game[1][1]='X';
				printMat(game);
			}
			else
			{
				game=getposition(game,x,y);
				printMat(game);
			}
			count++;
            check(game,count);
		if(flag!=0)
            {
                cout<<"Game Ended"<<endl;
                break;
            }
		}
		else
		{
			cout<<"User Turn";
			//wait(1);
			cout<<"Enter  row and column where u want to place  the 'O' seperated by  a space"<<endl;
			cin>>j>>k;
			game[j][k]='O';
			x=j,y=k;
			count++;
		}

	}
	cin>>i;
}
char** getposition(char** game,int x,int y)
{
	int i,j,k,l;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
            if(game[i][j]=='X')      //going for winning possibilities
			{
				if( game[(i+1)%3][j]=='X')  //vertical win chance 1
				{
				    if(game[(i+2)%3][j]=='*')
                    {
					game[(i+2)%3][j]='X';
					cout<<"1"<<endl;
					return game;
                    }
				}
				else if( game[(i+2)%3][j]=='X') //vertical win chance 2
				{
				    if(game[(i+1)%3][j]=='*')
                    {
					game[(i+1)%3][j]='X';
					cout<<"2"<<endl;
					return game;
                    }
				}
				else if(game[i][(j+1)%3]=='X')//horizontal win chance 1
				{
				    if(game[i][(j+2)%3]=='*')
                    {
					game[i][(j+2)%3]='X';
					cout<<"3"<<endl;
					return game;
                    }
				}
				else if(game[i][(j+2)%3]=='X')//horizontal win chance 2
				{
				    if(game[i][(j+1)%3]=='*')
                    {
					game[i][(j+1)%3]='X';
					cout<<"4"<<endl;
					return game;
                    }
				}
				else if(game[(i+1)%3][(j+1)%3]=='X') //diagonal win chance
                {
                    if(game[(i+2)%3][(j+2)%3]=='*')
                    {
                        game[(i+2)%3][(j+2)%3]='X';
                        return game;
                    }
                }
                else if(game[(i+2)%3][(j+2)%3]=='X') //diagonal win chance
                {
                    if(game[(i+1)%3][(j+1)%3]=='*')
                    {
                        game[(i+1)%3][(j+1)%3]='X';
                        return game;
                    }
                }
                else if(game[(i+2)%3][(j+1)%3]=='X')
                {
                    if(game[(i+1)%3][(j+2)%3]=='*')
                    {
                        game[(i+1)%3][(j+2)%3]='X';
                        return game;
                    }
                }
                 else if(game[(i+1)%3][(j+2)%3]=='X')
                {
                    if(game[(i+2)%3][(j+1)%3]=='*')
                    {
                        game[(i+2)%3][(j+1)%3]='X';
                        return game;
                    }
                }
			}
		}
	}
	for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
			if(game[i][j]=='O')
			{
				if( game[(i+1)%3][j]=='O')
				{
				    if(game[(i+2)%3][j]=='*')
                    {
					game[(i+2)%3][j]='X';
					cout<<"1"<<endl;
					return game;
                    }
				}
				else if( game[(i+2)%3][j]=='O')
				{
				    if(game[(i+1)%3][j]=='*')
                    {
					game[(i+1)%3][j]='X';
					cout<<"2"<<endl;
					return game;
                    }
				}
				else if(game[i][(j+1)%3]=='O')
				{
				    if(game[i][(j+2)%3]=='*')
                    {
					game[i][(j+2)%3]='X';
					cout<<"3"<<endl;
					return game;
                    }
				}
				else if(game[i][(j+2)%3]=='O')
				{
				    if(game[i][(j+1)%3]=='*')
                    {
					game[i][(j+1)%3]='X';
					cout<<"4"<<endl;
					return game;
                    }
				}
			}
		}

	}
	cout<<"Not"<<endl;
    if(game[x][(y+1)%3]=='*')
        game[x][(y+1)%3]='X';
     else if(game[x][(y+2)%3]=='*')
        game[x][(y+2)%3]='X';
     else if(game[(x+1)%3][y]=='*')
        game[(x+1)%3][y]='X';
     else if(game[(x+2)%3][y]=='*')
        game[(x+2)%3][y]='X';
    else
        cout<<"hii";
	return game;
}
void check(char** game,int count)
{
    for(int i=0;i<3;i++)
    {
        if((game[i][0]=='X'&&game[i][1]=='X'&&game[i][2]=='X')||(game[0][i]=='X'&&game[1][i]=='X'&&game[2][i]=='X'))
        {
            cout<<"Computer wins"<<endl;
            flag=1;
            return;
        }
        else if((game[i][0]==game[i][1]==game[i][2]=='O')||(game[0][i]==game[1][i]==game[2][i]=='O'))
        {
            cout<<"User Player wins"<<endl;
            flag=2;
            return ;
        }
    }
    if((game[0][0]=='X'&&game[1][1]=='X'&&game[2][2]=='X')||(game[2][0]=='X' &&game[1][1]=='X'&&game[0][2]=='X'))
    {
        cout<<"Computer Wins"<<endl;
        flag=1;
        return;
    }
    if(flag==0 && count==9)
    {
        cout<<"Game drawn"<<endl;
        return;
    }
}
void printMat(char** mat)
{
	for(int i= 0;i<3;i++)
	{
		for(int j=0 ;j<3;j++)
		{
			if(j < 2)
			{
			if(mat[i][j] == 'X')
			cout<<"X"<<"  |  ";

			else if(mat[i][j] == 'O')
			cout<<"O"<<"  |  ";

			else
			cout<<"-"<<"  |  ";
			}
			else
			{
			if(mat[i][j] == 'X')
			cout<<"X"<<"     ";

			else if(mat[i][j] == 'O')
			cout<<"O"<<"     ";

			else
			cout<<"-"<<"     ";
			}

		}
		if (i < 2)
		cout<<"\n--------------\n";
		else
		cout<<"\n\n";
	}
	cout<<"\n\n";
}
