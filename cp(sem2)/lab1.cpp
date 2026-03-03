#include <iostream>

class Monster
{
	public:
		int health_points;
		int damage;

		Monster(int hp, int dmg)
		{
			health_points = hp;
			damage = dmg;
		}

		void attack(Monster *m)
		{
			m->health_points -= damage;
		}
};

class Game
{
	public:
		Monster* A, *B;

		Game(Monster *A, Monster *B): A(A), B(B) {}

		void start_battle()
		{
			while (1)
			{
				A->attack(B);
				if (B->health_points <= 0)
				{
					std::cout << "Monster A won\n";
					break;
				}

				B->attack(A);
				if (A->health_points <= 0)
				{
					std::cout << "Monster B won\n";
					break;
				}
			}
		}
};

int main()
{
	Monster monsterA(100, 10);
	Monster monsterB(100, 5);

	Game game(&monsterA, &monsterB);

	game.start_battle();
	std::cout << monsterA.health_points << std::endl;

	return 0;
}

//struct Monster {
//	int health_points, damage;
//	std::string name;
//};
//
//void fight(Monster, Monster);
//
//int main()
//{
//	Monster monsterA = { 100, 15, "Arek" };
//	Monster monsterB = { 200, 5, "Ben" };
//
//	fight(monsterA, monsterB);
//
//	return 0;
//}
//
//void fight(Monster A, Monster B)
//{
//	while (1)
//	{
//		B.health_points -= A.damage;
//		if (B.health_points <= 0)
//		{
//			std::cout << A.name << " won\n";
//			break;
//		}
//
//		A.health_points -= B.damage;
//		if (A.health_points <= 0)
//		{
//			std::cout << B.name << " won\n";
//			break;
//		}
//	}
//}