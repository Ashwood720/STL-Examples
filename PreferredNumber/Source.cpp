#include <array>
#include <iostream>

using namespace std;
typedef array<float, 41> FloatArray;
constexpr int a = 40;

enum class ERa : unsigned short int
{
	Ra5, Ra10, Ra20, Ra40
};

int main(int argc, char* argv)
{
	ERa Ra = ERa::Ra20;
	int b = 0;

	if (Ra != ERa::Ra40)
	{
		b = (static_cast<int>(Ra) * 2);
	}
	else
	{
		b = 1;
	}

	FloatArray PrefNumArray = { 1.0f, 1.06f, 1.12f, 1.18f, 1.25f, 1.32f, 1.4f, 1.5f, 1.6f, 1.70f, 1.80f, 1.90f, 2.00f, 2.12f, 2.24f, 2.36f, 2.50f, 2.65f, 2.80f, 3.00f, 3.15f, 3.35f, 3.55f, 3.75f, 4.00f, 4.25f, 4.50f, 4.75f, 5.0f, 5.30f, 5.60f, 6.00f, 6.30f, 6.70f, 7.10f, 7.50f, 8.00f, 8.50f, 9.00f, 9.50f, 10.00f };

	FloatArray::const_pointer p_begin = &*PrefNumArray.cbegin();
	auto p_current = p_begin;

	cout << *p_begin << endl;

	for (int i = 0; i < 40 / b; i++)
	{
		p_current += b;
		cout << *p_current << endl;
	}
	p_current = p_begin;

	return 0;
}