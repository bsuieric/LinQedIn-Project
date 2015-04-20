#include "clientwindow.h"

ClientWindow::ClientWindow(LinQedInClient* client, QWidget *parent) : QDialog(parent), cl(client)
{
    groupBoxInfo = new QGroupBox(this);
    labelUsername = new QLabel(groupBoxInfo);
    labelNome = new QLabel(groupBoxInfo);
    labelCognome = new QLabel(groupBoxInfo);
    labelNascita = new QLabel(groupBoxInfo);
    labelDescrizione = new QLabel(groupBoxInfo);
    labelUser = new QLabel(groupBoxInfo);
    lineEditNome = new QLineEdit(groupBoxInfo);
    lineEditCognome = new QLineEdit(groupBoxInfo);
    dateEditNascita = new QDateEdit(groupBoxInfo);
    textEditDescrizione = new QTextEdit(groupBoxInfo);
    pushButtonSalva = new QPushButton(groupBoxInfo);
    toolBoxProfilo = new QToolBox(groupBoxInfo);
    pageContatti = new QWidget();
    listWidgetContatti = new QListWidget(pageContatti);
    pushButtonEliminaContatto = new QPushButton(pageContatti);
    treeWidgetInfoContatto = new QTreeWidget(pageContatti);
    pageFormazione = new QWidget();
    pushButtonAggiungiFormazione = new QPushButton(pageFormazione);
    pushButtonEliminaFormazione = new QPushButton(pageFormazione);
    tableWidgetFormazione = new QTableWidget(pageFormazione);
    if (tableWidgetFormazione->columnCount() < 2)
        tableWidgetFormazione->setColumnCount(2);
    QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
    tableWidgetFormazione->setHorizontalHeaderItem(0, __qtablewidgetitem);
    QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
    tableWidgetFormazione->setHorizontalHeaderItem(1, __qtablewidgetitem1);
    pageEsperienze = new QWidget();
    pushButtonAggiungiEsperienza = new QPushButton(pageEsperienze);
    tableWidgetEsperienze = new QTableWidget(pageEsperienze);
    if (tableWidgetEsperienze->columnCount() < 3)
        tableWidgetEsperienze->setColumnCount(3);
    QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
    tableWidgetEsperienze->setHorizontalHeaderItem(0, __qtablewidgetitem2);
    QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
    tableWidgetEsperienze->setHorizontalHeaderItem(1, __qtablewidgetitem3);
    QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
    tableWidgetEsperienze->setHorizontalHeaderItem(2, __qtablewidgetitem4);
    pushButtonEliminaEsperienza = new QPushButton(pageEsperienze);
    pageCompetenze = new QWidget();
    pushButtonAggiungiCompetenza = new QPushButton(pageCompetenze);
    tableWidgetCompetenze = new QTableWidget(pageCompetenze);
    if (tableWidgetCompetenze->columnCount() < 2)
        tableWidgetCompetenze->setColumnCount(2);
    QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
    tableWidgetCompetenze->setHorizontalHeaderItem(0, __qtablewidgetitem5);
    QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
    tableWidgetCompetenze->setHorizontalHeaderItem(1, __qtablewidgetitem6);
    pushButtonEliminaCompetenza = new QPushButton(pageCompetenze);
    pageLingue = new QWidget();
    tableWidgetLingue = new QTableWidget(pageLingue);
    if (tableWidgetLingue->columnCount() < 2)
        tableWidgetLingue->setColumnCount(2);
    QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
    tableWidgetLingue->setHorizontalHeaderItem(0, __qtablewidgetitem7);
    QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
    tableWidgetLingue->setHorizontalHeaderItem(1, __qtablewidgetitem8);
    pushButtonAggiungiLingua = new QPushButton(pageLingue);
    pushButtonEliminaLingua = new QPushButton(pageLingue);
    groupBoxSearch = new QGroupBox(this);
    listWidgetRicerca = new QListWidget(groupBoxSearch);
    labelRicercaUsername = new QLabel(groupBoxSearch);
    labelRicercaUser = new QLabel(groupBoxSearch);
    lineEditRicercaUsername = new QLineEdit(groupBoxSearch);
    pushButtonRicerca = new QPushButton(groupBoxSearch);
    pushButtonAggiungiContatto = new QPushButton(groupBoxSearch);

    setView();
    loadInfoUtente();
    loadProfiloUtente();

    connect(listWidgetContatti,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_listWidgetContatti_doubleClicked(QListWidgetItem*)));
    connect(pushButtonEliminaContatto,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaContatto_clicked()));
    connect(pushButtonAggiungiFormazione,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiFormazione_clicked()));
    connect(pushButtonEliminaFormazione,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaFormazione_clicked()));
    connect(pushButtonAggiungiEsperienza,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiEsperienze_clicked()));
    connect(pushButtonEliminaEsperienza,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaEsperienze_clicked()));
    connect(pushButtonAggiungiCompetenza,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiCompetenze_clicked()));
    connect(pushButtonEliminaCompetenza,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaCompetenze_clicked()));
    connect(pushButtonAggiungiLingua,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiLingue_clicked()));
    connect(pushButtonEliminaLingua,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaLingue_clicked()));
    connect(pushButtonRicerca,SIGNAL(clicked()),this,SLOT(on_pushButtonRicercaContatti_clicked()));
    connect(pushButtonAggiungiContatto,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiContatto_clicked()));
    connect(pushButtonSalva,SIGNAL(clicked()),this,SLOT(on_pushButtonEsciSalva_clicked()));
}

