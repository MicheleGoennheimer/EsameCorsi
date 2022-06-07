//
// Created by mi on 04/06/2022.
//

using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "Strutture.h"


Corso::Corso() {}

Corso::Corso(int giorni, int alunni) : LezioniCorso(giorni){
    anno = 1;
    this->numStudenti = alunni;
    studenti = new persona[alunni];
}

void Corso::InizializzaStudenti(string file){

    fstream instream;

    instream.open(file, ios::in);

    for(int i = 0; i < numStudenti; i++){
        instream >> studenti[i].nome;
        instream >> studenti[i].cognome;
        instream >> studenti[i].matricola;
    }

    instream.close();

}

void Corso::InizializzaProfessore(){

    cout << "Inserire il nome, cognome e matricola del professore :";
    cin >> prof.nome >> prof.cognome >> prof.matricola;

}


void Corso::AggiornaAnno(int year){

    if(year > 0 && year <= 3)
        anno = year;
    else
        cout << "WARNING: anno non valido";

}

void Corso::StampaCorso(){

    cout << endl << "-- Studenti --" << endl;

    for(int i = 0; i < numStudenti; i++){
        cout << "Nome: " << studenti[i].nome << ", cognome: "  << studenti[i].cognome;
        cout << ", matricola: " << studenti[i].matricola << endl;
    }

    cout << "-- Professore --" << endl;

    cout << "Nome: " << prof.nome << ", cognome: "  << prof.cognome;
    cout << ", matricola: " << prof.matricola << endl;

    cout  << "-- Anno --" << endl;

    cout << anno << endl;

    cout << "-- Lezioni --" << endl;
    StampaLezioni();

    cout << endl;

}

bool Corso::CorsiInsegnate(string nome, string cognome) {

    if(nome == prof.nome && cognome == prof.cognome)
        return true;
    else
        return false;

}

bool Corso::CorsiAula(string room){

    for(int i = 0; i < numGiorni; i++){
        if(lezCorso[i].stanza.id == room)
            return true;
    }

    return false;
}

persona Corso::PassaProf() const {
    return prof;
}
