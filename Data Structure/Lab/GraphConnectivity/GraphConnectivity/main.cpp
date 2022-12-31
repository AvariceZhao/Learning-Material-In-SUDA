
#include <iostream>
#include"Graph.h"
int main()
{
	int N, Q;
	std::cin >> N >> Q;

	Graph<int>G(N);


	

	while (Q--)
	{
		char op = ' ';
		int u = 0, v = 0;
		std::cin >> op >> u >> v;
		if (op == 'I')
			G.AddEdge(u, v);
		else if (op == 'D')
			G.DeleteEdge(u, v);
		else
			if (G.JudgeConnectivity(u, v))
				puts("Y");
			else
				puts("N");
		getchar();
	}
	return 0;
	
}