ClientWindow::~ClientWindow()
{}

void ClientWindow::setView(){
    resize(1071, 602);

    groupBoxInfo->setGeometry(QRect(0, 10, 811, 581));
    labelUsername->setGeometry(QRect(10, 30, 101, 16));
    labelNome->setGeometry(QRect(10, 60, 101, 16));
    labelCognome->setGeometry(QRect(10, 90, 101, 16));
    labelNascita->setGeometry(QRect(10, 120, 101, 16));
    labelDescrizione->setGeometry(QRect(10, 150, 101, 16));
    labelUser->setGeometry(QRect(128, 30, 131, 20));
    lineEditNome->setGeometry(QRect(130, 60, 131, 21));
    lineEditCognome->setGeometry(QRect(130, 90, 131, 21));
    dateEditNascita->setGeometry(QRect(130, 120, 110, 24));
    textEditDescrizione->setGeometry(QRect(130, 150, 131, 161));
    pushButtonSalva->setGeometry(QRect(20, 491, 201, 71));
    pushButtonSalva->setFocusPolicy(Qt::NoFocus);
    pushButtonSalva->setDefault(false);
    pushButtonSalva->setFlat(false);
    toolBoxProfilo->setGeometry(QRect(280, 30, 481, 501));
    pageContatti->setGeometry(QRect(0, 0, 481, 331));
    listWidgetContatti->setGeometry(QRect(0, 0, 181, 241));
    pushButtonEliminaContatto->setGeometry(QRect(30, 260, 115, 32));
    treeWidgetInfoContatto->setGeometry(QRect(265, 0, 211, 241));
    toolBoxProfilo->addItem(pageContatti, QStringLiteral("Contatti"));
    pageFormazione->setGeometry(QRect(0, 0, 481, 331));
    pushButtonAggiungiFormazione->setGeometry(QRect(70, 260, 131, 32));
    pushButtonEliminaFormazione->setGeometry(QRect(250, 260, 131, 32));
    tableWidgetFormazione->setGeometry(QRect(41, 31, 381, 221));

    tableWidgetFormazione->horizontalHeader()->setDefaultSectionSize(189);
    toolBoxProfilo->addItem(pageFormazione, QStringLiteral("Formazione"));
    pageEsperienze->setGeometry(QRect(0, 0, 481, 331));
    pushButtonAggiungiEsperienza->setGeometry(QRect(90, 270, 115, 32));
    tableWidgetEsperienze->setGeometry(QRect(10, 20, 461, 231));
    tableWidgetEsperienze->horizontalHeader()->setDefaultSectionSize(153);
    pushButtonEliminaEsperienza->setGeometry(QRect(260, 270, 115, 32));
    toolBoxProfilo->addItem(pageEsperienze, QStringLiteral("Esperienze Lavorative"));
    pageCompetenze->setGeometry(QRect(0, 0, 481, 331));
    pushButtonAggiungiCompetenza->setGeometry(QRect(70, 280, 115, 32));
    tableWidgetCompetenze->setGeometry(QRect(40, 10, 391, 261));
    tableWidgetCompetenze->horizontalHeader()->setDefaultSectionSize(194);
    pushButtonEliminaCompetenza->setGeometry(QRect(280, 280, 115, 32));
    toolBoxProfilo->addItem(pageCompetenze, QStringLiteral("Competenze"));
    pageLingue->setGeometry(QRect(0, 0, 481, 331));
    tableWidgetLingue->setGeometry(QRect(40, 10, 401, 251));
    tableWidgetLingue->horizontalHeader()->setDefaultSectionSize(199);
    pushButtonAggiungiLingua->setGeometry(QRect(80, 270, 115, 32));
    pushButtonEliminaLingua->setGeometry(QRect(270, 270, 115, 32));
    toolBoxProfilo->addItem(pageLingue, QStringLiteral("Lingue"));
    groupBoxSearch->setGeometry(QRect(820, 10, 581, 581));
    listWidgetRicerca->setGeometry(QRect(10, 200, 231, 321));
    labelRicercaUsername->setGeometry(QRect(40, 170, 91, 20));
    labelRicercaUser->setGeometry(QRect(400, 80, 121, 21));
    lineEditRicercaUsername->setGeometry(QRect(50, 50, 131, 21));
    lineEditRicercaUsername->setClearButtonEnabled(true);
    pushButtonRicerca->setGeometry(QRect(60, 80, 115, 32));
    pushButtonAggiungiContatto->setGeometry(QRect(40, 540, 181, 32));
    toolBoxProfilo->setCurrentIndex(1);
    setWindowTitle( "Utente LinQedIn");
    groupBoxInfo->setTitle( "Informazioni Personali");
    labelUsername->setText( "Username");
    labelNome->setText( "Nome");
    labelCognome->setText( "Cognome");
    labelNascita->setText( "Data di Nascita");
    labelDescrizione->setText( "Descrizione");
    labelUser->setText( "text");
    lineEditNome->setText(QString());
    dateEditNascita->setDisplayFormat( "dd/MM/yyyy");
    pushButtonSalva->setText( "Salva Modifiche ed Esci");
    pushButtonEliminaContatto->setText( "Rimuovi");
    treeWidgetInfoContatto->header()->setStretchLastSection(false);
    treeWidgetInfoContatto->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    QTreeWidgetItem *___qtreewidgetitem = treeWidgetInfoContatto->headerItem();
    ___qtreewidgetitem->setText(0,  "Contatto LinQedIn");
    toolBoxProfilo->setItemText(toolBoxProfilo->indexOf(pageContatti),  "Contatti");
    pushButtonAggiungiFormazione->setText( "Aggiungi");
    pushButtonEliminaFormazione->setText( "Rimuovi");
    QTableWidgetItem *___qtablewidgetitem = tableWidgetFormazione->horizontalHeaderItem(0);
    ___qtablewidgetitem->setText( "Percorso");
    QTableWidgetItem *___qtablewidgetitem1 = tableWidgetFormazione->horizontalHeaderItem(1);
    ___qtablewidgetitem1->setText( "Anno Diploma");
    toolBoxProfilo->setItemText(toolBoxProfilo->indexOf(pageFormazione),  "Formazione");
    pushButtonAggiungiEsperienza->setText( "Aggiungi");
    QTableWidgetItem *___qtablewidgetitem2 = tableWidgetEsperienze->horizontalHeaderItem(0);
    ___qtablewidgetitem2->setText( "Esperienza");
    QTableWidgetItem *___qtablewidgetitem3 = tableWidgetEsperienze->horizontalHeaderItem(1);
    ___qtablewidgetitem3->setText( "Inizio");
    QTableWidgetItem *___qtablewidgetitem4 = tableWidgetEsperienze->horizontalHeaderItem(2);
    ___qtablewidgetitem4->setText( "Fine");
    pushButtonEliminaEsperienza->setText( "Rimuovi");
    toolBoxProfilo->setItemText(toolBoxProfilo->indexOf(pageEsperienze),  "Esperienze Lavorative");
    pushButtonAggiungiCompetenza->setText( "Aggiungi");
    QTableWidgetItem *___qtablewidgetitem5 = tableWidgetCompetenze->horizontalHeaderItem(0);
    ___qtablewidgetitem5->setText( "Argomento");
    QTableWidgetItem *___qtablewidgetitem6 = tableWidgetCompetenze->horizontalHeaderItem(1);
    ___qtablewidgetitem6->setText( "Livello");
    pushButtonEliminaCompetenza->setText( "Rimuovi");
    toolBoxProfilo->setItemText(toolBoxProfilo->indexOf(pageCompetenze),  "Competenze");
    QTableWidgetItem *___qtablewidgetitem7 = tableWidgetLingue->horizontalHeaderItem(0);
    ___qtablewidgetitem7->setText( "Lingua");
    QTableWidgetItem *___qtablewidgetitem8 = tableWidgetLingue->horizontalHeaderItem(1);
    ___qtablewidgetitem8->setText( "Livello");
    pushButtonAggiungiLingua->setText( "Aggiungi");
    pushButtonEliminaLingua->setText( "Rimuovi");
    toolBoxProfilo->setItemText(toolBoxProfilo->indexOf(pageLingue),  "Lingue");
    groupBoxSearch->setTitle( "Spazio Ricerca");
    labelRicercaUsername->setText( "Username : ");
    labelRicercaUser->setText(QString());
    lineEditRicercaUsername->setText( "Username");
    pushButtonRicerca->setText( "Cerca");
    pushButtonAggiungiContatto->setText( "Aggiungi Contatto");
    dateEditNascita->setDisplayFormat("dd.MM.yyyy");

}

