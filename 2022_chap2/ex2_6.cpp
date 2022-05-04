#include <iostream>
using namespace std;
class Math   //MonoTone
{
public:
	static double CircleArea(int r)
	{
		return  r * r*3.14;
	}
	static int RectArea(int h, int w) {
		return  h * w;
	}
};
int main()
{
	cout << Math::CircleArea(5) << endl;
	cout << Math::RectArea(3, 6) << endl;
	return 0;
}
