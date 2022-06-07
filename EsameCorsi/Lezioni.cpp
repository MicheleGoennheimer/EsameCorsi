//
// Created by mi on 04/06/2022.
//
using namespace std;
#include "Lezioni.h"
#include <iostream>
#include <string>
#include <fstream>

LezioniCorso::LezioniCorso() {}

LezioniCorso::LezioniCorso(int giorni) {

    this->numGiorni = giorni;
    lezCorso = new lezione[giorni];

}

void LezioniCorso::InizializzaLezioni(string file) {

    fstream instream;

    instream.open(file, ios::in);

    for(int i = 0; i < numGiorni; i++){
        instream >> lezCorso[i].giorno;
        instream >> lezCorso[i].inizio;
        instream >> lezCorso[i].stanza.id;
        instream >> lezCorso[i].stanza.numPosti;
    }

    instream.close();

}

void LezioniCorso::StampaLezioni() {

    for(int i = 0; i < numGiorni; i++){

        cout << "Giorno numero: " << lezCorso[i].giorno;
        cout << ", ora: " << lezCorso[i].inizio << ":00";
        cout << ", aula: " << lezCorso[i].stanza.id << ", posti: ";
        cout << lezCorso[i].stanza.numPosti << endl;
    }


}