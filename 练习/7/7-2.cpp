#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cstdlib>

using namespace std;

class Sales_data {
private: // 定义私有数据成员
	string bookNo;  // 数据编号，隐式初始化为空串
	unsigned units_sold = 0;  // 销售量，显式初始化为0
	double sellingprice = 0.0;//原始价格，显式初始化为0.0
	double saleprice = 0.0; //实售价格，显式初始化为0.0
	double discount = 0.0; // 折扣，显式初始化为0.0
public:
	string iabn() const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		saleprice = (saleprice * (units_sold - rhs.units_sold) + rhs.units_sold * rhs.saleprice) / units_sold;
		if (sellingprice != 0)
			discount = saleprice / sellingprice;
		return *this;

	}
};

int main()
{

}

