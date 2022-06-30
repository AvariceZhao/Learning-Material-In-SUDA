#include<iostream>
using namespace std;
int main()
{
 int month,day;
 cout<<"请输入月和日"<<endl;
 cin>>month>>day;
 int days=365;
 switch(month)
 {
 	case 1: days-=31;
 	case 2: days-=28;
	case 3: days-=31;
	case 4: days-=30;
	case 5: days-=31;
	case 6: days-=30;
	case 7: days-=31;
	case 8: days-=31;
	case 9: days-=30;
	case 10: days-=31;
	case 11: days-=30;
	case 12: days-=31;
 }
 days+=day;
 switch(days%7)
 {
	case 0:cout<<"星期五";break;
	case 1:cout<<"星期六";break;
	case 2:cout<<"星期天";break;
	case 3:cout<<"星期一";break;
	case 4:cout<<"星期二";break;
	case 5:cout<<"星期三";break;
	case 6:cout<<"星期四";break;
 }
 return 0;
}