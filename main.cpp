<<<<<<< HEAD
#include "utils.h"

std::vector<proie> initialise_lproies(int nbre){
    std::vector<proie> v;
    for(int i=0;i<nbre;i++){
        v.push_back(proie((rand()%20)*dx,rand()%20*dy,1));
    }
    return v;
}

std::vector<predateur> initialise_lpred(int nbre){
    std::vector<predateur> v;
    for(int i=0;i<nbre;i++){
        v.push_back(predateur((rand()%20)*dx,rand()%20*dy,1));
    }
    return v;
}
=======
#include "proie.h"
#include "proie.cpp"
#include "predateur.cpp"
#include "predateur.h"
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea

std::vector<proie> actualise_lproies(std::vector<proie> v){
    int n = v.size();
    for (int i=0;i<n;i++){
        if (v[i].getHp() ==0)
            v.erase(v.begin() + i);
    }
    return v;
}

<<<<<<< HEAD
void draw_grass(sf::RenderWindow* p_window, sf::Texture t){
    sf::Sprite s(t);
    s.setScale(w,h);
            p_window->draw(s);
}

int main ()
{
    srand (time(NULL));
    sf :: RenderWindow window (sf :: VideoMode ( w, h ), "SFML works!" );
    sf::RenderWindow *pointeur_window = &window;

    std::vector<proie> liste_proies;
    std::vector<predateur> liste_predateurs;
    liste_proies = initialise_lproies(15);
    liste_predateurs = initialise_lpred(10);
    for (int i=0;i<liste_predateurs.size();i++){
        cases[liste_predateurs[i].getX()][liste_predateurs[i].getY()]=true;
    }
    for (int i=0;i<liste_proies.size();i++){
        cases[liste_proies[i].getX()][liste_proies[i].getY()]=true;
    }
    while (window.isOpen ())
    {
        sf :: Event event;
        while (window.pollEvent (event)  )
=======
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
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
        {
            if (event.type == sf :: Event :: Closed)
                window.close ();
        }
<<<<<<< HEAD

        window.clear ();
        draw_grass(pointeur_window,texture_herbe);
        for (int i=0;i<liste_proies.size();i++)
            liste_proies[i].affichage(pointeur_window);
        for (int i=0;i<liste_predateurs.size();i++)
            liste_predateurs[i].affichage(pointeur_window);
        cases_draw(pointeur_window);
        window.display ();
        for (int i=0;i<liste_predateurs.size();i++){
            liste_predateurs[i].deplacement(liste_proies);
            liste_predateurs[i].attaque(liste_proies);}
        for (int i=0;i<liste_proies.size();i++)
            liste_proies[i].deplacement(liste_proies);

        window.clear ();
        sf::sleep(sf::milliseconds(500));
        draw_grass(pointeur_window,texture_herbe);
        for (int i=0;i<liste_proies.size();i++)
            liste_proies[i].affichage(pointeur_window);
        for (int i=0;i<liste_predateurs.size();i++)
            liste_predateurs[i].affichage(pointeur_window);
        cases_draw(pointeur_window);
        window.display ();
        cout << "Nombre de moutons :" << liste_proies.size() << endl;
        liste_proies = actualise_lproies(liste_proies);

=======
        window.clear ();
        P.affichage();
        R.affichage();
        window.draw (shape);
        window.draw (shape2);
        window.display ();
        sf::sleep(sf::milliseconds(50));
        P.deplacement();
        R.deplacement(liste_proies);
        R.attaque(liste_proies);
        liste_proies = actualise_lproies(liste_proies);
>>>>>>> 5610c7c81a08a1684d34ba84f1c2e4c5bcf9d9ea
    }

    return  0 ;
}
