/* 
* @Author: anchen
* @Date:   2016-08-06 12:09:08
* @Last Modified by:   anchen
* @Last Modified time: 2016-08-06 12:14:20
* @Last Modified time: 2016-08-06 12:17:00
* @Last Modified time: 2016-08-06 12:19:12
*/

#include <iostream>
#include <string>
#ifndef SALES_ITEM_H
#define SALES_ITEM_H
using std::istream;using std::ostream;
class Sales_item
{
public:
	Sales_item(const std::string &book, unsigned units, double amount) :
		isbn(book), units_sold(units), revenue(amount) {}
	Sales_item() :units_sold(0), revenue(0.0) {}
	friend std::ostream& operator<<(std::ostream&, const Sales_item&);
	double avg_price()const;
	bool same_isbn(const Sales_item &rhs)const
	{
		return isbn == rhs.isbn;
	}

private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};
inline ostream& operator<<(ostream& out, const Sales_iteam& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t"
		<< s.revenue << "\t" << s.avg_price();
	return out;
}
inline double Sales_item::avg_price()const
{
	if (units_sold)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}
}
#endif // !SALES_ITEM_H

 
