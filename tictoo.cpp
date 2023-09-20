#include<iostream>
using namespace std;
char grid[3][3]={{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
int row,col;
char token='X';
string p1="",p2="";
bool tie= false;
void structure()
{

    cout<<"   |    |  \n";
    cout<< " "<<grid[0][0]<<" | "<<grid[0][1]<<"  | "<<grid[0][2]<<" \n";
    cout<<"___|____|___\n";
    cout<<"   |    |   \n";
    cout<< " "<<grid[1][0]<<" | "<<grid[1][1]<<"  | "<<grid[1][2]<<" \n";
    cout<<"___|____|___\n";
    cout<<"   |    |   \n";
    cout<< " "<<grid[2][0]<<" | "<<grid[2][1]<<"  | "<<grid[2][2]<<" \n";
    cout<<"   |    |   \n";
    cout<<"\n";
}
void check()
{
    int digit;
    if(token=='X') 
    {
        cout<<p1<<" please Enter=";
        cin>>digit;
    }
    if(token=='0') 
    {
        cout<<p2<<" please Enter=";
        cin>>digit;
    }
    if(digit==1)
    {
        row=0;
        col=0;
    }
    if(digit==2)
    {
        row=0;
        col=1;
    }
    if(digit==3)
    {
        row=0;
        col=2;
    }
    if(digit==4)
    {
        row=1;
        col=0;
    }
    if(digit==5)
    {
        row=1;
        col=1;
    }
    if(digit==6)
    {
        row=1;
        col=2;
    }
    if(digit==7)
    {
        row=2;
        col=0;
    }
    if(digit==8)
    {
        row=2;
        col=1;
    }
    if(digit==9)
    {
        row=2;
        col=2;
    }
    else if(digit<1 || digit >9)
        cout<<" *INVALID* "<<endl; //Other than 1-9
    if(token=='X' && grid[row][col] !='X' && grid[row][col] !='0') //unused space
    {
        grid[row][col]='X'; //player 1 turn
        token='0';
    }
    else
    if(token=='0' && grid[row][col] !='X' && grid[row][col] !='0') //unused space
    {
        grid[row][col]='0'; //player 2 turn
        token='X';
    }
    else
     {   cout<<" There is no empty place "<<endl;
        check();
     }
   structure();
}     
bool win_game()
{
    for(int i=0;i<3;i++)
        if(grid[i][0]==grid[i][1] && grid[i][0]==grid[i][2] || grid[0][i]==grid[1][i] && grid[0][i]==grid[2][i])
            return true;

    if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]||grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
        return true;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            if(grid[i][j] != 'X' && grid[i][j] !='0')
                return false;//game not finished
        
    } 

    tie=true;
    return false;   
}
int main()
{
    cout<<"Enter the name of First player=";
   getline(cin,p1);
   cout<<"Enter the name of Second player=";
   getline(cin,p2);
   cout<<p1<<" is player1 so he/she will play First \n";
   cout<<p2<<" is player2 so he/she will play First \n";
    while(!win_game()) //till win_game return false
    {
        structure();
        check();
        win_game();
    }
    if(token=='X' && tie == false)//Means  last turn was of player2 and there is no tie so p2 wins
        cout<<p2<<" WINS!"<<endl;
   else
    if(token=='0' && tie == false)//Means  last turn was of player1 and there is no tie so p1 wins
        cout<<p1<<" WINS!"<<endl; 
   else 
    cout<<"It's Draw"<<endl;

 return 0;

}
