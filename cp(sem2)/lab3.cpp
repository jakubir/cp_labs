#include <iostream>

class Monster
{
    public:
        Monster()
        {
            std::cout << "New Monster" << std::endl;
        }

        ~Monster()
        {
            std::cout << "Monster destroyed" << std::endl;
        }

        virtual void attack() 
        { 
            std::cout << "Default Monster attack" << std::endl; 
        }
};

class Dragon: public Monster
{
    public:
        Dragon()
        {
            std::cout << "New Dragon" << std::endl;
        }

        ~Dragon()
        {
            std::cout << "Dragon destroyed" << std::endl;
        }

        void attack()
        {
            std::cout << "Dragon attack" << std::endl; 
        }
};

class BlueDragon: public Dragon
{
    public:
        BlueDragon()
        {
            std::cout << "New BLUE Dragon" << std::endl;
        }

        ~BlueDragon()
        {
            std::cout << "BLUE Dragon destroyed" << std::endl;
        }

        void attack()
        {
            std::cout << "BLUE Dragon attack" << std::endl; 
        }
};

int main()
{
    BlueDragon bd;

    Monster* monsters[] = {
        new BlueDragon(),
        new Dragon(),
        new Monster()
    };

    for (auto m : monsters) {
        m->attack();
    }

    for (auto m : monsters) {
        delete m;
    }

    return 0;
}