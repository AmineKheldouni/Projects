<<<<<<< HEAD

=======
#ifndef proie_H
#define proie_H

#include <SFML/Graphics.hpp>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <vector>
using namespace std;
#include "math.h"
#include <cmath>

sf::Vector2f dimension(30.f,30.f);
const int w = 1020;
const int h = 600;
sf::RectangleShape shape(dimension);

class proie
{
	float x,y;
	sf::Sprite s;
	int hp;
public:
	proie();
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

#endif // proie_H
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
