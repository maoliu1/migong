#include<stdio.h>
#include<string.h>

int shuzu[10][10];
int count=0,min;
int endx,endy;
int flag;
int point(int x,int y)
{
    if(x==endx&&y==endy) 
    {
        flag=1;
        printf("%d",count);
        return 0;
    }
    shuzu[x][y]=1;
    if(flag)
	   return 0;
    if(shuzu[x][y-1]==0)
    {
        count++;
        point(x,y-1);
        count--;
    }
    if(shuzu[x+1][y]==0)
    {
        count++;
        point(x+1,y);
        count--;
    }
    if(shuzu[x-1][y]==0)
    {
        count++;
        point(x-1,y);
        count--;
    }
    if(shuzu[x][y+1]==0)
    {
        count++;
        point(x,y+1);
        count--;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&shuzu[i][j]);
        }
    }
    int x=1,y=1;
    endx=endy=n-2;
    flag=0;
    point(x,y);
    if(flag=1)
        printf("No solution"); 
    return 0;
}
