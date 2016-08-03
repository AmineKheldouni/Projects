#ifndef UTILS_H
#define UTILS_H
#include <SFML/Graphics.hpp>
#include <time.h>       /* time */
#include <iostream>
#include <vector>
using namespace std;
#include "math.h"
#include <cmath>

sf::Vector2f dimension(30.f,30.f);
int dx=30;
int dy=30;
const int w=600;
const int h=600;
const int w_case = 20;
const int h_case = 20;
bool cases[w_case][h_case];
sf::Texture texture_proie;
sf::Texture texture_pred;


sf::Texture texture_herbe;
bool b_texture = !texture_herbe.loadFromFile("herbe.jpg");
// CASES :
void cases_draw(sf::RenderWindow *p_window){

    double hw = dx;
    double hh = dy;
    sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(10, 10)),
    sf::Vertex(sf::Vector2f(150, 150))
};
    for (int i=0;i<w;i++){
        sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(0+hw*i,0)),
    sf::Vertex(sf::Vector2f(0+hw*i,h))
};
p_window->draw(line, 2, sf::Lines);
    }

for (int j=0;j<h;j++){
        sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(0,0+hh*j)),
    sf::Vertex(sf::Vector2f(w,0+hh*j))
};
p_window->draw(line, 2, sf::Lines);
        }
}


class proie
{
	int x,y;
	sf::Sprite s;
	int hp;
public:
	proie(float a, float b, int h);
	int getHp() const;
	void setHP(int h);
	bool estmorte();
	void deplacement(std::vector<proie> moutons);
	void affichage(sf::RenderWindow* p_window);
	int getX() const;
	int getY() const;
	sf::Sprite getImage() const;
	void setX(float a);
	void setY(float b);
	~proie();
};


class predateur
{
	int x,y;
	sf::Sprite s;
	int hp;
	int flaire;
public:
	predateur(float a, float b, int h);
	int getHp() const;
	void setHP(int h);
	bool estmort() const;
	void attaque(std::vector<proie>& v);
	void deplacement(std::vector<proie>& v);
	void affichage(sf::RenderWindow* p_window);
	int getX() const;
	int getY() const;
	sf::Sprite getImage() const;
	void setX(float a);
	void setY(float b);
	int proie_proche(std::vector<proie> v);
	~predateur();

};


predateur::predateur(float a, float b, int h){
	x = a;
	y = b;
	hp = h;
    while(!texture_pred.loadFromFile("predateur.png")){}
    s.setTexture(texture_pred);
    s.setPosition(x,y);
}

int predateur::getHp() const{
	return hp;
}

int predateur::getX() const{
	return x;
}

int predateur::getY() const{
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

int maximum(int a, int b){
    if (a<b)
        return a;
    return b;
}
int predateur::proie_proche(std::vector<proie> v){
    int indice_proie=0;
    if (v.size()!=0){
        double d = maximum(abs(x-v[0].getX()),abs(y-v[0].getY()));
        double d2;
        for (int i=1;i<v.size();i++){
            d2 = maximum(abs(x-v[i].getX()),abs(y-v[i].getY()));
            if (d2<=d){
                d = d2;
                indice_proie=i;
            }
        }
    }
    return indice_proie;
}
void min_dist(int& c, int a, int b, int aa, int bb){
	double dmin = maximum(abs(a-aa),abs(b-bb));
	double d = maximum(abs(a+dx-aa),abs(b-bb));
    if (a+2*dx<=w && d<=dmin){
        c = 0; //Droite
    }

	d = maximum(abs(a-aa),abs(b+dy-bb));
    if (b+2*dy<=h && d<=dmin){
        c = 1; //Bas
    }

    d = maximum(abs(a-dx-aa),abs(b-bb));
    if (a-dx>=0 && d<=dmin){
        c = 2; //Gauche
    }

    d = maximum(abs(a-aa),abs(b-dy-bb));
    if (b-dy>=0 && d<=dmin){
        c = 3; //Gauche
    }
}

void predateur::deplacement(std::vector<proie>& v){
	int c;
	if (v.empty()){
		c = rand() % 4;
	}
	else
	{
		proie P = v[proie_proche(v)];
		if (x+2*dx<=w && y+2*dy<=h){
			min_dist(c,x,y,P.getX(),P.getY());
		}
	}
	if (c==0 && x+2*dx<=w && !cases[x/dx+1][y/dy]){
		cases[x/dx][y/dy]=false;
		x += dx;
		cases[x/dx][y/dy]=true;
		s.setPosition(x,y);}
	if (c==1 && y+2*dy<=h && !cases[x/dx][y/dy+1]){
		cases[x/dx][y/dy]=false;
		y += dy;
		cases[x/dx][y/dy]=true;
		s.setPosition(x,y);}
	if (c==2 && x-dx>=0 && !cases[x/dx-1][y/dy]){
		cases[x/dx][y/dy]=false;
		x -= dx;
		cases[x/dx][y/dy]=true;
		s.setPosition(x,y);}
	if (c==3 && y-dy>=0 && !cases[x/dx][y/dy-1]){
		cases[x/dx][y/dy]=false;
		y -= dy;
		cases[x/dx][y/dy]=true;
		s.setPosition(x,y);
		}

}


void predateur::affichage(sf::RenderWindow* p_window){
	p_window->draw(s);
}

void predateur::attaque(std::vector<proie>& v){
	int n = v.size();
	if (n!=0){
	for(int i=0;i<n;i++){
		if (abs(v[i].getX()-x)<=dx && abs(v[i].getY()-y)<=dy){
			v[i].setHP(0);
			v[i].estmorte();
			v.erase(v.begin()+i);
		}
	}
	}
}

predateur::~predateur(){}

}

proie::proie(float a, float b, int h){
	x = a;
	y = b;
	hp = h;
	while(!texture_proie.loadFromFile("proie.png")){}
    s.setTexture(texture_proie);
    s.setPosition(x,y);
}

int proie::getHp() const{
	return hp;
}

int proie::getX() const{
	return x;
}

int proie::getY() const{
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
        s.setTexture(texture_herbe);
		return true;
	}
	return false;
	}

void proie::deplacement(std::vector<proie> moutons){
    if (hp!=0){
	int d = rand() % 4;
	if (d==0){
		if (x+2*dx<=w && !cases[x/dx+1][y/dy])
		{
            cases[x/dx][y/dy]=false;
			x += dx;
            cases[x/dx][y/dy]=true;
            s.setPosition(x,y);
		}
	}

	if (d==1){
		if (y+2*dy<=h && !cases[x/dx][y/dy+1])
		{
            cases[x/dx][y/dy]=false;
			y += dy;
            cases[x/dx][y/dy]=true;
            s.setPosition(x,y);
		}
	}
	if (d==2){
		if (x-dx>=0 && !cases[x/dx-1][y/dy])
		{
            cases[x/dx][y/dy]=false;
			x -= dx;
            cases[x/dx][y/dy]=true;
            s.setPosition(x,y);
		}
	}
	if (d==3){
		if (y-dy>=0 && !cases[x/dx][y/dy-1])
		{
            cases[x/dx][y/dy]=false;
			y -= dy;
            cases[x/dx][y/dy]=true;
            s.setPosition(x,y);
		}
	}
}
}


void proie::affichage(sf::RenderWindow* p_window){
    p_window->draw(s);

}

proie::~proie(){

}


/////////////////////////////////////////////////



#endif // UTILS_H