void ClientWindow::loadInfoUtente(){
    labelUser->setText(QString::fromStdString(cl->getClient()->getUsername()));
    lineEditNome->setText(QString::fromStdString(cl->getClient()->getInfo()->getNome()));
    lineEditCognome->setText(QString::fromStdString(cl->getClient()->getInfo()->getCognome()));
    dateEditNascita->setDate(cl->getClient()->getInfo()->getAnnoNascita());
    textEditDescrizione->setText(QString::fromStdString(cl->getClient()->getInfo()->getDescrizione()));
}

void ClientWindow::loadProfiloUtente(){
    loadContattiUtente();
    loadFormazioneUtente();
    loadEsperienzeUtente();
    loadCompetenzeUtente();
    loadLingueUtente();
}

void ClientWindow::loadContattiUtente(){
    listWidgetContatti->clear();
    for(int i=0; i<cl->getClient()->contactSize();++i){
        string username=cl->getClient()->getContact(i)->getContatto();
        if(cl->getDB()->findU(username)){
            QListWidgetItem * item= new QListWidgetItem(QString::fromStdString(username));
            listWidgetContatti->insertItem(0,item);
        }
        else
            cl->getClient()->removeContact(username);
    }
}

void ClientWindow::loadFormazioneUtente(){
    tableWidgetFormazione->clearContents();
    int num_rows=cl->getClient()->getProfilo()->getSizeF();
    tableWidgetFormazione->setRowCount(num_rows);
    tableWidgetFormazione->setColumnCount(2);
    for(int i=0; i<num_rows;++i){
        tableWidgetFormazione->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cl->getClient()->getProfilo()->getFromF(i)->getPercorso())));
        tableWidgetFormazione->setItem(i,1,new QTableWidgetItem(QString::number(cl->getClient()->getProfilo()->getFromF(i)->getAnnoDiploma())));
    }

}

