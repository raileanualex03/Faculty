#include <vector>


class Sale
{
public:
	std::vector<SaleItem> saleItems;
	Sale() {};
};

class SaleItem {
public:
	int _code;
	double _price;
};