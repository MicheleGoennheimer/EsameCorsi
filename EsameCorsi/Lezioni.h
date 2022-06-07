//
// Created by mi on 04/06/2022.
//
using namespace std;
#ifndef ESAMECORSI_LEZIONI_H
#define ESAMECORSI_LEZIONI_H
#include <string>


// Struttura che definisce l'aula
struct aula {
    string id;
    string numPosti;
};


// Struttura che definisce la singola lezione
struct lezione{
    int giorno;
    int inizio;
    aula stanza;
};

class LezioniCorso {

protected:
    int numGiorni;
    lezione *lezCorso;

public:
    LezioniCorso();
    LezioniCorso(int giorni);
    void InizializzaLezioni(string file);
    void StampaLezioni();

};

#endif //ESAMECORSI_LEZIONI_H
