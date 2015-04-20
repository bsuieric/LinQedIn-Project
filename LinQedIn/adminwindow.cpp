#include "adminwindow.h"

AdminWindow::AdminWindow(LinQedInAdmin* ad,QWidget *parent) : QDialog(parent), a(ad)
{

    groupBoxAdd = new QGroupBox(this);
    labelUAdd = new QLabel(groupBoxAdd);
    lineEditUAdd = new QLineEdit(groupBoxAdd);
    labelNAdd = new QLabel(groupBoxAdd);
    lineEditNAdd = new QLineEdit(groupBoxAdd);
    labelCAdd = new QLabel(groupBoxAdd);
    lineEditCAdd = new QLineEdit(groupBoxAdd);
    labelDAdd = new QLabel(groupBoxAdd);
    dataEditAdd = new QDateEdit(groupBoxAdd);
    comboBox = new QComboBox(groupBoxAdd);
    comboBox->insertItem(0,"Utente Basic");
    comboBox->insertItem(0,"Utente Executive");
    comboBox->insertItem(0,"Utente Business");
    pushButtonAdd = new QPushButton(groupBoxAdd);
    groupBoxIscritti = new QGroupBox(this);
    lineEditU = new QLineEdit(groupBoxIscritti);
    pushButtonCerca = new QPushButton(groupBoxIscritti);
    label_listaUtenti = new QLabel(groupBoxIscritti);
    listViewUtenti = new QListWidget(groupBoxIscritti);
    pushButtonElimina = new QPushButton(groupBoxIscritti);
    labelTree = new QLabel(groupBoxIscritti);
    labelTreeUsername = new QLabel(groupBoxIscritti);
    treeWidgetUtente = new QTreeWidget(groupBoxIscritti);
    comboBoxTypeChange = new QComboBox(groupBoxIscritti);
    comboBoxTypeChange->insertItem(0,"Utente Basic");
    comboBoxTypeChange->insertItem(1,"Utente Executive");
    comboBoxTypeChange->insertItem(2,"Utente Business");
    pushButtonESCI = new QPushButton(groupBoxIscritti);

    setupView();

    loadListaUtenti();

    connect(listViewUtenti,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_listViewUtenti_itemDoubleClicked(QListWidgetItem*)));
    connect(pushButtonCerca,SIGNAL(clicked()),this,SLOT(on_pushButtonCerca_clicked()));
    connect(pushButtonAdd,SIGNAL(clicked()),this,SLOT(on_pushButtonAdd_clicked()));
    connect(pushButtonElimina,SIGNAL(clicked()),this,SLOT(on_pushButtonElimina_clicked()));
    connect(pushButtonESCI,SIGNAL(clicked()),this,SLOT(on_pushButtonESCI_clicked()));
    connect(comboBoxTypeChange,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBoxType_change()));
}

AdminWindow::~AdminWindow()
{}

void AdminWindow::setupView(){
    resize(930, 683);

    groupBoxAdd->setGeometry(QRect(10, 20, 911, 231));
    labelUAdd->setGeometry(QRect(310, 30, 71, 16));
    labelNAdd->setGeometry(QRect(310, 60, 59, 16));
    labelCAdd->setGeometry(QRect(310, 90, 59, 16));
    labelDAdd->setGeometry(QRect(310, 120, 101, 16));
    dataEditAdd->setGeometry(QRect(420, 120, 121, 24));
    lineEditCAdd->setGeometry(QRect(420, 90, 113, 21));
    lineEditNAdd->setGeometry(QRect(420, 60, 113, 21));
    lineEditUAdd->setGeometry(QRect(420, 30, 113, 21));
    pushButtonAdd->setGeometry(QRect(390, 190, 115, 32));
    comboBox->setGeometry(QRect(370, 160, 151, 21));
    groupBoxIscritti->setGeometry(QRect(10, 250, 911, 431));
    lineEditU->setGeometry(QRect(390, 30, 121, 21));
    lineEditU->setClearButtonEnabled(true);
    pushButtonCerca->setGeometry(QRect(390, 50, 115, 32));
    listViewUtenti->setGeometry(QRect(60, 100, 291, 281));
    pushButtonElimina->setGeometry(QRect(650, 400, 115, 32));
    treeWidgetUtente->setGeometry(QRect(560, 100, 291, 281));
    label_listaUtenti->setGeometry(QRect(160, 70, 91, 21));
    pushButtonESCI->setGeometry(QRect(370, 370, 181, 51));
    comboBoxTypeChange->setGeometry(QRect(620, 70, 159, 26));
    labelTree->setGeometry(QRect(620, 40, 71, 16));
    labelTreeUsername->setGeometry(QRect(700, 40, 141, 16));

    treeWidgetUtente->header()->setStretchLastSection(false);
    treeWidgetUtente->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    dataEditAdd->setDisplayFormat("dd.MM.yyyy");
    setWindowTitle("Amministrazione");
    groupBoxAdd->setTitle("Nuovo Utente");
    labelUAdd->setText("Username");
    labelNAdd->setText("Nome");
    labelCAdd->setText("Cognome");
    labelDAdd->setText("Data di Nascita");
    pushButtonAdd->setText("Aggiungi");
    groupBoxIscritti->setTitle("Utenti Iscritti");
    lineEditU->setText("Username");
    pushButtonCerca->setText("Cerca");
    pushButtonElimina->setText("Elimina");
    label_listaUtenti->setText("Lista Utenti");
    pushButtonESCI->setText("ESCI");
    labelTree->setText("Username : ");
    labelTreeUsername->setText("");
    treeWidgetUtente->setHeaderLabel("Utente LinQedIn");

    const bool __sortingEnabled = treeWidgetUtente->isSortingEnabled();
    treeWidgetUtente->setSortingEnabled(false);
    treeWidgetUtente->setSortingEnabled(__sortingEnabled);
}

