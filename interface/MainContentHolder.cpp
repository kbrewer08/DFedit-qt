#include "MainContentHolder.h"
#include <string>

MainContentHolder::MainContentHolder(QWidget* parent)
    : QMainWindow(parent)
{
    mainTab = new QTabWidget;
    mainTab->addTab(new DFeditGUI(), tr("DR_FORCE_01"));
    mainTab->setTabsClosable(false);
    
//    QGridLayout* layout = new QGridLayout;
//    layout->addWidget(mainTab);

//    QWidget* centralWidget = new QWidget;
//    centralWidget->setLayout(layout);
    setCentralWidget(mainTab);
    createMenuBar();

    resize(900, 600);
    
    std::string versionString = "Dragon Force Editor ";
    versionString.append(DFEDIT_VERSION);
    setWindowTitle(tr(versionString.c_str()));
}

MainContentHolder::~MainContentHolder(void)
{
    
}

void MainContentHolder::createMenuBar(void)
{
    QAction* openAction = new QAction(tr("&Open a save file..."), this);
    QAction* quitAction = new QAction(tr("&Quit"), this);

    QAction* aboutAction = new QAction(tr("&About"), this);
    
    QMenu* fileMenu  = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(quitAction);
    
    QMenu* aboutMenu = menuBar()->addMenu(tr("A&bout"));
    aboutMenu->addAction(aboutAction);
}
