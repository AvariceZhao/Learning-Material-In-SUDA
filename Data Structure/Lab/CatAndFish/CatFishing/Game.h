#pragma once
class Game
{	private:
	static const int MAX_SIZE = 1000 + 10;
	int player_a[MAX_SIZE], player_b[MAX_SIZE];
	int state[MAX_SIZE];
	int card_num;
public:
	Game(int num);
	void init();
	void work();
};