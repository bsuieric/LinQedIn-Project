#include "mainwindow.h"
#include"QFileDialog"
#include"QMessageBox"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    db=new DB;
    centralWidget = new QWidget(this);
    widget = new QWidget(centralWidget);
    groupLayout = new QVBoxLayout(widget);
    adminBox = new QGroupBox(widget);
    verticalLayout_4 = new QVBoxLayout(adminBox);
    admin = new QPushButton(adminBox);
    clientBox = new QGroupBox(widget);
    verticalLayout_3 = new QVBoxLayout(clientBox);
    boxLayout = new QVBoxLayout();
    lineEdit = new QLineEdit(clientBox);
    client = new QPushButton(clientBox);
    menuBar = new QMenuBar(this);
    mainToolBar = new QToolBar(this);
    statusBar = new QStatusBar(this);

    setupView();

    connect(admin, SIGNAL(clicked()), this, SLOT(admin_clicked()));
    connect(client,SIGNAL(clicked()),this,SLOT(client_clicked()));
}

MainWindow::~MainWindow()
{}

void MainWindow::setupView(){
    resize(400, 300);

    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    widget->setObjectName(QStringLiteral("widget"));
    groupLayout->setObjectName(QStringLiteral("groupLayout"));
    adminBox->setObjectName(QStringLiteral("adminBox"));
    admin->setObjectName(QStringLiteral("admin"));
    clientBox->setObjectName(QStringLiteral("clientBox"));
    verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
    boxLayout->setObjectName(QStringLiteral("boxLayout"));
    lineEdit->setObjectName(QStringLiteral("lineEdit"));
    client->setObjectName(QStringLiteral("client"));
    menuBar->setObjectName(QStringLiteral("menuBar"));
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    statusBar->setObjectName(QStringLiteral("statusBar"));
    verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));

    widget->setGeometry(QRect(96, 30, 191, 176));

    groupLayout->setSpacing(6);
    groupLayout->setContentsMargins(11, 11, 11, 11);
    groupLayout->setContentsMargins(0, 0, 0, 0);
    groupLayout->addWidget(adminBox);
    groupLayout->addWidget(clientBox);

    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setContentsMargins(11, 11, 11, 11);
    verticalLayout_4->addWidget(admin);

    setCentralWidget(centralWidget);
    setMenuBar(menuBar);
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    insertToolBarBreak(mainToolBar);
    setStatusBar(statusBar);

    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setContentsMargins(11, 11, 11, 11);
    verticalLayout_3->addLayout(boxLayout);

    boxLayout->setSpacing(6);
    boxLayout->addWidget(lineEdit);
    boxLayout->addWidget(client);

    lineEdit->setText(QStringLiteral("Inserisci username"));
    lineEdit->setDragEnabled(false);
    lineEdit->setReadOnly(false);
    lineEdit->setClearButtonEnabled(true);

    adminBox->raise();
    clientBox->raise();
    adminBox->raise();

    menuBar->setGeometry(QRect(0, 0, 400, 22));
    statusBar->showMessage("Programmazione ad Oggetti2014/2015@UniPD Suierica");

    setWindowTitle("LinQedIn");
    adminBox->setTitle("Lato Amministratore");
    clientBox->setTitle("Lato Cliente");
    client->setText("Accedi");
    admin->setText("Accedi");
    lineEdit->setInputMask(QString());
}

DB* MainWindow::getDB()const{
    return db;
}

void MainWindow::admin_clicked(){
    LinQedInAdmin* admin=new LinQedInAdmin(db);
    AdminWindow *admWindow=new AdminWindow(admin);
    admWindow->exec();
}

void MainWindow::client_clicked(){
    QString username = lineEdit->text();
    Utente* ut= db->findU(username.toStdString());
    if(ut){
        LinQedInClient* client=new LinQedInClient(db, ut);
        ClientWindow* clientWindow=new ClientWindow(client);
        clientWindow->exec();
    }
    else{
        QMessageBox err;
        err.setText("Inserisci un Username valido");
        err.exec();
    }
}