void ClientWindow::on_pushButtonAggiungiFormazione_clicked(){
    QString newFormazione=QString::number(cl->getClient()->getProfilo()->getSizeF());
    Formazione* aux=new Formazione(newFormazione.toStdString(),0);
    cl->getClient()->getProfilo()->addInF(*aux);
    loadFormazioneUtente();
}

void ClientWindow::on_pushButtonEliminaFormazione_clicked(){
    QTableWidgetItem * item= tableWidgetFormazione->currentItem();
    if(item){
        string formazione=tableWidgetFormazione->item(tableWidgetFormazione->currentRow(),0)->text().toStdString();
        for(int i=0;i<cl->getClient()->getProfilo()->getSizeF();++i){
            if(formazione==cl->getClient()->getProfilo()->getFromF(i)->getPercorso())
                cl->getClient()->getProfilo()->removeInF(i);
        }
        loadFormazioneUtente();
    }
    else{
        QMessageBox err;
        err.setText("Percorso non selezionato");
        err.exec();
    }
}

void ClientWindow::loadEsperienzeUtente(){
    tableWidgetEsperienze->clearContents();
    int num_rows=cl->getClient()->getProfilo()->getSizeE();
    tableWidgetEsperienze->setRowCount(num_rows);
    tableWidgetEsperienze->setColumnCount(3);
    for(int i=0; i<num_rows;++i){
        QDateEdit* inizio=new QDateEdit(tableWidgetEsperienze);
        inizio->setDisplayFormat("dd.MM.yyyy");
        QDateEdit* fine=new QDateEdit(tableWidgetEsperienze);
        fine->setDisplayFormat("dd.MM.yyyy");
        inizio->setDate(cl->getClient()->getProfilo()->getFromE(i)->getInizioEsp());
        fine->setDate(cl->getClient()->getProfilo()->getFromE(i)->getFineEsp());
        tableWidgetEsperienze->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cl->getClient()->getProfilo()->getFromE(i)->getEsperienza())));
        tableWidgetEsperienze->setCellWidget(i,1,inizio);
        tableWidgetEsperienze->setCellWidget(i,2,fine);
    }
}

