#ifndef PROFILO_H
#define PROFILO_H
#include"competenze.h"
#include"esperienze.h"
#include"formazione.h"
#include"lingue.h"
#include"rete.h"
#include<vector>
using std::vector;

class Profilo
{
public:
    Profilo(vector<Competenze*> = vector<Competenze*>(),
            vector<Esperienze*> = vector<Esperienze*>(),
            vector<Formazione*> = vector<Formazione*>(),
            vector<Lingue*> = vector<Lingue*>() );

    ~Profilo();

    bool cIsEmpty()const;
    bool eIsEmpty()const;
    bool fIsEmpty()const;
    bool lIsEmpty()const;

    int getSizeC()const;
    int getSizeE()const;
    int getSizeF()const;
    int getSizeL()const;

    void addInC(const Competenze&);
    void addInE(const Esperienze&);
    void addInF(const Formazione&);
    void addInL(const Lingue&);

    void removeInC(int i);
    void removeInE(int i);
    void removeInF(int i);
    void removeInL(int i);

    Competenze* getFromC(int i);
    Esperienze* getFromE(int i);
    Formazione* getFromF(int i);
    Lingue* getFromL(int i);


private:
    vector<Competenze*> c;
    vector<Esperienze*> e;
    vector<Formazione*> f;
    vector<Lingue*> l;
};

#endif // PROFILO_H
