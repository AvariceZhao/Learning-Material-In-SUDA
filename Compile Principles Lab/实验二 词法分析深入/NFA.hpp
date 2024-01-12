//2127405037 zhaopeng
#include "utility.h"
#define epsilon '.'
class NFAEdge;
class NFAState
{
public:
	int data;
	vector<NFAEdge> outGoingEdges;
	NFAState() { data = 0; };
	NFAState(int id)
	{
		data = id;
		outGoingEdges.clear();
	}
};
class NFAEdge
{

public:
	NFAState* to;
	char c;
	NFAEdge(NFAState* to, char c)
	{
		this->c = c;
		this->to = to;
	}
};

class NFA
{
public:
	int stateCount;
	NFAState* NFAStart;
	NFAState* NFAEnd;

	set<NFAState*>NFAStatePointers;
	map<string, vector<string>> regexTree;
	string regexTreeRoot;
	
	map<int, map<char,set<int>>>NFATransition;
	set<char>alphbets;

	NFA()
	{
		stateCount = 0;
	};

	~NFA()
	{
		while (NFAStatePointers.size())
		{
			auto t = (*NFAStatePointers.begin());
			NFAStatePointers.erase(t);
			delete t;
		}
	}
	void Preperation()
	{
		for (auto i : NFAStatePointers)
		{

			for (auto edge : i->outGoingEdges)
			{
				
				if(edge.c!=epsilon)
				{
				alphbets.insert(edge.c);
				}
				if(NFAStatePointers.count(edge.to)!=0)

				NFATransition[i->data][edge.c].insert(edge.to->data);
			}
		}
	}
	NFA(map<string, vector<string>> T, string root)
	{
		stateCount = 0;
		regexTree = T;
		NFATransition.clear();
		alphbets.clear();
		regexTreeRoot = root;
		NFAStatePointers.clear();
		auto t = recursiveBuild(root);
		NFAStart = t->NFAStart;
		NFAEnd = t->NFAEnd;
	
	}

	NFA(map<int, map<char, set<int>>> trans)
	{
		this->NFATransition = trans;

	}
	private:
	NFA* recursiveBuild(string currentNode)
	{

		vector<string> sonNodes = regexTree[currentNode];

		if (currentNode.length() >= 2 && sonNodes.size() == 1)
		{
			
			return singleChar(sonNodes[0][0]);
		}
		else if (sonNodes.size() == 3)
		{
			
			string firstNode = sonNodes[1];

			if (firstNode[0] == '|')
			{
				return OR(recursiveBuild(sonNodes[0]), recursiveBuild(sonNodes[2]));
			}
			else if (sonNodes[0][0] == '(' && sonNodes[2][0] == ')')
			{

				return recursiveBuild(sonNodes[1]);
			}
		}
		else if (sonNodes.size() == 2)
		{
		
			
			if (sonNodes[0].size() >= 2 && sonNodes[1].size() >= 2)
			{
				
				return AND(recursiveBuild(sonNodes[0]), recursiveBuild(sonNodes[1]));
			}
			else if (sonNodes[0].size() >= 2 && sonNodes[1].size() == 1 && sonNodes[1][0] == '*')
			{

				return CLOSURE(recursiveBuild(sonNodes[0]));
			}
		}
		return NULL;
	}

	NFA* singleChar(char ch)
	{
		auto NFAStart = new NFAState(++stateCount), NFAEnd = new NFAState(++stateCount);
		NFA* ans = new NFA();

		NFAStatePointers.insert(NFAStart);
		NFAStatePointers.insert(NFAEnd);


		NFAStart->outGoingEdges.push_back(NFAEdge(NFAEnd, ch));
		ans->NFAStart = NFAStart;
		ans->NFAEnd = NFAEnd;
		return ans;
	}
	NFA* OR(NFA* NFA1, NFA* NFA2)

	{
		auto NFAStart = new NFAState(++stateCount), NFAEnd = new NFAState(++stateCount);

		NFAStart->outGoingEdges.push_back(NFAEdge(NFA1->NFAStart, epsilon));
		NFAStart->outGoingEdges.push_back(NFAEdge(NFA2->NFAStart, epsilon));
		NFA1->NFAEnd->outGoingEdges.push_back(NFAEdge(NFAEnd, epsilon));
		NFA2->NFAEnd->outGoingEdges.push_back(NFAEdge(NFAEnd, epsilon));

		NFA* ans = new NFA();
		ans->NFAStart = NFAStart;
		ans->NFAEnd = NFAEnd;
		NFAStatePointers.insert(NFAStart);
		NFAStatePointers.insert(NFAEnd);

		return ans;
	}

	NFA* AND(NFA* NFA1, NFA* NFA2)
	{

		
		NFA* ans = new NFA();
		auto NFAStart = new NFAState(++stateCount), NFAEnd = new NFAState(++stateCount);
		ans->NFAStart = NFA1->NFAStart;
		ans->NFAEnd = NFA2->NFAEnd;
		auto i = NFA1->NFAEnd, j = NFA2->NFAStart;
	
		NFAStatePointers.insert(NFAStart);
		NFAStatePointers.insert(NFAEnd);

		for (NFAEdge e : j->outGoingEdges)
		{
			i->outGoingEdges.push_back(e);
		}
		NFAStatePointers.erase(j);
		delete j;
		return ans;
	}

	NFA* CLOSURE(NFA* NFA1)
	{
		NFA* ans = new NFA();
		auto NFAStart = new NFAState(++stateCount), NFAEnd = new NFAState(++stateCount);
		ans->NFAStart = NFAStart;
		ans->NFAEnd = NFAEnd;

		NFAStatePointers.insert(NFAStart);
		NFAStatePointers.insert(NFAEnd);

		ans->NFAStart->outGoingEdges.push_back(NFAEdge(NFA1->NFAStart, epsilon));
		NFA1->NFAEnd->outGoingEdges.push_back(NFAEdge(NFAEnd, epsilon));
		NFA1->NFAEnd->outGoingEdges.push_back(NFAEdge(NFA1->NFAStart, epsilon));
		NFAStart->outGoingEdges.push_back(NFAEdge(NFAEnd, epsilon));

		return ans;
	}
};
