#ifndef UTENTE_H
#define UTENTE_H
#include"competenze.h"
#include"esperienze.h"
#include"formazione.h"
#include"infopersonali.h"
#include"lingue.h"
#include"profilo.h"
#include"rete.h"
#include<vector>
#include"QList"
#include"QString"
using std::vector;

class DB;
class Utente
{
    friend class SearchFunctor;
public:
    Utente(string, string, string, QDate, string="", Profilo* = new Profilo(), vector<Rete*> = vector<Rete*>());
    virtual ~Utente() =0;

    string getUsername()const;
    void setUsername(const string&);

    InfoPersonali* getInfo()const;

    Profilo* getProfilo()const;

    bool contactIsEmpty()const;
    int contactSize()const;
    void addContact(const Rete&);
    void removeContact(const string&);
    Rete* getContact(int i)const;
    vector<Rete*> getVectorRete()const;

    virtual void userSearch(const DB &, const string &, QList<QString> &) =0;
    class SearchFunctor
    {
    public:
        int searchType;
        SearchFunctor(int x=0) : searchType(x) {}
        void operator() (const Utente* u, QList<QString>& list) const
        {
            switch(searchType)
            {
                case 1:
                    list.push_back("Nome : "+QString::fromStdString(u->getInfo()->getNome()));
                    list.push_back("Cognome : "+QString::fromStdString(u->getInfo()->getCognome()));
                    list.push_back("Anno di Nascita : "+u->getInfo()->getAnnoNascita().toString("dd.MM.yyyy"));
                    break;
                case 2:
                list.push_back("Nome : "+QString::fromStdString(u->getInfo()->getNome()));
                list.push_back("Cognome : "+QString::fromStdString(u->getInfo()->getCognome()));
                list.push_back("Anno di Nascita : "+u->getInfo()->getAnnoNascita().toString("dd.MM.yyyy"));
                for(int i=0 ; i< u->getProfilo()->getSizeC();++i){
                    QString competenza=QString::fromStdString(u->getProfilo()->getFromC(i)->getCompetenza()).append(" con voto ").append(
                                QString::number(u->getProfilo()->getFromC(i)->getVoto()));
                    list.push_back("Competenza : "+competenza);
                }
                for(int i=0 ; i< u->getProfilo()->getSizeE();++i){
                    QString esperienza=QString::fromStdString(u->getProfilo()->getFromE(i)->getEsperienza()).append(" dal ").append(
                                u->getProfilo()->getFromE(i)->getInizioEsp().toString("dd.MM.yyyy").append(" al ").append(
                                    u->getProfilo()->getFromE(i)->getFineEsp().toString("dd.MM.yyyy")));
                    list.push_back("Esperienza : "+esperienza);
                }
                for(int i=0 ; i< u->getProfilo()->getSizeF();++i){
                    QString formazione=QString::fromStdString(u->getProfilo()->getFromF(i)->getPercorso()).append(" Anno Diploma: ").append(
                                QString::number(u->getProfilo()->getFromF(i)->getAnnoDiploma()));
                    list.push_back("Formazione : "+formazione);
                }
                for(int i=0 ; i< u->getProfilo()->getSizeL();++i){
                    QString lingua=QString::fromStdString(u->getProfilo()->getFromL(i)->getLingua()).append(" Livello ").append(
                                QString::fromStdString(u->getProfilo()->getFromL(i)->getLivello()));
                    list.push_back("Lingua : "+lingua);
                }
                    break;

                case 3:
                list.push_back("Nome : "+QString::fromStdString(u->getInfo()->getNome()));
                list.push_back("Cognome : "+QString::fromStdString(u->getInfo()->getCognome()));
                list.push_back("Anno di Nascita : "+u->getInfo()->getAnnoNascita().toString("dd.MM.yyyy"));
                for(int i=0 ; i< u->getProfilo()->getSizeC();++i){
                    QString competenza=QString::fromStdString(u->getProfilo()->getFromC(i)->getCompetenza()).append(" con voto ").append(
                                QString::number(u->getProfilo()->getFromC(i)->getVoto()));
                    list.push_back("Competenza : "+competenza);
                }
                for(int i=0 ; i< u->getProfilo()->getSizeE();++i){
                    QString esperienza=QString::fromStdString(u->getProfilo()->getFromE(i)->getEsperienza()).append(" dal ").append(
                                u->getProfilo()->getFromE(i)->getInizioEsp().toString("dd.MM.yyyy").append(" al ").append(
                                    u->getProfilo()->getFromE(i)->getFineEsp().toString("dd.MM.yyyy")));
                    list.push_back("Esperienza : "+esperienza);
                }
                for(int i=0 ; i< u->getProfilo()->getSizeF();++i){
                    QString formazione=QString::fromStdString(u->getProfilo()->getFromF(i)->getPercorso()).append(" Anno Diploma: ").append(
                                QString::number(u->getProfilo()->getFromF(i)->getAnnoDiploma()));
                    list.push_back("Formazione : "+formazione);
                }
                for(int i=0 ; i< u->getProfilo()->getSizeL();++i){
                    QString lingua=QString::fromStdString(u->getProfilo()->getFromL(i)->getLingua()).append(" Livello ").append(
                                QString::fromStdString(u->getProfilo()->getFromL(i)->getLivello()));
                    list.push_back("Lingua : "+lingua);
                }
                for(int i=0;i<u->contactSize();++i){
                    list.push_back("Contatto : "+QString::fromStdString(u->getContact(i)->getContatto()));
                }
                break;
            }
        }
    };
private:
    string username;
    InfoPersonali* info;
    Profilo* p;
    vector<Rete*> contact;
};

#endif // UTENTE_H
