#include<stdio.h>
int score=0,pvs,mov;
int check(int a[][4],int n)
{
	int i,pvj,state,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
				return 0;
			for(k=j+1;k<n;k++)
			{
				if(a[i][k]==a[i][j])
					return 0;
				else if(a[i][k]==0)
					continue;
				break;
			}
			for(k=i+1;k<n;k++)
			{
				if(a[k][j]==a[i][j])
					return 0;
				else if(a[i][k]==0)
					continue;
				break;
			}
		}
	return 1;
}
int left(int arr[][4],int n)
{
	int i,j,pvj;
	int state,pv,pos,m=1;
	for(i=0;i<n;i++)
	{
		pos=0;
		pvj=0;
		state=0;
		while(arr[i][pvj]==0)
		{
			pvj++;
			if(pvj==n)
			{
				state=1;
				break;
			}
		}
		for(j=pvj+1;j<n && state==0;j++)
			if(arr[i][j]==arr[i][pvj])
			{
				arr[i][pvj]=arr[i][j]*2;
				arr[i][j]=0;
				pvj++;
			//	pvs=score;
				score+=arr[i][pvj-1];
				m=0;
			}
			else if(arr[i][j]==0)
				continue;
			else
			{
				pvj=j;
			}
		pvj=0;
		while(arr[i][pvj]!=0)
		{
			pvj++;
			if(pvj==n)
			{
				state=1;
				break;
			}
		}
		for(j=pvj+1;j<n && state==0 ;j++)
		{
			if(arr[i][j]==0)
				continue;
			else
			{
				arr[i][pvj]=arr[i][j];
				arr[i][j]=0;
				pvj++;
				m=0;
			}
		}
	}
	return m;
}
int up(int arr[][4],int n)
{
	int i,j,pvj,m=1;
	int state,pv,pos;
	for(i=0;i<n;i++)
	{
		pos=0;
		pvj=0;
		state=0;
		while(arr[pvj][i]==0)
		{
			pvj++;
			if(pvj==n)
			{
				state=1;
				break;
			}
		}
		for(j=pvj+1;j<n && state==0;j++)
			if(arr[j][i]==arr[pvj][i])
			{
				arr[pvj][i]=arr[j][i]*2;
				arr[j][i]=0;
				pvj++;
			//	pvs=score;
				score+=arr[pvj-1][i];
				m=0;
			}
			else if(arr[j][i]==0)
				continue;
			else
			{
				pvj=j;
			}
		pvj=0;
		while(arr[pvj][i]!=0)
		{
			pvj++;
			if(pvj==n)
			{
				state=1;
				break;
			}
		}
		for(j=pvj+1;j<n && state==0 ;j++)
		{
			if(arr[j][i]==0)
				continue;
			else
			{
				arr[pvj][i]=arr[j][i];
				arr[j][i]=0;
				pvj++;
				m=0;
			}
		}
	}
	return m;
}
int right(int arr[][4],int n)
{
	int i,j,pvj;
	int state,pv,m=1;
	for(i=0;i<n;i++)
	{
		pvj=n-1;
		state=0;
		while(arr[i][pvj]==0)
		{
			pvj--;
			if(pvj==-1)
			{
				state=1;
				break;
			}
		}
		for(j=pvj-1;j>=0 && state==0;j--)
			if(arr[i][j]==arr[i][pvj])
			{
				arr[i][pvj]=arr[i][j]*2;
				arr[i][j]=0;
				pvj--;
			//	pvs=score;
				score+=arr[i][pvj+1];
				m=0;
			}
			else if(arr[i][j]==0)
				continue;
			else
			{
				pvj=j;
			}
		pvj=n-1;
		while(arr[i][pvj]!=0)
		{
			pvj--;
			if(pvj==-1)
			{
				state=1;
				break;
			}
		}
		for(j=pvj-1;j>=0 && state==0 ;j--)
		{
			if(arr[i][j]==0)
				continue;
			else
			{
				arr[i][pvj]=arr[i][j];
				arr[i][j]=0;
				m=0;
				pvj--;
			}
		}
	}
	return m;
}
int down(int arr[][4],int n)
{
	int i,j,pvj;
	int state,pv,m=1;
	for(i=0;i<n;i++)
	{
		pvj=n-1;
		state=0;
		while(arr[pvj][i]==0)
		{
			pvj--;
			if(pvj==-1)
			{
				state=1;
				break;
			}
		}
		for(j=pvj-1;j>=0 && state==0;j--)
			if(arr[j][i]==arr[pvj][i])
			{
				arr[pvj][i]=arr[j][i]*2;
				arr[j][i]=0;
				pvj--;
			//	pvs=score;
				score+=arr[pvj+1][i];
				m=0;
			}
			else if(arr[j][i]==0)
				continue;
			else
			{
				pvj=j;
			}
		pvj=n-1;
		while(arr[pvj][i]!=0)
		{
			pvj--;
			if(pvj==-1)
			{
				state=1;
				break;
			}
		}
		for(j=pvj-1;j>=0 && state==0 ;j--)
		{
			if(arr[j][i]==0)
				continue;
			else
			{
				arr[pvj][i]=arr[j][i];
				arr[j][i]=0;
				pvj--;
				m=0;
			}
		}
	}
	return m;
}
int main()
{
	printf("\n\n\n\n");
	int n=4;
	int arr[n][n],pvv[n][n];
	int a,b,m,i,j,state=0,pvj,pos;
b:
	score=state=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=0;
	char c='0',qqqq;
	while(1)
	{
		int count=0;
		int flag[4]={0};
		if(c!='U')
			while(1)
			{
				a=rand()%4;
				b=rand()%4;
				if(arr[a][b]==0)
				{
					arr[a][b]=2;
					break;
				}
			}
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tscore:%d\n\n\t\t\t\t\t.................................................................",score);
		for(i=0;i<n;i++)
		{
			printf("\n\t\t\t\t\t|\t\t|\t\t|\t\t|\t\t|\n\t\t\t\t\t|\t\t|\t\t|\t\t|\t\t|\n\t\t\t\t\t");
			for(j=0;j<n;j++)
			{
				if(arr[i][j]!=0)
					printf("|\t%d\t",arr[i][j]);
				else
					printf("|\t \t");
				if(j==n-1)
					printf("|\n\t\t\t\t\t|\t\t|\t\t|\t\t|\t\t|");
			}
			printf("\n\t\t\t\t\t|\t\t|\t\t|\t\t|\t\t|\n\t\t\t\t\t.................................................................");
		}
		printf("\n");
		printf("Controls:\n\t\t\t\tw->Up\n\t\t\t\t\t\t\t\t\t\t\tR->Restart\t\tQ->Quit\n\n\t\ta->Left\t\t\t\td->Right\n\t\t\t\t\t\t\t\t\t\t\tU->Undo\n\n\t\t\t\ts->Down\n");
		count=check(arr,n);
		if(count==1)
		{
			printf("\nGAME OVER...!!!\tYour Score is %d\nDo You Want to Restart[y/n] ",score);
vv:
			system ("/bin/stty raw");
			qqqq=getchar();
			system ("/bin/stty cooked");
			if(qqqq=='y')
			{
				printf("\n\n\n\n");
				goto b;
			}
			else if(qqqq=='n')
				return 0;
			else 
				goto vv;
		}
		printf("Enter Input:");
a:
		system ("/bin/stty raw");
		c=getchar();
		system ("/bin/stty cooked");
		/*if(c=='w'|| c=='W' || c=='a' || c=='A' || c=='s' || c=='S' || c=='d' || c=='D' || c=='R')
		  printf("\n\n\n\n");
		  else*/
		printf(" ");	
		if(c=='w'|| c=='W' || c=='a' || c=='A' || c=='s' || c=='S' || c=='d' || c=='D' || c=='R')
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					pvv[i][j]=arr[i][j];
		if(c=='Q')
			printf("\n");
		if(c=='W' || c=='w')
		{
			pvs=score;
			m=up(arr,n);
			if(m==1)
				goto a;
		}
		else if(c=='S' || c=='s')
		{
			pvs=score;
			m=down(arr,n);
			if(m==1)
				goto a;
		}
		else if(c=='A' || c=='a')
		{
			pvs=score;
			m=left(arr,n);
			if(m==1)
				goto a;
		}
		else if(c=='D'|| c=='d')
		{
			pvs=score;
			m=right(arr,n);
			if(m==1)
				goto a;
		}
		else if(c=='Q')
		{
			printf("ARE YOU SURE YOU WANT TO QUIT [y/n]");
v:
			system ("/bin/stty raw");
			qqqq=getchar();
			system ("/bin/stty cooked");
			if(qqqq=='y')
			{
				printf("\nGAME OVER...!!!\tYour Score is %d\n",score);
				return 0;
			}
			else if(qqqq=='n')
			{
				printf("\nEnter Input:");
				goto a;
			}
			else 
				goto v;
		}
		else if(c=='U')
		{
			score=pvs;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					arr[i][j]=pvv[i][j];
		}
		else if(c=='R')
			goto b;
		else
			goto a;
		if(c=='U' || c=='w'|| c=='W' || c=='a' || c=='A' || c=='s' || c=='S' || c=='d' || c=='D' || c=='R')
			printf("\n\n\n\n");
		else
			printf(" ");
	}
	return 0;
}
