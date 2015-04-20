#ifndef ESPERIENZE_H
#define ESPERIENZE_H
#include<string>
using std::string;
#include<QDate>

class Esperienze
{
public:
    Esperienze(string, QDate, QDate);
    ~Esperienze();

    string getEsperienza()const;
    void setEsperienza(const string&);

    QDate getInizioEsp()const;
    void setInizioEsp(const QDate&);

    QDate getFineEsp()const;
    void setFineEsp(const QDate&);
private:
    string esperienza;
    QDate inizioEsp;
    QDate fineEsp;
};

#endif // ESPERIENZE_H
