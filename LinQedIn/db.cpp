#include "db.h"

DB::DB(const vector<Utente*>& utenti): u(utenti)
{
    load();
}

DB::~DB()
{
    for(vector<Utente*>::iterator it= u.begin(); it!=u.end();++it)
        delete *it;
}

bool DB::uIsEmpty()const{
    return u.empty();
}

int DB::getSize()const{
    return u.size();
}

bool DB::addUtenti(Utente* ut){
    bool trovato=false;
    vector<Utente*>::iterator it= u.begin();
    for(; it!=u.end() && !trovato ;++it){
        if((*it)->getUsername()==ut->getUsername())
            trovato=true;
    }
    if(!trovato)
        u.push_back(ut);
    return trovato;
}

void DB::removeUtente(string user){
    for(unsigned int i=0; i<u.size();++i){
        if(getU(i)->getUsername()==user){
            delete getU(i);
            u.erase(u.begin()+i);
        }
    }
}

vector<Utente*> DB::getVectorUtenti()const{
    return u;
}

Utente* DB::getU(int i){
    vector<Utente*>::iterator it=u.begin()+i;
    return *it;
}

Utente* DB::findU(const string& user)const{
    vector<Utente*>::const_iterator it=u.begin();
    for( ; it != u.end() ; ++it){
        if((*it)->getUsername()==user)
            return *it;
    }
    return 0;

}

void DB::load(){
    QFile *file=new QFile("/Users/BGD/Desktop/LinQedIn/LinQedInYes/utentiLinQedIn.xml");
    if(file->exists()){
        if(!file->open(QFile::ReadOnly | QFile::Text)){
            QMessageBox err;
            err.setText("Errore nell'apertura del file");
            err.exec();
        }
        else{
            QDomDocument doc;
            if(!doc.setContent(file))
            {
                return;
            }
            QDomElement docElem=doc.documentElement();
            QDomNodeList nodes=docElem.elementsByTagName("Utente");
            for(int i=0; i<nodes.count();++i){
                QDomElement el=nodes.at(i).toElement();
                QDomNode nodo=el.firstChild();
                QDomAttr t=el.attributeNode("tipo");
                QString tipo=t.value();
                QString u, n, c, d;
                QDate data;
                Competenze* comp;
                Esperienze* esp;
                Formazione* form;
                Lingue* ling;
                Rete* re;
                vector<Rete*> rete;
                Profilo* p=new Profilo();
                while(!nodo.isNull()){
                    QDomElement elemento = nodo.toElement();
                    QString tagName = elemento.tagName();
                    if(tagName == "Username")
                    {
                        u=elemento.text();
                    }
                    if(tagName == "Nome")
                    {
                        n=elemento.text();
                    }
                    if(tagName == "Cognome")
                    {
                        c=elemento.text();
                    }
                    if(tagName == "DataNascita")
                    {
                        QString aux=elemento.text();
                        QStringList l=aux.split(".");
                        data.setDate(l[2].toInt(),l[1].toInt(),l[0].toInt());
                    }
                    if(tagName == "Descrizione")
                    {
                        d=elemento.text();
                    }

                    if(tagName == "Competenze")
                    {
                        QString nomeC=elemento.attributeNode("nome").value();
                        int votoC=elemento.attributeNode("voto").value().toInt();
                        comp=new Competenze(nomeC.toStdString(), votoC);
                        p->addInC(*comp);
                    }
                    if(tagName == "Esperienze")
                    {
                        QString nomeE=elemento.attributeNode("nome").value();
                        QString inizio=elemento.attributeNode("inizio").value();
                        QString fine=elemento.attributeNode("fine").value();
                        QStringList i=inizio.split(".");
                        QStringList f=fine.split(".");
                        QDate in(i[2].toInt(),i[1].toInt(),i[0].toInt());
                        QDate fi(f[2].toInt(),f[1].toInt(),f[0].toInt());
                        esp=new Esperienze(nomeE.toStdString(), in, fi);
                        p->addInE(*esp);
                    }
                    if(tagName == "Studi")
                    {
                        QString nomeS=elemento.attributeNode("percorso").value();
                        int annoS=elemento.attributeNode("anno").value().toInt();
                        form=new Formazione(nomeS.toStdString(), annoS);
                        p->addInF(*form);
                    }
                    if(tagName == "Lingue")
                    {
                        QString nomeL=elemento.attributeNode("nome").value();
                        QString livelloL=elemento.attributeNode("livello").value();
                        ling = new Lingue(nomeL.toStdString(), livelloL.toStdString());
                        p->addInL(*ling);
                    }
                    if(tagName == "Rete")
                    {
                        QString nomeUser=elemento.attributeNode("username").value();
                        re=new Rete(nomeUser.toStdString());
                        rete.push_back(re);
                    }
                    nodo=nodo.nextSibling();
                }
                Utente* ut = 0;
                if(tipo=="Basic")
                {
                    ut=new UtenteBasic(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString(), p, rete);
                }
                if(tipo=="Executive")
                {
                    ut=new UtenteExecutive(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString(), p, rete);
                }
                if(tipo=="Business"){
                    ut=new UtenteBusiness(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString(), p, rete);
                }
                addUtenti(ut);
            }
            file->close();
        }
    }
}

