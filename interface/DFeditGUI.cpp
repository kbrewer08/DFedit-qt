#include "DFeditGUI.h"

DFeditGUI::DFeditGUI(QWidget* parent)
    : QWidget(parent)
{
    dfTab = new QTabWidget;
    dfTab->addTab(new GeneralsTab(),  tr("Generals"));
    dfTab->addTab(new CastlesTab(),   tr("Castles"));
    dfTab->addTab(new DivisionsTab(), tr("Divisions"));
    dfTab->addTab(new MassEditTab(),  tr("Mass Editing"));
    dfTab->addTab(new KingdomsTab(),  tr("Kingdoms"));
    dfTab->addTab(new ItemsTab(),     tr("Items"));
    dfTab->setTabsClosable(false);

    layout = new QGridLayout;
    layout->addWidget(dfTab);
    this->setLayout(layout);
}

DFeditGUI::~DFeditGUI(void)
{
    
}
