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
	string bookNo;  // ���ݱ�ţ���ʽ��ʼ��Ϊ�մ�
	unsigned units_sold = 0;  // ����������ʽ��ʼ��Ϊ0
	double sellingprice = 0.0;//ԭʼ�۸���ʽ��ʼ��Ϊ0.0
	double saleprice = 0.0; //ʵ�ۼ۸���ʽ��ʼ��Ϊ0.0
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
    Sales_data total;
}

