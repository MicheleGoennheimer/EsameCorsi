using namespace std;
#include <iostream>
#include <string>
#include "Strutture.h"
#include "Lezioni.h"


int main() {

    int corsi;
    int anno;
    string file = "LezioniCorso1.txt";
    int giorni = 3;
    int alunni = 3;

    cout << "Quanti corsi ha questo corso di laurea: ";
    cin >> corsi;

    Corso * CLaurea = new Corso[corsi];

    for(int i = 0; i < corsi; i++){

        CLaurea[i] = Corso(giorni, alunni);

        cout << "Inserisce il nome del file  da cui prendere gli studenti: ";
        cin >> file;

        CLaurea[i].InizializzaStudenti(file);

        CLaurea[i].InizializzaProfessore();

        cout << "Inserisce il nome del file  da cui prendere gli orari: ";
        cin >> file;

        CLaurea[i].InizializzaLezioni(file);

        cout << "Inserire l'anno del seguente corso:";
        cin >> anno;
        CLaurea[i].AggiornaAnno(anno);


    }

    for(int i = 0; i < corsi; i++)
        CLaurea[i].StampaCorso();

    string nome, cognome;

    cout << "inserire il nome e il cosnome del professore che si cerca: ";
    cin >> nome >> cognome;

    for(int i = 0; i < corsi; i++){
        if(CLaurea[i].CorsiInsegnate(nome, cognome))
            cout << "Il seguente prof tiene il corso numero: " << i + 1 << endl;
    }

    string idaula;

    cout << endl;
    cout << "Inserire l'id dell'aula: ";
    cin >> idaula;

    for(int i = 0; i < corsi; i++){
        if(CLaurea[i].CorsiAula(idaula))
            cout << "Nell'aula e' tenuto il corso numero: " << i + 1 << endl;
    }


    // Mostrare i docenti che insegnano un solo corso

    persona professori[corsi];
    int contatore;

    cout << "-- Lista dei professori che tengono un solo corso --" << endl;

    for(int i = 0; i < corsi; i++)                  // Popola il vettore dei prof di tutto il corso di laurea
        professori[i] = CLaurea[i].PassaProf();

    for(int i = 0; i < corsi; i++){

        contatore = 0;

        for(int j = 0; j < corsi; j++){

            if(professori[j].matricola == professori[i].matricola)
                contatore++;
        }

        if(contatore == 1)
            cout << professori[i].nome << " " << professori[i].cognome << endl;

    }



    return 0;
}
