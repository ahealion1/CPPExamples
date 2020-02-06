#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <cstdlib>
using namespace std;

class Monster
{
public:
	enum MonsterType
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:
    MonsterType m_type;
    string m_name;
    string m_sound;
    int m_HP;

public:
	Monster(MonsterType type, string name, string sound, int HP)
		: m_type(type), m_name(name), m_sound(sound), m_HP(HP)
	{
		
	}
	
	string getTypeString() const
	{
		switch(m_type)
		{
		case DRAGON : return "dragon";
		case GOBLIN : return "goblin";
		case OGRE : return "ogre";
		case ORC : return "orc";
		case SKELETON : return "skeleton";
		case TROLL : return "troll";
		case VAMPIRE : return "vampire";
		case ZOMBIE : return "zombie";
		}
		
		return "?";
	}
	
	void print() const
	{
		cout<<m_name<<" the "<<getTypeString()<<" has "<<m_HP<<" HP and goes "<<m_sound;
	}
	
};

class MonsterGenerator
{
private:
	
	
public:
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction = 1.0/(static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
	
	static Monster generateMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0,Monster::MAX_MONSTER_TYPES-1));
		int HP = getRandomNumber(1,100);
		static const string s_names[6]{"Frankenstein", "Glorp", "Boo", "Sasquatch", "Striga", "Toby"};
		string name = s_names[getRandomNumber(0,5)];
		static const string s_sounds[6]{"boo!", "AAARRRGGHHH!!!", "*wail*", "*hiss*", "*growl*", "*rattle*"};
		string sound = s_sounds[getRandomNumber(0,5)];
				
		return Monster{type, name, sound, HP};
	}
	
};

 
int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value
 
	Monster m = MonsterGenerator::generateMonster();
	m.print();
    
    return 0;
}



