#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int MinCurrentMapProfit = -1;

typedef vector<int> VecInt;

int main(int argc, char* argv)
{
	//////////////INPUT//////////////
	
	// *Costs per product
	int Expense = 1100;

	// *PriceVector is a survey of potential consumers, where they name the price of the product for which they would take it
	VecInt PriceVector{ 4000, 2500, 3000, 5000, 3500, 2000, 5000, 3200, 1500, 4000, 2000, 4000, 4500, 3000, 5000, 2500, 3500, 2000, 3500, 4000 };

	/////////////////////////////////

	sort(PriceVector.begin(), PriceVector.end());

	auto PriceVectorSorted = move(PriceVector);

	VecInt VecUniqied;
	unique_copy(PriceVectorSorted.cbegin(), PriceVectorSorted.cend(), back_inserter(VecUniqied));

	if (VecUniqied.size() != VecUniqied.capacity())
	{
		VecUniqied.shrink_to_fit();
	}
	const int Size = VecUniqied.size();
	VecInt::iterator It = VecUniqied.begin();

	VecInt Demand(Size);

	for (int i = 0; It != VecUniqied.cend(); ++It, i++)
	{
		Demand[i] = count(cbegin(PriceVectorSorted), cend(PriceVectorSorted), *It);
	}
	PriceVectorSorted.clear();

	for (int i = 0; i < Size; i++)
	{
		auto ItDemand = Demand.begin() + i;
		int j = 0;

		for (; ItDemand != Demand.cend(); ++ItDemand)
		{
			j += *ItDemand;
		}
		Demand[i] = j;
	}

	VecInt Profit(Size);
	map<int, int> MapPriceProfit;
	for (int i = Size - 1; i != MinCurrentMapProfit; --i)
	{
		Profit[i] = (VecUniqied[i] - Expense) * Demand[i];

		MapPriceProfit.emplace(Profit[i], VecUniqied[i]);
	}
	VecInt::const_iterator MaxProfit = max_element(Profit.cbegin(), Profit.cend());

	////////////////////OUTPUT////////////////

	cout << "The maximum profit, equal to " << *MaxProfit << " rubles, is achieved at a price of " << MapPriceProfit[*MaxProfit] << " rubles per copy" << endl;

	//////////////////////////////////////////

	return 0;
}