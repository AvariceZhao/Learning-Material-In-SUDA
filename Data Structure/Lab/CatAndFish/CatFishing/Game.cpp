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
	std::cout << "�������һ����ҵ�" << card_num << "����" << endl;
	for (int i = 1; i <= card_num; i++)
		cin >> player_a[i];
    std::cout << "��һ����������������" << endl;
    std::cout << endl;
    std::cout << "������ڶ�����ҵ�" << card_num << "����" << endl;
	for (int i = 1; i <= card_num; i++)
		cin >> player_b[i];
    std::cout << "�ڶ�����������������" << endl;
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
        if (count % 2 == 0)//A����
        {
            count++;
            auto t = a_card.front(); a_card.pop();
            std::cout << "A��" << t << " state[" <<t<<"]="<< state[t] << endl;
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
                    std::cout << "AӮ" << Top << endl;

                }
                auto Top = Table.top(); Table.pop();
                state[Top] = 0;
                temp.push(Top);
                std::cout << "AӮ" << Top << endl;
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
            std::cout << "B��" << t << " state[" << t << "]=" << state[t] << endl;
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
                std::cout << "BӮ" << Top << endl;

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
        std::cout << "B����ʣ�����Ϊ:";
        while (!b_card.empty())
        {
            std::cout << b_card.front() << " ";
            b_card.pop();
        }

    }
    else
    {
        std::cout << "A win" << endl;
        std::cout << "A����ʣ�����Ϊ:";
        while (!a_card.empty())
        {
            std::cout << a_card.front() << " ";
            a_card.pop();
        }

    }
    std::cout << endl;
    std::cout << "��ʱ����ʣ�����Ϊ:";
    while (!Table.empty())
    {
        std::cout << Table.top() << " ";
        Table.pop();
    }

}