void AdminWindow::loadListaUtenti(){
    listViewUtenti->clear();
    for(int i=0; i<a->getDB()->getSize(); ++i){
        string user=a->getDB()->getU(i)->getUsername();
        QListWidgetItem *newItem= new QListWidgetItem(QString::fromStdString(user));
        listViewUtenti->addItem(newItem);
    }
}

void AdminWindow::loadInfoUtente(Utente* aux){
    treeWidgetUtente->clear();
    labelTreeUsername->setText("");
    if(aux){
        setComboBoxTypeChange(aux);
        labelTreeUsername->setText(QString::fromStdString(aux->getUsername()));
        QTreeWidgetItem* it1=addRoot("Nome");
        it1->setExpanded(true);
        addChild(it1, QString::fromStdString(aux->getInfo()->getNome()));
        QTreeWidgetItem* it2=addRoot("Cognome");
        it2->setExpanded(true);
        addChild(it2, QString::fromStdString(aux->getInfo()->getCognome()));
        QTreeWidgetItem* it3=addRoot("Data di Nascita");
        it3->setExpanded(true);
        addChild(it3, aux->getInfo()->getAnnoNascita().toString("dd.MM.yyyy"));
        QTreeWidgetItem* it4=addRoot("Competenze");
        it4->setExpanded(true);
        for(int i=0; i<aux->getProfilo()->getSizeC();++i)
        {
            QString text= QString::fromStdString(aux->getProfilo()->getFromC(i)->getCompetenza()) +
                    " con voto "+QString::number(aux->getProfilo()->getFromC(i)->getVoto());
            addChild(it4,text);
        }
        QTreeWidgetItem* it5=addRoot("Esperienze");
        it5->setExpanded(true);
        for(int i=0; i<aux->getProfilo()->getSizeE();++i)
        {
            QString text= QString::fromStdString(aux->getProfilo()->getFromE(i)->getEsperienza()) +
                    " Dal "+ aux->getProfilo()->getFromE(i)->getInizioEsp().toString("dd.MM.yyyy")+" Al "+
                    aux->getProfilo()->getFromE(i)->getInizioEsp().toString("dd.MM.yyyy");
            addChild(it5,text);
        }
        QTreeWidgetItem* it6=addRoot("Formazione");
        it6->setExpanded(true);
        for(int i=0; i<aux->getProfilo()->getSizeF();++i)
        {
            QString text= QString::fromStdString(aux->getProfilo()->getFromF(i)->getPercorso()) +
                    " Nel "+ QString::number(aux->getProfilo()->getFromF(i)->getAnnoDiploma());
            addChild(it6,text);
        }
        QTreeWidgetItem* it7=addRoot("Lingue");
        it7->setExpanded(true);
        for(int i=0; i<aux->getProfilo()->getSizeL();++i)
        {
            QString text= QString::fromStdString(aux->getProfilo()->getFromL(i)->getLingua()) +
                    " "+ QString::fromStdString(aux->getProfilo()->getFromL(i)->getLivello());
            addChild(it7,text);
        }
        QTreeWidgetItem* it8=addRoot("Contatti");
        it8->setExpanded(true);
        for(int i=0; i<aux->contactSize();++i)
        {
            addChild(it8,QString::fromStdString(aux->getContact(i)->getContatto()));
        }
    }
}

void AdminWindow:: setComboBoxTypeChange(Utente *u){
    if(dynamic_cast<UtenteBasic*>(u))
        comboBoxTypeChange->setCurrentIndex(0);
    else if(dynamic_cast<UtenteExecutive*>(u))
        comboBoxTypeChange->setCurrentIndex(1);
    else if(dynamic_cast<UtenteBusiness*>(u))
        comboBoxTypeChange->setCurrentIndex(2);
}

