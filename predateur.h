#ifndef PREDATEUR_H
#define PREDATEUR_H

#include "proie.h"

sf :: RectangleShape shape2;
class predateur
{
	float x,y;
	sf::Sprite s;
	int hp;
	int flaire;
public:
	predateur();
	predateur(float a, float b, int h);
	int getHp() const;
	void setHP(int h);
	bool estmort() const;
	void attaque(std::vector<proie> v);
	void deplacement(std::vector<proie> v);
	void affichage();
	float getX() const;
	float getY() const;
	sf::Sprite getImage() const;
	void setX(float a);
	void setY(float b);
	~predateur();

};

#endif // PREDATEUR_H
