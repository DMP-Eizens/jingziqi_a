#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<windows.h>
using namespace std;

int board[9] = { 0 };
int sequence[9] = { 0 };

void displaychar(int loc)
{
    switch (board[loc])
    {
    case 0:
        cout << " ";
        break;
    case 1:
        cout << "X";
        break;
    case 2:
        cout << "O";
        break;
    }
    return;
}

void display()
{
    cout << endl;
    cout << "     |     |     " << endl;

    cout << "  ";
    displaychar(0);
    cout << "  |  ";
    displaychar(1);
    cout << "  |  ";
    displaychar(2);
    cout << endl;

    cout << "     |     |     " << endl
        << "-----|-----|-----" << endl
        << "     |     |     " << endl;

    cout << "  ";
    displaychar(3);
    cout << "  |  ";
    displaychar(4);
    cout << "  |  ";
    displaychar(5);
    cout << endl;

    cout << "     |     |     " << endl
        << "-----|-----|-----" << endl
        << "     |     |     " << endl;

    cout << "  ";
    displaychar(6);
    cout << "  |  ";
    displaychar(7);
    cout << "  |  ";
    displaychar(8);
    cout << endl;

    cout << "     |     |     " << endl;
    cout << endl;

    return;
}
void print(int result)
{
    ofstream fout;
    fout.open("./jilu.txt", ios::out | ios::app);

    time_t nowtime;
    time(&nowtime);
    tm p;
    localtime_s(&p, &nowtime);
    fout << p.tm_year + 1900 << " " << p.tm_mon + 1 << "." << p.tm_mday << " " << p.tm_hour << ":" << p.tm_min << ":" << p.tm_sec << endl;

    switch (result)
    {
    case 0:
        fout << "此局游戏未完成" << endl;
        break;
    case 2:
        fout << "此局游戏玩家胜出" << endl;
        break;
    case 1:
        fout << "此局游戏电脑胜出" << endl;
        break;
    case 3:
        fout << "此局游戏平局" << endl;
        break;
    }

    fout << endl << "     |     |     " << endl;
    fout << "  ";
    switch (board[0])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << "  |  ";
    switch (board[1])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << "  |  ";
    switch (board[2])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << endl;

    fout << "   ";
    if (sequence[0] == 0)fout << " ";
    else fout << sequence[0];
    fout << " |   ";
    if (sequence[1] == 0)fout << " ";
    else fout << sequence[1];
    fout << " |   ";
    if (sequence[2] == 0)fout << " ";
    else fout << sequence[2];

    fout << endl;
    fout << "-----|-----|-----" << endl
        << "     |     |     " << endl;
    fout << "  ";
    switch (board[3])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << "  |  ";
    switch (board[4])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << "  |  ";
    switch (board[6])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << endl;

    fout << "   ";
    if (sequence[3] == 0)fout << " ";
    else fout << sequence[3];
    fout << " |   ";
    if (sequence[4] == 0)fout << " ";
    else fout << sequence[4];
    fout << " |   ";
    if (sequence[5] == 0)fout << " ";
    else fout << sequence[5];

    fout << endl;
    fout << "-----|-----|-----" << endl
        << "     |     |     " << endl;
    fout << "  ";
    switch (board[6])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << "  |  ";
    switch (board[7])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << "  |  ";
    switch (board[8])
    {
    case 0:
        fout << " ";
        break;
    case 1:
        fout << "X";
        break;
    case 2:
        fout << "O";
        break;
    }
    fout << endl;

    fout << "   ";
    if (sequence[6] == 0)fout << " ";
    else fout << sequence[6];
    fout << " |   ";
    if (sequence[7] == 0)fout << " ";
    else fout << sequence[7];
    fout << " |   ";
    if (sequence[8] == 0)fout << " ";
    else fout << sequence[8];

    fout << endl << "******************" << endl;
    return;
}
void ai(int round){}
bool win(){
    return (board[0] == board[1] && board[0] == board[2] && board[0] != 0)
        || (board[3] == board[4] && board[3] == board[5] && board[3] != 0)
        || (board[6] == board[7] && board[6] == board[8] && board[6] != 0)

        || (board[0] == board[3] && board[0] == board[6] && board[0] != 0)
        || (board[1] == board[4] && board[1] == board[7] && board[1] != 0)
        || (board[2] == board[5] && board[2] == board[8] && board[2] != 0)

        || (board[0] == board[4] && board[0] == board[8] && board[0] != 0)
        || (board[2] == board[4] && board[2] == board[6] && board[2] != 0);
}

int main()
{
    char command;
    cout << "欢迎使用本井字棋程序，输入a开始游戏，输入s查看介绍与帮助，输入d结束游戏" << endl;

    ////////
programstart:
    ////////

    int result = 0;
    cin >> command;
    switch (command)
    {
    case 'a':
        break;
    case 's':
        cout << "这是一款控制台井字棋程序，你可以和电脑对战，结果将自动保存在程序所在目录" << endl
            << "输入a开始游戏，输入d结束游戏，初始页面时输入s查看介绍与帮助" << endl
            << "玩家扮演 X先手，电脑扮演 O，通过输入数字1-9在对应位置落子" << endl
            << "游戏中输入a将重新开始游戏，本局记为未完成" << endl
            << "准备好了就输入a开始吧" << endl;
        goto programstart;
    case 'd':
        goto end;
    default:
        cout << "无效输入，请检查指令是否正确" << endl;
        goto programstart;
    }

    ////////
gamestart:
    ////////

    for (int i = 0; i < 9; i++)
    {
        board[i] = 0;
        sequence[i] = 0;
    }

    display();
    for (int round = 1; round <= 9; round++)
    {
        if (round % 2 != 0)
        {

            ////////
        getcommand:
            ////////

            cin >> command;
            switch (command)
            {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (board[command - 49] == 0)
                {
                    board[command - 49] = 1;
                    sequence[command - 49] = round;
                }
                else
                {
                    cout << "此位置已有落子！" << endl;
                    goto getcommand;
                }
                break;
            case 'a':
            case 'd':
                goto record;
            default:
                cout << "无效输入，请检查指令是否正确" << endl;
                goto getcommand;
            }
        }
        else ai(round);
        display();
        if (win())
        {
            result = round % 2 + 1;
            goto record;
        }
    }
    result = 3;

    ////////
record:
    ////////

    print(result);
    if (command == 'a')
    {
        cout << "重新开始游戏" << endl;
        goto gamestart;
    }
    if (command == 'd')
    {
        goto end;
    }
    switch (result)
    {
    case 2:
        cout << "恭喜你取得胜利！" << endl;
        break;
    case 1:
        cout << "很遗憾你失败了" << endl;
        break;
    case 3:
        cout << "平局" << endl;
        break;
    }
    cout << "输入a再来一局，输入s查看介绍与帮助，输入d结束游戏" << endl;
    goto programstart;

    ////////
end:
    ////////

    cout << "结束游戏" << endl;
    return 20641110;
}
