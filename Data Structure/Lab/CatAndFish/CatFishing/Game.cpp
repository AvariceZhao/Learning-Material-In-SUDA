#include "utility.h"
#include "Game.h"
#include "LinkQueue.hpp"
#include "LinkStack.hpp"
Game::Game(int num)
{
	card_num = num;
    memset(state, 0, sizeof state);
}
void Game::init()
{
	std::cout << "请输入第一名玩家的" << card_num << "张牌" << endl;
	for (int i = 1; i <= card_num; i++)
		cin >> player_a[i];
    std::cout << "第一名玩家数据输入完成" << endl;
    std::cout << endl;
    std::cout << "请输入第二名玩家的" << card_num << "张牌" << endl;
	for (int i = 1; i <= card_num; i++)
		cin >> player_b[i];
    std::cout << "第二名玩家数据输入完成" << endl;
}
void Game::work()
{
	Queue<int>a_card, b_card;
	Stack<int>Table;
	int count = 0;
	
	for (int i = 1; i <= card_num; i++)
		a_card.push(player_a[i]);
	for (int i = 1; i <= card_num; i++)
		b_card.push(player_b[i]);

    while (!a_card.empty() && !b_card.empty())
    {
        std::cout << "count  #"<< count << endl<<endl;
        if (count % 2 == 0)//A出牌
        {
            count++;
            auto t = a_card.front(); a_card.pop();
            std::cout << "A出" << t << " state[" <<t<<"]="<< state[t] << endl;
            Table.push(t);
            if (state[t] == 1)
            {
                Stack<int>temp;
                Table.pop();
                temp.push(t);
                while (Table.top() != t)
                {
                    auto Top = Table.top(); Table.pop();
                    state[Top] = 0;
                    temp.push(Top);
                    std::cout << "A赢" << Top << endl;

                }
                auto Top = Table.top(); Table.pop();
                state[Top] = 0;
                temp.push(Top);
                std::cout << "A赢" << Top << endl;
                while (!temp.empty())
                {
                    auto now = temp.top(); temp.pop();
                    a_card.push(now);
                }
            }
            else
            {

                state[t] = 1;
            }
        }
        else
        {
            count++;
            auto t = b_card.front(); b_card.pop();
            std::cout << "B出" << t << " state[" << t << "]=" << state[t] << endl;
            Table.push(t);
            if (state[t] == 1)
            {
                Stack<int>temp;
                Table.pop();
                temp.push(t);
                while (Table.top() != t)
                {
                    auto Top = Table.top(); Table.pop();
                    state[Top] = 0;
                    temp.push(Top);
                    std::cout << "B" << Top << endl;

                }

                auto Top = Table.top(); Table.pop();
                state[Top] = 0;
                temp.push(Top);
                std::cout << "B赢" << Top << endl;

                while (!temp.empty())
                {
                    auto now = temp.top(); temp.pop();
                    b_card.push(now);
                }
            }
            else
            {

                state[t] = 1;
            }
        }
        std::cout << "-----------------------------------------------------------------------------" << endl;
    }

    if (a_card.empty())
    {
        std::cout << "B win" << endl;
        std::cout << "B手中剩余的牌为:";
        while (!b_card.empty())
        {
            std::cout << b_card.front() << " ";
            b_card.pop();
        }

    }
    else
    {
        std::cout << "A win" << endl;
        std::cout << "A手中剩余的牌为:";
        while (!a_card.empty())
        {
            std::cout << a_card.front() << " ";
            a_card.pop();
        }

    }
    std::cout << endl;
    std::cout << "此时桌上剩余的牌为:";
    while (!Table.empty())
    {
        std::cout << Table.top() << " ";
        Table.pop();
    }

}