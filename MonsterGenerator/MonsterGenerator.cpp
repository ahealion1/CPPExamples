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
	Monster() : m_type(MonsterType::ZOMBIE), m_name("ZOMBIE"), m_sound("boo!"), m_HP(100)
	{
		
	}
	
	Monster(MonsterType type, string name, string sound, int HP)
		: m_type(type), m_name(name), m_sound(sound), m_HP(HP)
	{
		
	}
	
	string getTypeString() const
	{
		switch(m_type)
		{
		case DRAGON : return "Dragon";
		case GOBLIN : return "Goblin";
		case OGRE : return "Ogre";
		case ORC : return "Orc";
		case SKELETON : return "Skeleton";
		case TROLL : return "Troll";
		case VAMPIRE : return "Vampire";
		case ZOMBIE : return "Zombie";
		}
		
		return "?";
	}
	
	void print() const
	{
		cout<<m_name<<" the "<<getTypeString()<<" has "<<m_HP<<" HP and goes "<<m_sound;
	}
	
	void richPrint() const
	{
		cout<<"\n\n**************************\n"
		<<"Monster Type: \t"<<getTypeString()<<"\n"
		<<"Name: \t\t"<<m_name<<"\n"
		<<"Sound: \t\t"<<m_sound<<"\n"
		<<"HP \t\t"<<m_HP<<"\n"
		<<"**************************\n";
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
	
	static Monster generateRandomMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0,Monster::MAX_MONSTER_TYPES-1));
		int HP = getRandomNumber(1,100);
		static const string s_names[6]{"Frankenstein", "Glorp", "Boo", "Sasquatch", "Striga", "Toby"};
		string name = s_names[getRandomNumber(0,5)];
		static const string s_sounds[6]{"boo!", "AAARRRGGHHH!!!", "*wail*", "*hiss*", "*growl*", "*rattle*"};
		string sound = s_sounds[getRandomNumber(0,5)];
				
		return Monster{type, name, sound, HP};
	}
	
	static Monster generateCustomMonster()
	{
		Monster::MonsterType type;		
		cout<<"Choose a monster type from the list:\n"
		"(D)RAGON \n(G)OBLIN \n(O)GRE \nO(R)C \n(S)KELETON \n(T)ROLL \n(V)AMPIRE \n(Z)OMBIE\n";
		char choice{'Z'};
		cin>>choice;
		switch(choice)
		{
			case 'D' : case 'd' : type = Monster::DRAGON; 	cout<<"Dragon\n"; break;
			case 'G' : case 'g' : type = Monster::GOBLIN; 	cout<<"Goblin\n"; break;
			case 'O' : case 'o' : type = Monster::OGRE; 	cout<<"Ogre\n"; break;
			case 'R' : case 'r' : type = Monster::ORC; 		cout<<"Orc\n"; break;
			case 'S' : case 's' : type = Monster::SKELETON; cout<<"Skeleton\n"; break;
			case 'T' : case 't' : type = Monster::TROLL; 	cout<<"Troll\n"; break;
			case 'V' : case 'v' : type = Monster::VAMPIRE; 	cout<<"Vampire\n"; break;
			case 'Z' : case 'z' : type = Monster::ZOMBIE; 	cout<<"Zombie\n"; break;	
			default : {cout<<"Error - incorrect choice\n"; assert(0);}
		}
		cout<<"\nNow type in your monster's name:\n";
		string name{"Jeff"};
		cin>>name;
		cout<<"\nNow type in the sound that your monster makes (e.g. 'AAARRGGHHH' or *rattle*)\n";
		string sound{"'boo!'"};
		cin>>sound;
		cout<<"\nFinally, we'll give your monster 100HP to begin.\nPress enter to see your monster...";
		getchar();
		int HP = 100;
		Monster m(type,name,sound,HP);
		m.richPrint();
	}
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value
	
	cout<<"Would you like to generate (y)our own monster or a (r)andom monster?";
	char choice{'r'};
	cin>>choice;
	Monster monster1;
	
	assert(choice=='r' || choice=='y');
	if(choice == 'r')
	{
		monster1 = MonsterGenerator::generateRandomMonster();
	}
	else if(choice == 'y')
	{
		monster1 = MonsterGenerator::generateCustomMonster();
	}
	else
	{
		cout<<"Error - incorrect choice...";
		return 0;
	}
	monster1.print();
    
    return 0;
}



