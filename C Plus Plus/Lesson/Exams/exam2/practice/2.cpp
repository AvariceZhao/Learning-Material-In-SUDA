#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Record
{
private:
	string name;
	int hour, minute, second;
	double latitude, longitude;
public:
	Record(string t_name="noName",int t_hour=0,int t_minute=0,int t_second=0,double t_latitude=0,double t_longitude=0)
	{
		name=t_name,hour=t_hour,minute=t_minute,second=t_second,latitude=t_latitude,longitude=t_longitude;
	}
	string getName()const
	{
		return name;
	}
	int getHour()const
	{
		return hour;
	}
	int getMinute()const
	{
		return minute;
	}
	int getSecond()const
	{
		return second;
	}
	double getLatitude()const
	{
		return latitude;
	}
	double getLongitude()const
	{
		return longitude;
	}
	friend Record & operator++(Record &r)
	{
	r.second ++;
    if(r.second == 60) r.minute ++, r.second = 0;
    if(r.minute == 60) r.hour ++, r.minute = 0;
    if(r.hour == 24) r.hour = 0;
    return r;
	}
	friend Record operator+(const Record &r,const double &data)
	{
		    return Record(r.name, r.hour, r.minute, r.second, r.latitude + data, r.longitude + data);
	}
	friend ostream& operator<<(ostream &out,Record &r)
	{
	out << setw(10) << left << r.name;
    out << right << setw(2) << r.hour << ":" << setw(2) << r.minute << ":" << setw(2) << r.second;
    out << right << fixed << setprecision(10) << setw(20) << r.latitude << setw(20) << r.longitude;
    return out;
	}
};
int main()
{
Record  record1("Randy", 11, 12, 13, 34.15, 117.21);
	Record  record2(record1);
	cout << record2 << endl;

	vector<Record> vec_record;
	string path = "D:\\location.txt";
	inputData(path, vec_record);

	processTime(vec_record);
	cout<< "After time processing: " << endl;
	outPut(vec_record, 10);

	processLocation(vec_record);
	cout<<"After location processing: " << endl;
	outPut(vec_record, 10);
	return 0;
} 
