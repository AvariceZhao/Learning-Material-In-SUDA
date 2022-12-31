#include"Tree.h"
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m&&(n || m))
    {
        getchar();
        Tree T;
        for (int i = 0; i < n; i++)
            T.SaveInfo(i);
        string s1, s2, s3;
        while (m--)
        {
            cin >> s1;
            for (int i = 1; i <= 3; i++)cin >> s3;
            for (int i = 1; i <= 2; i++)cin >> s2;
            s2.erase(s2.end() - 1);
            if (T.judge(s1, s2, s3))
                cout << "True" << endl;
            else
                cout << "False" << endl;
        }
        cout << endl;
    }
}