QTreeWidgetItem* AdminWindow::addRoot(const QString &name){
    QTreeWidgetItem *itm= new QTreeWidgetItem(treeWidgetUtente);
    itm->setText(0, name);
    treeWidgetUtente->addTopLevelItem(itm);
    return itm;
}

void AdminWindow::addChild(QTreeWidgetItem *parent, const QString& name){
    QTreeWidgetItem *itm=new QTreeWidgetItem();
    itm->setText(0,name);
    parent->addChild(itm);
}

void AdminWindow::on_listViewUtenti_itemDoubleClicked(QListWidgetItem *item){
    Utente *user=a->find(item->text().toStdString());
    loadInfoUtente(user);
}

void AdminWindow::on_pushButtonCerca_clicked(){
    QString username = lineEditU->text();
    if(username==""){
        QMessageBox err;
        err.setText("Inserisci Username");
        lineEditU->setText("");
        err.exec();
    }
    else{
        Utente* aux=a->find(username.toStdString());
        if(aux==0){
            QMessageBox err;
            err.setText("Nessun Utente Trovato");
            err.exec();
            lineEditU->setText("");
        }
        else{
            for(int row = 0; row < listViewUtenti->count(); row++)
            {
                QListWidgetItem *item = listViewUtenti->item(row);
                if(item->text()==username)
                    listViewUtenti->setCurrentItem(item);
            }
            labelTreeUsername->setText(QString::fromStdString(aux->getUsername()));
            loadInfoUtente(aux);
        }
    }
}

void AdminWindow::on_pushButtonAdd_clicked(){
    bool add=true;
    QString username = lineEditUAdd->text();
    QString nome = lineEditNAdd->text();
    QString cognome = lineEditCAdd->text();
    QDate data = dataEditAdd->date();
    if(username == "" || nome == "" || cognome == ""){
        QMessageBox err;
        err.setText("Compila tutti i campi");
        err.exec();
        resetCampiAddUtente();
    }
    else{
        if(comboBox->currentText()=="Utente Basic"){
            Utente* newUtente= new UtenteBasic(username.toStdString(), nome.toStdString(), cognome.toStdString(), data);
            add=a->addU(newUtente);
            a->getDB()->save();
            loadListaUtenti();
        }
        else
            if(comboBox->currentText()=="Utente Executive"){
                Utente* newUtente= new UtenteExecutive(username.toStdString(), nome.toStdString(), cognome.toStdString(), data);
                add=a->addU(newUtente);
                a->getDB()->save();
                loadListaUtenti();
            }
        else
            if(comboBox->currentText()=="Utente Business"){
                Utente* newUtente= new UtenteBusiness(username.toStdString(), nome.toStdString(), cognome.toStdString(), data);
                add=a->addU(newUtente);
                a->getDB()->save();
                loadListaUtenti();
            }
        QMessageBox ok;
        if(!add){
            ok.setText("Utente Aggiunto");
            ok.exec();
        }
        else{
            ok.setText("Username già presente");
            ok.exec();
        }
    }
    resetCampiAddUtente();
}

void AdminWindow::resetCampiAddUtente(){
    lineEditUAdd->setText("");
    lineEditNAdd->setText("");
    lineEditCAdd->setText("");
}

void AdminWindow::on_pushButtonElimina_clicked(){
    QString username = labelTreeUsername->text();
    QMessageBox err;
    Utente * u= a->find(username.toStdString());
    if(u){
        int reply = QMessageBox::question(this, "Cancellazione Utente", "Confermi la cancellazione del utente?",
                                              QMessageBox::Yes, QMessageBox::Cancel);
              if(reply == QMessageBox::Yes){
                  labelTreeUsername->setText("");
                    treeWidgetUtente->clear();
                    for(int row = 0; row < listViewUtenti->count(); row++)
                    {
                        QListWidgetItem *item = listViewUtenti->item(row);
                        if(item->text()==username){
                            listViewUtenti->removeItemWidget(listViewUtenti->takeItem(row));
                            listViewUtenti->removeItemWidget(item);
                            delete item;
                        }
                    }
                    a->removeU(u->getUsername());
                    a->getDB()->save();
              }
    }
    else{
        err.setText("Nessun utente selezionato");
        err.exec();
    }

}

void AdminWindow::on_comboBoxType_change(){
    QString username = labelTreeUsername->text();
    if(username != ""){
        int reply = QMessageBox::question(this, "Cambio Tipo Utente", "Confermi di cambiare tipo?",
                                              QMessageBox::Yes, QMessageBox::Cancel);
              if(reply == QMessageBox::Yes){
                    a->getDB()->changeSubcriptionType(username.toStdString(), comboBoxTypeChange->currentText().toStdString());
                    a->getDB()->save();
              }
    }
}

void AdminWindow::on_pushButtonESCI_clicked(){
    this->close();
}