void ClientWindow::on_pushButtonAggiungiEsperienze_clicked(){
    QString newEsperienza=QString::number(cl->getClient()->getProfilo()->getSizeE());
    QDate* inizio=new QDate();
    QDate* fine=new QDate();
    Esperienze* aux=new Esperienze(newEsperienza.toStdString(), *inizio, *fine );
    cl->getClient()->getProfilo()->addInE(*aux);
    loadEsperienzeUtente();
}

void ClientWindow::on_pushButtonEliminaEsperienze_clicked(){
    QTableWidgetItem * item= tableWidgetEsperienze->currentItem();
    if(item){
        string esperienza=tableWidgetEsperienze->item(tableWidgetEsperienze->currentRow(),0)->text().toStdString();
        for(int i=0;i<cl->getClient()->getProfilo()->getSizeE();++i){
            if(esperienza == cl->getClient()->getProfilo()->getFromE(i)->getEsperienza())
                cl->getClient()->getProfilo()->removeInE(i);
        }
        loadEsperienzeUtente();
    }
    else{
        QMessageBox err;
        err.setText("Esperienza non selezionata");
        err.exec();
    }
}

void ClientWindow::loadCompetenzeUtente(){
    tableWidgetCompetenze->clearContents();
    int num_rows=cl->getClient()->getProfilo()->getSizeC();
    tableWidgetCompetenze->setRowCount(num_rows);
    tableWidgetCompetenze->setColumnCount(2);
    for(int i=0; i<num_rows;++i){
        QComboBox* comboCompetenze= new QComboBox(tableWidgetCompetenze);
        for(int c=0;c<10;++c)
            comboCompetenze->insertItem(c,QString::number(c+1));
        tableWidgetCompetenze->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cl->getClient()->getProfilo()->getFromC(i)->getCompetenza())));
        int voto=cl->getClient()->getProfilo()->getFromC(i)->getVoto();
        comboCompetenze->setCurrentIndex(voto-1);
        tableWidgetCompetenze->setCellWidget(i,1,comboCompetenze);
    }
}

void ClientWindow::on_pushButtonAggiungiCompetenze_clicked(){
    QString newCompetenza=QString::number(cl->getClient()->getProfilo()->getSizeC());
    Competenze* aux=new Competenze(newCompetenza.toStdString(), 1);
    cl->getClient()->getProfilo()->addInC(*aux);
    loadCompetenzeUtente();
}

void ClientWindow::on_pushButtonEliminaCompetenze_clicked(){
    QTableWidgetItem * item= tableWidgetCompetenze->currentItem();
    if(item){
        string competenza=tableWidgetCompetenze->item(tableWidgetCompetenze->currentRow(),0)->text().toStdString();
        for(int i=0;i<cl->getClient()->getProfilo()->getSizeC();++i){
            if(competenza == cl->getClient()->getProfilo()->getFromC(i)->getCompetenza())
                cl->getClient()->getProfilo()->removeInC(i);
        }
        loadCompetenzeUtente();
    }
    else{
        QMessageBox err;
        err.setText("Argomento non selezionato");
        err.exec();
    }
}

