#include "predateur.h"


predateur::predateur(){}

predateur::predateur(float a, float b, int h){
	x = a;
	y = b;
	hp = h;
}

int predateur::getHp() const{
	return hp;
}

float predateur::getX() const{
	return x;
}

float predateur::getY() const{
 return y;
}

sf::Sprite predateur::getImage() const{
	return s;
}

void predateur::setX(float a){
	x = a;
}

void predateur::setY(float b){
	y = b;
}

void predateur::setHP(int h){
	hp = h;
}

bool predateur::estmort() const{
	if (hp==0)
		return true;
	return false;
	}

void min_dist(int& c, int a, int b, int aa, int bb){
	double dmin;
	double d2;
	if (a+2*dimension.x<=w){
		dmin = sqrt((aa-a-dimension.x)*(aa-a-dimension.x)+(bb-b)*(bb-b));
		c = 0;
	}
	d2 = sqrt((aa-a+dimension.x)*(aa-a+dimension.x)+(bb-b)*(bb-b));
	if (a-dimension.x>=0 && d2<=dmin){
		dmin = d2;
		c = 2;
	}
	else{
		dmin = d2;
	}
	d2 = sqrt((aa-a)*(aa-a)+(bb-b-dimension.y)*(bb-b-dimension.y));
	if (b+2*dimension.y<=h && d2<=dmin){
		dmin = d2;
		c = 1;
	}
	d2 = sqrt((aa-a)*(aa-a)+(bb-b+dimension.y)*(bb-b+dimension.y));
	if (b-dimension.y>=0 && d2<=dmin){
		dmin = d2;
		c = 3;
	}
}

void predateur::deplacement(std::vector<proie> v){
	int c;
	if (v.empty()){
		c = rand() % 4;
	}
	else
	{
		proie P = v[0];
		if (x+2*dimension.x<=w){
			min_dist(c,x,y,P.getX(),P.getY());
		}
	}
	if (c==0)
		x += dimension.x;
	if (c==1)
		y += dimension.y;
	if (c==2)
		x -= dimension.x;
	if (c==3)
		y -= dimension.y;
	
}


void predateur::affichage(){
	shape2.setSize(dimension);
	shape2.setFillColor (sf :: Color :: Red);
	shape2.setPosition(x,y);
}

void predateur::attaque(std::vector<proie> v){
	int n = v.size();
	for(int i=0;i<n;i++){
		if (fabs(v[i].getX()-x)<=30 || fabs(v[i].getY()-y)<=30){
			v[i].setHP(0);
		}
	}
}

predateur::~predateur(){

}