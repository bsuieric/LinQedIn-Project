#ifndef INFOPERSONALI_H
#define INFOPERSONALI_H
#include<QDate>
using std::string;

class InfoPersonali
{
public:
    InfoPersonali(string,string,QDate,string="");
    ~InfoPersonali();

    string getNome()const;
    void setNome(const string&);

    string getCognome()const;
    void setCognome(const string&);

    QDate getAnnoNascita()const;
    void setAnnoNascita(const QDate&);

    string getDescrizione()const;
    void setDescrizione(const string&);
private:
    string nome;
    string cognome;
    QDate annoNascita;
    string descrizione;
};

#endif // INFOPERSONALI_H
