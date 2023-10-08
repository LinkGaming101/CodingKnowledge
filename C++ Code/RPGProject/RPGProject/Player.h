#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

enum Race { HUMAN, ELF, DWARF, ORC, TROLL };

class Player {
	public:
		Player(string name, Race race, 
			int hp, int mp);
		
		//getters
		string getName() const noexcept;
		Race getRace() const noexcept;
		string whatRace() const noexcept;
		int getHitPoints() const noexcept;
		int getMagicPoints() const noexcept;
		
		//setters
		void setName(string name);
		void setRace(Race race);
		void setHitPoints(int hp);
		void setMagicPoints(int mp);
		
		virtual string attack() const = 0;

	private:
		string name;
		Race race;
		int hp;
		int mp;
};
#endif // !PLAYER_H
