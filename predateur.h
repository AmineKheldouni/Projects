<<<<<<< HEAD

#ifndef PREDATEUR_H
#define PREDATEUR_H

#include "utils.h"





class proie
{
	float x,y;
	sf::Sprite s;
	int hp;
public:
	proie(float a, float b, int h);
	int getHp() const;
	void setHP(int h);
	bool estmorte();
	void deplacement();
	void affichage();
	float getX() const;
	float getY() const;
	sf::Sprite getImage() const;
	void setX(float a);
	void setY(float b);
	~proie();
};

=======
#ifndef PREDATEUR_H
#define PREDATEUR_H

#include "proie.h"
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea

sf :: RectangleShape shape2;
class predateur
{
	float x,y;
	sf::Sprite s;
	int hp;
	int flaire;
public:
<<<<<<< HEAD
=======
	predateur();
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
	predateur(float a, float b, int h);
	int getHp() const;
	void setHP(int h);
	bool estmort() const;
<<<<<<< HEAD
	void attaque(std::vector<proie>& v);
	void deplacement(std::vector<proie>& v);
=======
	void attaque(std::vector<proie> v);
	void deplacement(std::vector<proie> v);
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
	void affichage();
	float getX() const;
	float getY() const;
	sf::Sprite getImage() const;
	void setX(float a);
	void setY(float b);
	~predateur();

};

#endif // PREDATEUR_H
