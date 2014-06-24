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

    layout = new QGridLayout(this);
    layout->addWidget(dfTab);
}

DFeditGUI::~DFeditGUI(void)
{
    
}
