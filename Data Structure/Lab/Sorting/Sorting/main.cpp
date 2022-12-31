#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
const int MAXNUM = 1e4 + 10;
struct hotel
{
	int distance, cost;
}Hotels[MAXNUM];
bool compare(hotel A, hotel B)
{
	return A.cost != B.cost ? A.cost < B.cost : A.distance < B.distance;
}
int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
			cin >> Hotels[i].distance >> Hotels[i].cost;
		sort(Hotels, Hotels + n, compare);
		int cnt = 0, min_distance = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (Hotels[i].distance < min_distance)
			{
				min_distance = Hotels[i].distance;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}