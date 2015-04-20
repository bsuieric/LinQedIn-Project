#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive(string u, string n, string c, QDate d, string descr, Profilo* pr,vector<Rete*> r):
    Utente(u,n,c,d,descr,pr,r)
{}

void UtenteExecutive::userSearch(const DB& db, const string& user, QList<QString>& list)
{
    Utente* ut = db.findU(user);
    Utente::SearchFunctor sf(3);
    sf(ut, list);
}
