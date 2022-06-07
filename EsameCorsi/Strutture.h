//
// Created by mi on 04/06/2022.
//

#ifndef ESAMECORSI_STRUTTURE_H
#define ESAMECORSI_STRUTTURE_H
#include <string>
#include "Lezioni.h"

// Struttura che definisce lo studente
struct persona {
    string nome;
    string cognome;
    int matricola;
};


class Corso : public LezioniCorso {

protected:

    int numStudenti;
    persona *studenti;
    persona prof;
    int anno;

public:
    Corso();
    Corso(int giorni, int alunni);
    void InizializzaStudenti(string file);
    void InizializzaProfessore();
    persona PassaProf() const;
    void AggiornaAnno(int year);
    void StampaCorso();
    bool CorsiInsegnate(string nome, string cognome);
    bool CorsiAula(string room);
};





#endif //ESAMECORSI_STRUTTURE_H
