#ifndef POKEMON_H
#define POKEMON_H

class Pokemon {
	public:
		Pokemon();
		int getHealth() const;
		void setHealth(int newHealth);
		~Pokemon();
		int *pint;
	private:
		int health = 0;
};

#endif
