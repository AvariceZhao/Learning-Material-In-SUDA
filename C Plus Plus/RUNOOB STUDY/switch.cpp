
#include <iostream>
using namespace std;
 
int main ()
{
   // �ֲ���������
   char grade = 'D';
 
   switch(grade)
   {
   case 'A' :
      cout << "�ܰ���" << endl; 
      break;
   case 'B' :
   case 'C' :
      cout << "���ú�" << endl;
      break;
   case 'D' :
      cout << "��ͨ����" << endl;
      break;
   case 'F' :
      cout << "�������һ��" << endl;
      break;
   default :
      cout << "��Ч�ĳɼ�" << endl;
   }
   cout << "���ĳɼ��� " << grade << endl;
 
   return 0;
}