void DB::save() const
{
    QFile* file = new QFile("/Users/BGD/Desktop/LinQedIn/LinQedInYes/utentiLinQedIn.xml");
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
       QMessageBox err;
       err.setText("Errore nell'apertura del file");
       err.exec();
    }
    else
    {
       QXmlStreamWriter* inp = new QXmlStreamWriter;
       inp->setAutoFormatting(true);
       inp->setDevice(file);
       inp->writeStartDocument();
       inp->writeStartElement("Utenti");
       for(vector<Utente*>::const_iterator it = u.begin(); it != u.end(); ++it)
       {
           Utente* ut= *it;
           inp->writeStartElement("Utente");
           if(dynamic_cast<UtenteBasic*>(*(it)))
           {
               inp->writeAttribute("tipo","Basic");
           }
           else if(dynamic_cast<UtenteExecutive*>(*(it)))
           {
               inp->writeAttribute("tipo","Executive");
           }
           else if(dynamic_cast<UtenteBusiness*>(*(it)))
           {
               inp->writeAttribute("tipo","Business");
           }
           inp->writeTextElement("Username", QString::fromStdString(ut->getUsername()));
           inp->writeTextElement("Nome", QString::fromStdString(ut->getInfo()->getNome()));
           inp->writeTextElement("Cognome", QString::fromStdString(ut->getInfo()->getCognome()));
           inp->writeTextElement("DataNascita", (ut->getInfo()->getAnnoNascita().toString("dd.MM.yyyy")));
           inp->writeTextElement("Descrizione", QString::fromStdString(ut->getInfo()->getDescrizione()));
           for(int i=0; i< ut->getProfilo()->getSizeC();++i){
               inp->writeEmptyElement("Competenze");
               inp->writeAttribute("nome", QString::fromStdString(ut->getProfilo()->getFromC(i)->getCompetenza()));
               inp->writeAttribute("voto", QString::number(ut->getProfilo()->getFromC(i)->getVoto()));
           }
           for(int i=0; i< ut->getProfilo()->getSizeE();++i){
               inp->writeEmptyElement("Esperienze");
               inp->writeAttribute("nome", QString::fromStdString(ut->getProfilo()->getFromE(i)->getEsperienza()));
               inp->writeAttribute("inizio", ut->getProfilo()->getFromE(i)->getInizioEsp().toString("dd.MM.yyyy"));
               inp->writeAttribute("fine", ut->getProfilo()->getFromE(i)->getFineEsp().toString("dd.MM.yyyy"));
           }
           for(int i=0; i< ut->getProfilo()->getSizeF();++i){
               inp->writeEmptyElement("Studi");
               inp->writeAttribute("percorso", QString::fromStdString(ut->getProfilo()->getFromF(i)->getPercorso()));
               inp->writeAttribute("anno", QString::number(ut->getProfilo()->getFromF(i)->getAnnoDiploma()));
           }
           for(int i=0; i< ut->getProfilo()->getSizeL();++i){
               inp->writeEmptyElement("Lingue");
               inp->writeAttribute("nome", QString::fromStdString(ut->getProfilo()->getFromL(i)->getLingua()));
               inp->writeAttribute("livello", QString::fromStdString(ut->getProfilo()->getFromL(i)->getLivello()));
           }
           for(int i=0; i<ut->contactSize();++i){
               inp->writeEmptyElement("Rete");
               inp->writeAttribute("username", QString::fromStdString(ut->getContact(i)->getContatto()));
           }
           inp->writeEndElement();
        }
        inp->writeEndElement();
        inp->writeEndDocument();
        file->close();
    }
}

