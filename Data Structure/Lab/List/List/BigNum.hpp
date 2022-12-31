#pragma once
#include<cstring>
#include<iostream>
#include <vector>
#define positive 0
#define negative 1
class BigNum
{
public:
	std::vector<int>num;//存储每一位数字
	BigNum();
	BigNum(const BigNum& Num);
	BigNum(const std::vector<int> Num, int Sign);
	BigNum(const std::string& str);
	BigNum operator +( BigNum& Num);
	void print();
	BigNum operator -( BigNum& num);
	BigNum operator *( BigNum& num);
private:
	int sign;//正负
	bool cmp(std::vector<int>& A, std::vector<int>& B);
	std::vector<int> add(const std::vector<int>& A, const  std::vector<int>& B);
	std::vector<int> sub(const std::vector<int>& A, const std::vector<int>& B);
	std::vector<int> multi (std::vector<int>& A, std::vector<int>& B);
};
BigNum::BigNum() {};
BigNum::BigNum(const BigNum& Num) :num(Num.num), sign(Num.sign) {};
BigNum::BigNum(const std::vector<int> Num, int Sign) :num(Num), sign(Sign) {};
BigNum::BigNum(const std::string& str)
{
	for (auto c : str)
	{
		if (!((c >= '0' && c <= '9') || c == '+' || c == '-'))
			throw std::runtime_error{ "Invalid character is given" };
	}
	if (str[0] == '-')
	{
		sign = negative;
		for (int i = str.size() - 1; i >= 1; i--)
			num.push_back(str[i] - '0');
	}
	else
	{
		sign = positive;
		int i_bound = 0;
		if (str[0] == '+')i_bound = 1;
		for (int i = str.size() - 1; i >= i_bound; i--)
			num.push_back(str[i] - '0');
	}

}

BigNum BigNum::operator +( BigNum& Num)//进行两个正数相加
{
	if (sign == positive && Num.sign == positive)//正+正
	{
		std::vector<int>C = add(num, Num.num);
		BigNum ans(C, positive);
		return ans;
	}
	if (sign == negative && Num.sign == negative)
	{
		std::vector<int>C = add(num, Num.num);
		BigNum ans(C, negative);
		return ans;
	}
	std::vector<int>& A = num; std::vector<int>& B = Num.num;
	if (sign == positive && Num.sign == negative)//减法 A-B
	{
		std::vector<int> C;
		if (cmp(A, B))
		{
			C = sub(A, B);
			BigNum ans(C, positive);
			return ans;
		}
		else
		{
			C = sub(B, A);
			BigNum ans(C, negative);
			return ans;
		}
	}
	if (sign == negative && Num.sign == positive)//减法 B-A
	{
		std::vector<int> C;
		if (cmp(A, B))
		{
			C = sub(A, B);
			BigNum ans(C, negative);
			return ans;
		}
		else
		{
			C = sub(B, A);
			BigNum ans(C, positive);
			return ans;
		}
	}


}

BigNum BigNum::operator-(BigNum&Num)
{
	if (sign == positive && Num.sign == positive)//正-正
	{
		BigNum B(Num.num, negative);
		return (*this) + B;
	}
	if (sign == negative && Num.sign == negative)//负-负=负+正
	{
		BigNum B(Num.num, positive);
		return (*this) + B;
	}
	std::vector<int>& A = num; std::vector<int>& B = Num.num;
	if (sign == positive && Num.sign == negative)//正-负=正+正
	{
		auto temp = add(num, Num.num);
		BigNum ans(temp, positive);
		return ans;
	}
	if (sign == negative && Num.sign == positive)//负-正
	{
		BigNum ans(add(num, Num.num), negative);
		return ans;
	}
}

BigNum BigNum::operator*(BigNum &Num)
{
	if (sign ^ Num.sign)
	{
		BigNum ans(multi(num, Num.num), negative);
		return ans;
	}
	else
	{
		BigNum ans(multi(num, Num.num), positive);
		return ans;
	}
}
void BigNum::print()
{
	//std::cout << num.size();
	if (sign == negative)
		std::cout << "-";
	for (int i = (int)num.size() - 1; i >= 0; i--)
	{
		std::cout << num[i];
	}
	std::cout << std::endl;
}


bool BigNum::cmp(std::vector<int>& A, std::vector<int>& B)
{
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; i--)
		if (A[i] != B[i])
			return A[i] > B[i];
	return true;
}

std::vector<int>  BigNum::add( const std::vector<int>& A,const  std::vector<int>& B)
{
	if (A.size() < B.size()) return add(B, A);

	std::vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t) C.push_back(t);
	return C;
}
std::vector<int> BigNum::sub(const std::vector<int>& A,const  std::vector<int>& B)
{
	std::vector<int> C;
	for (int i = 0, t = 0; i < A.size(); i++)
	{
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

std::vector<int>BigNum:: multi(std::vector<int>& A, std::vector<int>& B) {

	std::vector<int> C(A.size() + B.size(), 0);
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
		
			C[i + j] += A[i] * B[j]; 
		}
	}
	int t = 0;  
	for (int i = 0; i < C.size(); i++) {
		t = t + C[i]; 
		C[i] = t % 10;  
		t /= 10;  
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
