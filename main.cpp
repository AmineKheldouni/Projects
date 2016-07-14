#include "proie.h"
#include "proie.cpp"
#include "predateur.cpp"
#include "predateur.h"

std::vector<proie> actualise_lproies(std::vector<proie> v){
    int n = v.size();
    for (int i=0;i<n;i++){
        if (v[i].getHp() ==0)
            v.erase(v.begin() + i);
    }
    return v;
}

int main ()
{
	srand (time(NULL));
    sf :: RenderWindow window (sf :: VideoMode ( w, h ), "SFML works!" );

    std::vector<proie> liste_proies;
    std::vector<predateur> liste_predateurs;

    proie P(w/2,h/2,1);
    liste_proies.push_back(P);
    predateur R(100,100,1);
    while (window.isOpen ())
    {
        sf :: Event event;
        while (window.pollEvent (event))
        {
            if (event.type == sf :: Event :: Closed)
                window.close ();
        }
        window.clear ();
        P.affichage();
        R.affichage();
        window.draw (shape);
        window.draw (shape2);
        window.display ();
        //sf::sleep(sf::milliseconds(10));
        P.deplacement();
        R.deplacement(liste_proies);
        R.attaque(liste_proies);
        liste_proies = actualise_lproies(liste_proies);
    }

    return  0 ;
}
