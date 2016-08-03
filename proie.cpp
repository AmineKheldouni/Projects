<<<<<<< HEAD
#include "predateur.h"


=======
#include "proie.h"
#include "predateur.h"

proie::proie(){

}
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea

proie::proie(float a, float b, int h){
	x = a;
	y = b;
	hp = h;
}
<<<<<<< HEAD

=======
 
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
int proie::getHp() const{
	return hp;
}

float proie::getX() const{
	return x;
}

float proie::getY() const{
 return y;
}

sf::Sprite proie::getImage() const{
	return s;
}

void proie::setX(float a){
	x = a;
}

void proie::setY(float b){
	y = b;
}

void proie::setHP(int h){
	hp = h;
}

bool proie::estmorte(){
	if (hp==0){
    	shape.setFillColor (sf :: Color :: Black);
		return true;
	}
	return false;
	}

void proie::deplacement(){
	int d = rand() % 4;

	if (d==0){
<<<<<<< HEAD
		if (x+2*dx<=w)
		{
			x += dx;
=======
		if (x+2*dimension.x<=w)
		{
			x += dimension.x;
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
		}
		else
		{
			deplacement();
		}
	}
	if (d==1){
<<<<<<< HEAD
		if (y+2*dy<=h)
		{
			y += dy;
=======
		if (y+2*dimension.y<=h)
		{
			y += dimension.y;
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
		}
		else{
			deplacement();
		}
	}
	if (d==2){
<<<<<<< HEAD
		if (x-dx>=0)
		{
			x -= dx;
=======
		if (x-dimension.x>=0)
		{
			x -= dimension.x;
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
		}
		else{
			deplacement();
		}
	}
	if (d==3){
<<<<<<< HEAD
		if (y-dy>=0)
		{
			y -= dy;
=======
		if (y-dimension.y>=0)
		{
			y -= dimension.y;
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
		}
		else{
			deplacement();
		}
	}
}


void proie::affichage(){
	shape.setSize(dimension);
    shape.setFillColor (sf :: Color :: Blue);
    shape.setPosition(x,y);
}

proie::~proie(){

}
<<<<<<< HEAD
=======

>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
