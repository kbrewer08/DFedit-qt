#include "MainContentHolder.h"
#include <string>

MainContentHolder::MainContentHolder(QWidget* parent)
    : QMainWindow(parent)
{
    mainTab = new QTabWidget;
    mainTab->addTab(new DFeditGUI(""), tr("DR_FORCE_01"));
    mainTab->setMovable(true);
    
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(mainTab);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    createMenuBar();

    resize(900, 600);
    
    setWindowTitle(getDfeVersion().c_str());
}

MainContentHolder::~MainContentHolder(void)
{
    
}

void MainContentHolder::addNewTab(QString inFile)
{
    const char* tabName = "";
    
    mainTab->addTab(new DFeditGUI(inFile), tr(tabName));
    mainTab->setTabsClosable(true);
}

std::string MainContentHolder::getDfeVersion(void)
{
    std::string version = "Dragon Force Edit ";
    version.append(DFEDIT_VERSION);
    
    return version;
}

void MainContentHolder::createMenuBar(void)
{
    QAction*   openAction   = new QAction(tr("&Open a save file..."), this);
    QShortcut* openShortCut = new QShortcut(QKeySequence("Ctrl+O"), this);
    QAction*   quitAction   = new QAction(tr("&Quit"), this);
    QShortcut* quitShortCut = new QShortcut(QKeySequence("Ctrl+Q"), this);

    QAction* aboutAction = new QAction(tr("A&bout"), this);
    
    QMenu* fileMenu  = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(quitAction);
    
    connect(openAction, SIGNAL(triggered(bool)), this, SLOT(openFile(void)));
    connect(openShortCut, SIGNAL(activated()), this, SLOT(openFile(void)));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close(void)));
    connect(quitShortCut, SIGNAL(activated()), this, SLOT(close(void)));
    
    QMenu* aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutAction);

    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(aboutDFedit()));

}

QString MainContentHolder::openFile(void)
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open the SSF save file"),
                                                    "", // <-- this empty string means no specific directory is selected to be shown by default
                                                    tr(".bin files (*.bin);;All files (*.*)"));

    addNewTab(fileName);

    return fileName;
}

void MainContentHolder::aboutDFedit(void)
{
    std::string aboutTitle = "About ";
    aboutTitle.append(getDfeVersion());

    QMessageBox::about(this, aboutTitle.c_str(),
                       tr("<p align=center><b>Dragon Force Edit</b><br />"
                          "by KB<br />"
                          "DragonForceEdit@gmail.com</p>"
                          "<p>Dragon Force Edit is a utility that lets you change just about "
                          "anything in your Dragon Force save files. Currently, the save "
                          "files that it works with are those created by the SSF emulator "
                          "with the Hook Backup Library option checked.</p>"
                          ));
}