void DB::changeSubcriptionType(const string& user, const string& tipo)
{
    Utente *aux=findU(user);
    string u=aux->getUsername();
    string n=aux->getInfo()->getNome();
    string c=aux->getInfo()->getCognome();
    QDate date=aux->getInfo()->getAnnoNascita();
    string d=aux->getInfo()->getDescrizione();
    Profilo * newProfilo= new Profilo();
    vector<Rete*> contatti=vector<Rete*>();
    for(int i=0; i<aux->getProfilo()->getSizeC();++i){
        string comp=aux->getProfilo()->getFromC(i)->getCompetenza();
        int voto=aux->getProfilo()->getFromC(i)->getVoto();
        Competenze* newCompetenze=new Competenze(comp,voto);
        newProfilo->addInC(*newCompetenze);
    }
    for(int i=0; i<aux->getProfilo()->getSizeE();++i){
        string esp=aux->getProfilo()->getFromE(i)->getEsperienza();
        QDate ini=aux->getProfilo()->getFromE(i)->getInizioEsp();
        QDate fin=aux->getProfilo()->getFromE(i)->getFineEsp();
        Esperienze* newEsperienza= new Esperienze(esp,ini,fin);
        newProfilo->addInE(*newEsperienza);
    }
    for(int i=0; i<aux->getProfilo()->getSizeF();++i){
        string form=aux->getProfilo()->getFromF(i)->getPercorso();
        int anno=aux->getProfilo()->getFromF(i)->getAnnoDiploma();
        Formazione* newFormazione=new Formazione(form,anno);
        newProfilo->addInF(*newFormazione);
    }
    for(int i=0; i<aux->getProfilo()->getSizeL();++i){
        string lingua=aux->getProfilo()->getFromL(i)->getLingua();
        string livello=aux->getProfilo()->getFromL(i)->getLivello();
        Lingue* newLingue=new Lingue(lingua,livello);
        newProfilo->addInL(*newLingue);
    }
    for(int i=0; i<aux->contactSize();++i){
        string contatto=aux->getContact(i)->getContatto();
        Rete* newRete= new Rete(contatto);
        contatti.push_back(newRete);
    }
    removeUtente(u);
    Utente *newUtente=0;
    if(tipo=="Utente Basic"){
        newUtente=new UtenteBasic(u,n,c,date,d,newProfilo,contatti);
        addUtenti(newUtente);
    }
    if(tipo=="Utente Business"){
        newUtente=new UtenteBusiness(u,n,c,date,d,newProfilo,contatti);
        addUtenti(newUtente);
    }
    if(tipo=="Utente Executive"){
        newUtente=new UtenteExecutive(u,n,c,date,d,newProfilo,contatti);
        addUtenti(newUtente);
    }
    save();
}
