#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H
#include"db.h"
#include"utente.h"

class DB;
class UtenteBasic : public Utente
{
public:
    UtenteBasic(string, string, string, QDate, string="", Profilo* = new Profilo(), vector<Rete*> = vector<Rete*>());
    virtual void userSearch(const DB&, const string& u, QList<QString>&) ;
};

#endif // UTENTEBASIC_H
