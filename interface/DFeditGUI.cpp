#include "DFeditGUI.h"

DFeditGUI::DFeditGUI(QWidget* parent)
    : QMainWindow(parent)
{
    parentTab = new QTabWidget;
    parentTab->addTab(new GeneralsTab(), tr("Generals"));
    parentTab->addTab(new CastlesTab(), tr("Castles"));
    parentTab->addTab(new DivisionsTab(), tr("Divisions"));
    parentTab->addTab(new KingdomsTab(), tr("Kingdoms"));
    parentTab->addTab(new MassEditTab(), tr("Mass Editing"));

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(parentTab);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    
    setWindowTitle(tr("Dragon Force Editor"));
}

DFeditGUI::~DFeditGUI()
{

}
