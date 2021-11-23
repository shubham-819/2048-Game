#include<conio.h>
#include<bits/stdc++.h>

using namespace std;

int traverseover(int arr[4][4])
{
	int fl=0,gl=0,i=0,j;
	while(i<4)
	{
		j=0;
    	while(j<4)
		{
    		if(arr[i][j]==0)
    		{
    			fl=1;
				break;	
			}
			j++;
		}

		i++;
	}		
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(arr[i+1][j]==arr[i][j] || arr[i][j+1]==arr[i][j])
    		{
    			gl=1;
    			break;
			}
			
	if(fl || gl) return 1;
	else return 0;
}

void arrowd(int arr[4][4])
{
	int i=0,j,q,t;
	while(i<4)
	{
		q=i,t=3;
		j=2;
		while(j>=0)
		{
			if(arr[i][j]!=0)
			{
				if(arr[i][j+1]==0 || arr[i][j+1]==arr[i][j])
				{
					if(arr[q][t]==arr[i][j])
					{
						arr[q][t]*=2;
						arr[i][j]=0;
					}
					else
					{
						if(arr[q][t]==0)
						{
							arr[q][t]=arr[i][j];
							arr[i][j]=0;
						}
						else
						{
							arr[q][--t]=arr[i][j];
							arr[i][j]=0;
						}
					}
				}
				else t--;
			}
			j--;
		}
		i++;
	}
}

int traverse(int temporary[4][4],int arr[4][4])
{
	int fl=1,i=0,j;
	while(i<4)
	{
		j=0;
    	while(j<4)
		{
    		if(temporary[i][j]!=arr[i][j])
    		{
    			fl=0;
    			break;
			}
			j++;
		}

		i++;
	}
	return fl;
}

void arroww(int arr[4][4])
{
	int i,j=0,q,t;
	while(j<4)
	{
		q=0,t=j;
		i=1;
		while(i<4)
		{
			if(arr[i][j]!=0)
			{
				if(arr[i-1][j]==0 || arr[i-1][j]==arr[i][j])
				{
					if(arr[q][t]==arr[i][j])
					{
						arr[q][t]*=2;
						arr[i][j]=0;
					}
					else
					{
						if(arr[q][t]==0)
						{
							arr[q][t]=arr[i][j];
							arr[i][j]=0;
						}
						else
						{
							arr[++q][t]=arr[i][j];
							arr[i][j]=0;
						}
					}
				}
				else q++;
			}
			i++;
		}
		j++;
	}
}

void newnumber(int arr[4][4])
{
	int q,t;
	srand(time(0));
	while(1)
	{
		q=rand()%4;
		t=rand()%4;
		if(arr[q][t]==0)
		{
			arr[q][t]=pow(2,q%2 + 1);
			break;
		}
	}

}

void arrows(int arr[4][4])
{
	int i,j=0,q,t;
	while(j<4)
	{
		q=3,t=j;
		i=2;
		while(i>=0)
		{
			if(arr[i][j]!=0)
			{
				if(arr[i+1][j]==0 || arr[i+1][j]==arr[i][j])
				{
					if(arr[q][t]==arr[i][j])
					{
						arr[q][t]*=2;
						arr[i][j]=0;
					}
					else
					{
						if(arr[q][t]==0)
						{
							arr[q][t]=arr[i][j];
							arr[i][j]=0;
						}
						else
						{
							arr[--q][t]=arr[i][j];
							arr[i][j]=0;
						}
					}
				}
				else q--;
			}
			i--;
		}
		j++;
	}
}

void display(int arr[4][4])
{
	cout<<"\n\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\n\n";
	int i=0,j;
	while(i<4)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		j=0;
		while(j<4)
		{
			if(arr[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<arr[i][j]<<" ";

			j++;
		}
		cout<<"|"<<endl;

		i++;
	}
	cout<<"\t\t\t\t-----------------\n";
}

void arrowa(int arr[4][4])
{
	int i=0,j,q,t;
	while(i<4)
	{
		q=i,t=0, j=1;
		while(j<4)
		{
			if(arr[i][j]!=0)
			{
				if(arr[i][j-1]==0 || arr[i][j-1]==arr[i][j])
				{
					if(arr[q][t]==arr[i][j])
					{
						arr[q][t]*=2;
						arr[i][j]=0;
					}
					else
					{
						if(arr[q][t]==0)
						{
							arr[q][t]=arr[i][j];
							arr[i][j]=0;
						}
						else
						{
							arr[q][++t]=arr[i][j];
							arr[i][j]=0;
						}
					}
				}
				else t++;
			}

			j++;
		}

		i++;
	}
}

int main()
{
	cout<<"\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key";
	getch();
	system("cls");
	int x,y,w,z,i,j;
	int arr[4][4]={0},temporary[4][4]={0};
	srand(time(0));
	x=rand()%4;
	y=rand()%4;
	while(1)
	{
		w=rand()%4;
		z=rand()%4;
		if(w!=x && z!=y) break;
	}
	arr[x][y]=2;
	arr[w][z]=4;
	display(arr);
	
	int choice;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			temporary[i][j]=arr[i][j];
    	choice=getch();
    	system("cls");
    	if(choice==72) arroww(arr);
    	if(choice==80) arrows(arr);
    	if(choice==75) arrowa(arr);
    	if(choice==77) arrowd(arr);
		if(choice==27) break;
		
		if(!traverse(temporary,arr))
			newnumber(arr);
		display(arr);
			
		if(!traverseover(arr))
		{
			cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}	
	}
	return 0;
}
