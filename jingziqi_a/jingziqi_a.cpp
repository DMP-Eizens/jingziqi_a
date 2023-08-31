#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<windows.h>
using namespace std;

int board[9] = { 0 };
int sequence[9] = { 0 };

void display(){}
void print(int result){}
void ai(int round){}
bool win(){}

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