void ClientWindow::loadLingueUtente(){
    tableWidgetLingue->clearContents();
    int num_rows=cl->getClient()->getProfilo()->getSizeL();
    tableWidgetLingue->setRowCount(num_rows);
    tableWidgetLingue->setColumnCount(2);
    for(int i=0; i<num_rows;++i){
        QComboBox* comboLingue= new QComboBox(tableWidgetLingue);
        comboLingue->insertItem(0,"Basic");
        comboLingue->insertItem(1,"Avanzato");
        comboLingue->insertItem(2,"Eccelente");
        comboLingue->insertItem(3,"Madre Lingua");
        tableWidgetLingue->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cl->getClient()->getProfilo()->getFromL(i)->getLingua())));
        QString livello=QString::fromStdString(cl->getClient()->getProfilo()->getFromL(i)->getLivello());
        if(livello=="Basic") comboLingue->setCurrentIndex(0);
        if(livello=="Avanzato") comboLingue->setCurrentIndex(1);
        if(livello=="Eccelente") comboLingue->setCurrentIndex(2);
        if(livello=="Madre Lingua") comboLingue->setCurrentIndex(3);
        tableWidgetLingue->setCellWidget(i,1,comboLingue);
    }
}

void ClientWindow::on_pushButtonAggiungiLingue_clicked(){
    QString newLingua=QString::number(cl->getClient()->getProfilo()->getSizeL());
    Lingue* aux=new Lingue(newLingua.toStdString(), "Basic");
    cl->getClient()->getProfilo()->addInL(*aux);
    loadLingueUtente();
}

void ClientWindow::on_pushButtonEliminaLingue_clicked(){
    QTableWidgetItem * item= tableWidgetLingue->currentItem();
    if(item){
        string lingua=tableWidgetLingue->item(tableWidgetLingue->currentRow(),0)->text().toStdString();
        for(int i=0;i<cl->getClient()->getProfilo()->getSizeL();++i){
            if(lingua== cl->getClient()->getProfilo()->getFromL(i)->getLingua())
                cl->getClient()->getProfilo()->removeInL(i);
        }
        loadLingueUtente();
    }
    else{
        QMessageBox err;
        err.setText("Lingua non selezionata");
        err.exec();
    }
}

QTreeWidgetItem* ClientWindow::addRoot(const QString &name){
    QTreeWidgetItem *itm= new QTreeWidgetItem(treeWidgetInfoContatto);
    itm->setText(0, name);
    treeWidgetInfoContatto->addTopLevelItem(itm);
    return itm;
}

void ClientWindow::addChild(QTreeWidgetItem *parent, const QString& name){
    QTreeWidgetItem *itm=new QTreeWidgetItem();
    itm->setText(0,name);
    parent->addChild(itm);
}

