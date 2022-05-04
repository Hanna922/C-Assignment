#include<iostream>
using namespace std;
#include "cat.h"
#include "dog.h"
#include "duck.h"
#include "goldFish.h"

int main()  // class Adapter pattern 
{
	Cat cat("야옹이", Pet::MAMMAL, 2);
	Dog dog("멍멍이", Pet::MAMMAL, 5);
	Duck duck("도널드", Pet::BIRDS, 1);
	GoldFish goldFish("니모", Pet::FISH, 2);

	cout << "\n** Cat객체 테스트 **" << endl;
	cat.eat();
	cat.creep();
	cat.view();

	cout << "\n** Dog객체 테스트 **" << endl;
	dog.eat();
	dog.creep();
	dog.view();

	cout << "\n** Duck객체 테스트 **" << endl;
	duck.eat();
	duck.creep();
	duck.swim();
	duck.view();

	cout << "\n** GoldFish객체 테스트 **" << endl;
	goldFish.eat();
	goldFish.swim();
	goldFish.view();


	Pet *petAry[4] = { new Cat("야옹이", Pet::MAMMAL, 2), new Dog("멍멍이", Pet::MAMMAL, 5),
				  new Duck("도널드", Pet::BIRDS, 1), new GoldFish("니모", Pet::FISH, 2) };
	for (int i = 0; i < sizeof(petAry) / sizeof(petAry[0]); i++) {

		// TODO - 아래와 같이 출력되게 코딩해보세요~
		    /* 고양이 먹이를 먹습니다
		       땅 위에서 사뿐사뿐 걷습니다
			   야옹이(포유류) 2살

			   개 먹이를 먹습니다
			   땅 위에서 네발로 걷습니다
			   멍멍이(포유류) 5살

			   오리 먹이를 먹습니다
			   땅 위에서 두발로 걷습니다
			   물 속에서 두발로 헤엄칩니다
			   도널드(조류) 1살

			   금붕어 먹이를 먹습니다
			   물 속에서 헤엄칩니다
			   니모(어류) 2살
			 */

	}
	for (int i = 0; i < sizeof(petAry) / sizeof(petAry[0]); i++) {
		delete petAry[i];
	}
	return 0;
}