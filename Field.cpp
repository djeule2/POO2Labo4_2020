//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Field.h"
#include "Buffy.h"
#include "Humain.h"
#include "Vampire.h"

Field::Field(){
    int largeurGrille ;
    int hauteurGrille;
    int nbrVambire;
    int nbrHumain;
    readControl("Largeur Grille", Grille::BORNE_INF, Grille::BORNE_SUP, largeurGrille);
    readControl("HauteurGrille", Grille::BORNE_INF, Grille::BORNE_SUP, hauteurGrille);
    readControl("Nombre de humain", 0,largeurGrille*hauteurGrille-1, nbrHumain);
    readControl("Nombre de Vampire", 0, largeurGrille*hauteurGrille-nbrHumain-1, nbrVambire);
    grid = new Grille(largeurGrille, hauteurGrille);
    createHumanoid(nbrHumain, nbrVambire);
    loadListHumanoidGrid();
    grid->displayGrille();

}

void Field::createHumanoid(int nbrVampire, int nbrHuman){
    int xPosition;
    int yPosition;
    srand((unsigned int)time_t(0));
    //creation du Buffy
    xPosition=rand()%grid->getHauteurGrille();
    yPosition=rand()%grid->getLargeurGrille();
    _humanoids.push_back(new Buffy(xPosition, yPosition));

    for(int i=0; i< nbrHuman; i++){
        //creation de Humain
        xPosition=rand()%grid->getHauteurGrille();
        yPosition=rand()%grid->getLargeurGrille();
        _humanoids.push_back(new Humain(xPosition, yPosition));
    }

    for(int i=0; i< nbrVampire; i++){
        //creation Vampire
        xPosition=rand()%grid->getHauteurGrille();
        yPosition=rand()%grid->getLargeurGrille();
        _humanoids.push_back(new Vampire(xPosition, yPosition));
    }

}

void Field::loadListHumanoidGrid(){
    for (_List_iterator<Humanoid *> it = _humanoids.begin(); it != _humanoids.end(); ++it ){
        grid->loadHumanoidGrid(**it);
    }
}

int Field::nexTurn(){
    // Déterminer les prochaines actions
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++)
        (*it)->setAction(*this);
    // Executer les actions
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++)
        (*it)->executeAction(*this);
    // Enlever les humanoides tués
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); )
        if (!(*it)->isAlive()) {
            it = _humanoids.erase(it); // suppression de l’élément dans la liste
            delete *it; // destruction de l’humanoide référencé
        }
        else
            ++it;
    return turn++;
}

void Field::addHumanoid(Humanoid* humanoid){
    _humanoids.push_back(humanoid);
}

void Field::handleCommand(const string &cmd){
    switch (cmd.at(0)){
        case QUIT:
            break;
        case NEXT:
            break;
        case STATTISTIQUE:
            break;
        default:
            cout<<"commande invalide"<<endl;
            break;
    }

}


void Field::showMenu(){
    cout<<QUIT<<">quit ";
    cout<<STATTISTIQUE<<">tatisties";
    cout<<NEXT<< ">ext :";
}

void Field::readControl (const string msg, const int borneInf, const int borneSup, int &val){
    cout<< "Entrez " << msg <<" comprise entre ["<< borneInf <<
    "-"<<borneSup<<"]: ";
    while (!(cin>>val)|| val<borneInf||val>borneSup){
        if(cin.fail()){
            cout<<"saisie incorrecte : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            cout<<"le chiffre pas dans l'intervalle ["<<borneInf<<
            " - "<<borneSup<<"] : ";
        }
    }
}

void Field::startGame(){

}
