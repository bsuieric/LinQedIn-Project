#ifndef DB_H
#define DB_H
#include<vector>
using std::vector;
#include"utente.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"
#include"QFile"
#include"QXmlStreamReader"
#include"QXmlStreamWriter"
#include"QStringList"
#include"QFileDialog"
#include"QMessageBox"
#include"QDomDocument"

class Utente;
class UtenteBasic;
class DB
{
public:
    DB(const vector<Utente*>& = vector<Utente*>());
    ~DB();

    bool uIsEmpty()const;

    int getSize()const;

    bool addUtenti(Utente*);

    void removeUtente(string);

    Utente* getU(int);

    Utente* findU(const string&)const;

    void save()const;

    void load();

    void changeSubcriptionType(const string&, const string&);

    vector<Utente*> getVectorUtenti()const;
private:
    vector<Utente*> u;
};

#endif // DB_H
