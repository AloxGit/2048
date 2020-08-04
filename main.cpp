#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int score=0;

void fill(int cnt, int grid[4][4])
{
    int main();
    srand(time(0));
    int a=rand(),nib,b,xy,trk=0,cc=0;
    nib=((a%2)+1)*2;

    b=rand();
    if(cnt<=0)
    {
        cout<<"GAME OVER\nPRESS 1 TO CONTINUE\n";
        cin>>cc;
        if(cc==1)
            main();
        else
            exit(0);
    }
    xy=(b%cnt)+1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]==0)
            {
                trk++;
                if(xy==trk)
                {
                    grid[i][j]=nib;
                    break;
                }
            }
        }
    }
}

void disp(int grid[4][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<setw(4)<<grid[i][j];
        }
        cout<<"\n\n";
    }
        cout<<"SCORE : "<<score;
    cout<<"\n";
}

void lef(int grid[4][4])
{
    for(int i=0;i<4;i++)
    {
        int trail[4]={0},l=0,k=0;
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]!=0)
            {
                trail[l]=grid[i][j];
                l++;
            }
        }
        for(int j=1;j<l;j++)
        {
            if(trail[j]==trail[j-1])
            {
                trail[j-1]=2*trail[j-1];
                trail[j]=0;
                score+=trail[j-1];
            }
        }
        for(int j=0;j<4;j++)
        {
            if(trail[j]!=0)
            {
                grid[i][k]=trail[j];
                k++;
            }
        }
        for(int j=k;j<4;j++)
            grid[i][j]=0;
    }

    int cnt=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]==0)
            {
                cnt++;
            }
        }
    }
    fill(cnt,grid);

}

void up(int grid[4][4])
{
    for(int i=0;i<4;i++)
    {
        int trail[4]={0},l=0,k=0;
        for(int j=0;j<4;j++)
        {
            if(grid[j][i]!=0)
            {
                trail[l]=grid[j][i];
                l++;
            }
        }
        for(int j=1;j<l;j++)
        {
            if(trail[j]==trail[j-1])
            {
                trail[j-1]=2*trail[j-1];
                trail[j]=0;
                score+=trail[j-1];
            }
        }
        for(int j=0;j<4;j++)
        {
            if(trail[j]!=0)
            {
                grid[k][i]=trail[j];
                k++;
            }
        }
        for(int j=k;j<4;j++)
            grid[j][i]=0;
    }

    int cnt=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]==0)
            {
                cnt++;
            }
        }
    }
    fill(cnt,grid);

}


void ryt(int grid[4][4])
{
    for(int i=0;i<4;i++)
    {
        int trail[4]={0},l=0,k=3;
        for(int j=3;j>=0;j--)
        {
            if(grid[i][j]!=0)
            {
                trail[l]=grid[i][j];
                l++;
            }
        }
        for(int j=1;j<l;j++)
        {
            if(trail[j]==trail[j-1])
            {
                trail[j-1]=2*trail[j-1];
                trail[j]=0;
                score+=trail[j-1];
            }
        }
        for(int j=0;j<4;j++)
        {
            if(trail[j]!=0)
            {
                grid[i][k]=trail[j];
                k--;
            }
        }
        for(int j=k;j>=0;j--)
            grid[i][j]=0;
    }

    int cnt=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]==0)
            {
                cnt++;
            }
        }
    }
    fill(cnt,grid);

}

void dwn(int grid[4][4])
{
    for(int i=0;i<4;i++)
    {
        int trail[4]={0},l=0,k=3;
        for(int j=3;j>=0;j--)
        {
            if(grid[j][i]!=0)
            {
                trail[l]=grid[j][i];
                l++;
            }
        }
        for(int j=1;j<l;j++)
        {
            if(trail[j]==trail[j-1])
            {
                trail[j-1]=2*trail[j-1];
                trail[j]=0;
                score+=trail[j-1];
            }
        }
        for(int j=0;j<4;j++)
        {
            if(trail[j]!=0)
            {
                grid[k][i]=trail[j];
                k--;
            }
        }
        for(int j=k;j>=0;j--)
            grid[j][i]=0;
    }

    int cnt=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grid[i][j]==0)
            {
                cnt++;
            }
        }
    }
    fill(cnt,grid);

}


int main()
{
    int grid[4][4]={0},cnt=16;
    char dirc;
    score=0;
    fill(cnt,grid);
    cnt--;
    fill(cnt,grid);
    disp(grid);
    while(1)
    {
        cin>>dirc;
        switch(dirc)
        {
            case 'w':   system("cls");
                        up(grid);
                        disp(grid);
                        break;

            case 'a':   system("cls");
                        lef(grid);
                        disp(grid);
                        break;

            case 's':   system("cls");
                        dwn(grid);
                        disp(grid);
                        break;

            case 'd':   system("cls");
                        ryt(grid);
                        disp(grid);
                        break;

            default: cout<<"KUCHH BHI\nPRESS WASD ONLY\n";
        }
    }
    return 0;
}
