#include "MainContentHolder.h"
#include <string>

MainContentHolder::MainContentHolder(QWidget* parent)
    : QMainWindow(parent)
{
    mainTab = new QTabWidget;
    mainTab->addTab(new DFeditGUI(""), tr("No files open"));
    mainTab->setMovable(true);

    //closing tabs will only work if more than 1 is open    
    connect(mainTab, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

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
    if(inFile == NULL){
        return;
    }

    //if blank tab open, close it, so real one can be opened
    if(mainTab->count() == 1){
        mainTab->removeTab(0);
    }

    mainTab->addTab(new DFeditGUI(inFile), tr(""));            //can't set tab name yet
    mainTab->setTabText(mainTab->count() - 1, "New Tab text"); //save file loaded, set tab name now
    mainTab->setCurrentIndex(mainTab->count() - 1);            //select the new tab/file
    mainTab->setTabsClosable(true);                            //real file open, set tabs closable

    return;
}

std::string MainContentHolder::getDfeVersion(void)
{
    std::string version = "Dragon Force Edit ";
    version.append(DFEDIT_VERSION);
    
    return version;
}

void MainContentHolder::createMenuBar(void)
{

    QMenu* fileMenu  = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(tr("&Open a save file..."), this, SLOT(openFile()), QKeySequence(tr("Ctrl+O")));
    fileMenu->addAction(tr("&Quit"), this, SLOT(close()), QKeySequence(tr("Ctrl+Q")));
    fileMenu->addAction(tr("&Reload"), this, SLOT(reloadTab()), QKeySequence(tr("Ctrl+R")));

    QAction* aboutAction = new QAction(tr("A&bout"), this);

    QMenu* aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutAction);

    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(aboutDFedit()));

    return;
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

    return;
}

void MainContentHolder::closeTab(int tabNumber)
{
    mainTab->removeTab(tabNumber);
    if(!mainTab->count()){ //when last tab closed, reopen a blank one
        mainTab->addTab(new DFeditGUI(""), tr("No files open"));
        mainTab->setTabsClosable(false);
    }

    return;
}

void MainContentHolder::reloadTab(void)
{
    QMessageBox::about(this, "Reload action", "The reload button works.");

    return;
}
