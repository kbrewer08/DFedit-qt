#include "DFeditGUI.h"

DFeditGUI::DFeditGUI(QWidget* parent)
    : QMainWindow(parent)
{
    parentTab = new QTabWidget;
    parentTab->addTab(new GeneralsTab(),  tr("Generals"));
    parentTab->addTab(new CastlesTab(),   tr("Castles"));
    parentTab->addTab(new DivisionsTab(), tr("Divisions"));
    parentTab->addTab(new MassEditTab(),  tr("Mass Editing"));
    parentTab->addTab(new KingdomsTab(),  tr("Kingdoms"));
    parentTab->addTab(new ItemsTab(),     tr("Items"));
    parentTab->setTabsClosable(false);

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(parentTab);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    createMenuBar();

    resize(900, 600);
    setWindowTitle(tr("Dragon Force Editor"));
}

DFeditGUI::~DFeditGUI(void)
{

}

void DFeditGUI::createMenuBar(void)
{
    QAction* openAction = new QAction(tr("&Open a save file..."), this);
    QAction* quitAction = new QAction(tr("&Quit"), this);
    
    QMenu* fileMenu  = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(quitAction);
    
    QMenu* aboutMenu = menuBar()->addMenu(tr("&About"));
}
