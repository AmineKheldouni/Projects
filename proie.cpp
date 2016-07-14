#include "proie.h"
#include "predateur.h"

proie::proie(){

}

proie::proie(float a, float b, int h){
	x = a;
	y = b;
	hp = h;
}

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
		if (x+2*dimension.x<=w)
		{
			x += dimension.x;
		}
		else
		{
			deplacement();
		}
	}
	if (d==1){
		if (y+2*dimension.y<=h)
		{
			y += dimension.y;
		}
		else{
			deplacement();
		}
	}
	if (d==2){
		if (x-dimension.x>=0)
		{
			x -= dimension.x;
		}
		else{
			deplacement();
		}
	}
	if (d==3){
		if (y-dimension.y>=0)
		{
			y -= dimension.y;
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