void ClientWindow::loadInfoContatto(Utente* aux){
    treeWidgetInfoContatto->clear();
    if(aux){
        QTreeWidgetItem* it=addRoot("Username");
        it->setExpanded(true);
        addChild(it,QString::fromStdString(aux->getUsername()));
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

void ClientWindow::on_listWidgetContatti_doubleClicked(QListWidgetItem *item){
    Utente *user=cl->getDB()->findU(item->text().toStdString());
    if(user)
        loadInfoContatto(user);
}

void ClientWindow::on_pushButtonEliminaContatto_clicked(){
    QListWidgetItem *item=listWidgetContatti->currentItem();
    if(item){
        cl->getClient()->removeContact(item->text().toStdString());
        for(int row=0; row<listWidgetContatti->count();++row)
            if(item->text()==listWidgetContatti->item(row)->text()){
                listWidgetContatti->removeItemWidget(listWidgetContatti->takeItem(row));
                listWidgetContatti->removeItemWidget(item);
                treeWidgetInfoContatto->clear();
            }
    }
    else{
        QMessageBox err;
        err.setText("Nessun contatto selezionato");
        err.exec();
    }
}

void ClientWindow::on_pushButtonRicercaContatti_clicked(){
    labelRicercaUser->setText("");
    listWidgetRicerca->clear();
    QList<QString> lista;
    QString u=lineEditRicercaUsername->text();
    Utente *ricerca=cl->getDB()->findU(u.toStdString());
    if(ricerca){
        cl->getClient()->userSearch(*(cl->getDB()),u.toStdString(), lista);
        labelRicercaUser->setText(u);
        for(int i=0; i<lista.size();++i){
            QListWidgetItem* item= new QListWidgetItem(lista.at(i));
            listWidgetRicerca->insertItem(i,item);
        }
    }
    else{
        QMessageBox err;
        err.setText("Non presente nel database");
        err.exec();
    }
}

void ClientWindow::on_pushButtonAggiungiContatto_clicked(){
    QString user= labelRicercaUser->text();
    bool presente=false;
    if(user!="" && user!=QString::fromStdString(cl->getClient()->getUsername())){
        for(int i=0; i<cl->getClient()->contactSize() && !presente;++i){
            if(cl->getClient()->getContact(i)->getContatto()==user.toStdString()){
                presente=true;
            }
        }
        if(presente){
            QMessageBox presente;
            presente.setText("Contatto già presente nella tua lista");
            presente.exec();
        }
        else{
            Rete* r=new Rete(user.toStdString());
            cl->getClient()->addContact(*r);
            loadContattiUtente();
            QMessageBox ok;
            ok.setText("Contatto Aggiunto");
            ok.exec();
        }
    }
    else{
        QMessageBox err;
        err.setText("Nessun contatto da aggiungere");
        err.exec();
    }
}

void ClientWindow::on_pushButtonEsciSalva_clicked(){
    saveModificheCompetenze();
    saveModificheEsperienze();
    saveModificheFormazione();
    saveModificheLingue();
    saveModificheInfoPersonali();
    cl->getDB()->save();
    this->close();
}

void ClientWindow::saveModificheCompetenze()const{
    for(int row=0; row < tableWidgetCompetenze->rowCount();++row){
        QTableWidgetItem* item=tableWidgetCompetenze->item(row,0);
        QComboBox* voto=(QComboBox*)tableWidgetCompetenze->cellWidget(row,1);
        cl->getClient()->getProfilo()->getFromC(row)->setCompetenza(item->text().toStdString());
        cl->getClient()->getProfilo()->getFromC(row)->setVoto(voto->currentText().toInt());
    }
}

void ClientWindow::saveModificheEsperienze()const{
    for(int row=0; row<tableWidgetEsperienze->rowCount();++row){
        QTableWidgetItem* item=tableWidgetEsperienze->item(row,0);
        QDateEdit * i=(QDateEdit*)tableWidgetEsperienze->cellWidget(row,1);
        QDateEdit * f=(QDateEdit*)tableWidgetEsperienze->cellWidget(row,2);
        cl->getClient()->getProfilo()->getFromE(row)->setEsperienza(item->text().toStdString());
        cl->getClient()->getProfilo()->getFromE(row)->setInizioEsp(i->date());
        cl->getClient()->getProfilo()->getFromE(row)->setFineEsp(f->date());
    }
}

void ClientWindow::saveModificheFormazione()const{
    for(int row=0; row < tableWidgetFormazione->rowCount();++row){
        QTableWidgetItem* item=tableWidgetFormazione->item(row,0);
        QTableWidgetItem* anno=tableWidgetFormazione->item(row,1);
        cl->getClient()->getProfilo()->getFromF(row)->setPercorso(item->text().toStdString());
        cl->getClient()->getProfilo()->getFromF(row)->setAnnoDiploma(anno->text().toInt());
    }
}

void ClientWindow::saveModificheLingue()const{
    for(int row=0; row< tableWidgetLingue->rowCount();++row){
        QTableWidgetItem* item=tableWidgetLingue->item(row,0);
        QComboBox* livello=(QComboBox*)tableWidgetLingue->cellWidget(row,1);
        cl->getClient()->getProfilo()->getFromL(row)->setLingua(item->text().toStdString());
        cl->getClient()->getProfilo()->getFromL(row)->setLivello(livello->currentText().toStdString());
    }
}

void ClientWindow::saveModificheInfoPersonali()const{
    QString n= lineEditNome->text();
    QString c= lineEditCognome->text();
    QDate date= dateEditNascita->date();
    QString d= textEditDescrizione->toPlainText();
    cl->getClient()->getInfo()->setNome(n.toStdString());
    cl->getClient()->getInfo()->setCognome(c.toStdString());
    cl->getClient()->getInfo()->setAnnoNascita(date);
    cl->getClient()->getInfo()->setDescrizione(d.toStdString());
}
