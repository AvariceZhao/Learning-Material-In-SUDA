
#include <iostream>
#include"SocialGraph.h"
using namespace std;
void showFunction()
{
	cout << "*****Functions*****" << endl;
	cout << "[0] Calculate Shortest Path between two people" << endl;
	cout << "[1] Calculate the people one can indirectly know" << endl;
	cout << "[2] Judge whether everyone can know each other" << endl;
	cout << "[3] Add new relationship" << endl;
	cout << "[4] Delete relationship" << endl;
	cout << "[5] Add new people to the social graph" << endl;
	cout << "[6] Delete people from the social graph" << endl;
	cout << "[7] Get the crucial people and crucial edge in the social graph" << endl;
	cout << "[8] Exit" << endl;
	cout << "*****End*****" << endl;

}

inline void Operator(SocialGraph &Graph,int id)
{
	if (id < 0 || id >7)
	{
		cout << "Error operation!" << endl;
		return;
	}
	string name;
	int x, y;
	switch (id)
	{
	case 0:
		cout << "Input the id of two people" << endl;
		cin >> x >> y;
		cout <<"Shortest Path:"<< Graph.ShortestPath(x, y) << endl;
		break;
	case 1:
		cout << "Input the id of people" << endl;
		cin >> x;
		Graph.PeopleCanKnow(x);
		break;
	case 2:
		if (Graph.judgeConnect())
			cout << "People can know each other from their friends" << endl;
		else
			cout << "People can not know each other" << endl;
		break;
	case 3:
		cout << "Input the id of two people you want to add relationship" << endl;
		cin >> x >> y;
		Graph.addEdge(x, y);
		break;
	case 4:
		cout << "Input the id of two people you want to delete relationship" << endl;
		cin >> x >> y;
		Graph.deleteEdge(x, y);
		break;
	case 5:

		cout << "Input people's name you want to add to the social graph" << endl;
		cin >> name;
		Graph.addPeople(name);
		break;
	case 6:
		cout << "Input the id of people you want to delete from the graph" << endl;
		cin >> x;
		Graph.deletePeople(x);
		break;
	case 7:
		Graph.getVDCC_EDCC();
		break;
	case 8:
		exit(0);
		break;
	default:
		break;
	}
}
int main()
{
	SocialGraph Graph;
	showFunction();
	
	while (true)
	{

		int id;
		cin >> id;
		Operator(Graph, id);
		cout << "----------------------------" << endl;
	}
	
	return 0;
}
