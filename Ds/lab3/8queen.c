/**
 *利用栈操作实现八皇后问题求解
 */
#include <iostream>
#include<cmath>
using namespace std;
#define StackSize 8 /*最多放8个皇后*/
int queen[StackSize][StackSize]={0}; /*棋盘*/
int ans=0;                           /*解数*/
int top=-1;                          /*栈顶指针*/ 
int data[StackSize];                  /*存储皇后位置*/ 

/*入栈*/ 
void Push(int x)                                          //入栈操作
{
    top++;                                                           //栈顶指针上移
    data[top]=x;
}
/*出栈*/ 
void Pop()                                              //出栈操作
{
    top--;                                                           //栈顶指针下移
}

void SeqStack(){top=-1;}                                              //构造函数，初始化空栈

/*放N皇后的递归函数*/
void PlaceQueen(int row)                                //在栈顶放置符合条件的值的操作,即摆放皇后
{
    bool Judgement();
    void SeqStack();                                    //关键点1：每一次摆放都会初始化空栈
    void Output();
    for (int col=0;col<StackSize;col++)                              //穷尽0~7，即穷尽列
    {
        Push(col);
        if (Judgement())                                             //判断摆放皇后的位置是否安全
        {
            if (row<StackSize-1)                                     //若还没有放到第八个皇后，则进行下一个皇后的放置
                PlaceQueen(row+1);                                    
            else
            {
                ans++;                                               //解数加1
                Output();                                            //打印成功的棋盘
            }
        }
        Pop();                                                       //若不符合条件则出栈        
    }
}

/*关键点2：判断合法性*/
bool Judgement()
{
    for(int i=0;i<top;i++)                                           //依次检查前面各行的皇后位置
        if(data[top]==data[i]||(abs(data[top]-data[i]))==(top-i))    //判断是否在同一列同一斜线
            return false;                                            /*第一个条件，使每次入栈的数字不同层（行）*/   
    return true;                                                     /*top-i的值就是皇后之间的非法相对距离，值为0、1、2....，也就是同一条对角线或者斜对角线。data[top]-data[i]为2个皇后的实际的相对距离。*/  
}

/*输出棋盘*/ 
void Output()                                          //将栈的数组形式打印成棋盘形式
{
    cout<<"NO."<<ans<<":"<<endl;                                    
    for(int i=0;i<StackSize;i++)
    {
        for(int j=0;j<data[i];j++)
            cout<<"- ";                                             //不放置处打印“-”
        cout<<"Q";                                                  //放置处打印“Q”
        for(int j=StackSize-1;j>data[i];j--)
            cout<<" -";
        cout<<endl;                                                 //换行
    }
    cout<<endl;
}
int main()
{
    PlaceQueen(0);                                        //从栈底开始赋值
    cout<<"the total number of solutions is:"<<ans<<endl;       //输出摆放方法的总数
    system("pause");
    return 0;
}