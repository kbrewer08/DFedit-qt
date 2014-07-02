#include "DFeditGUI.h"

DFeditGUI::DFeditGUI(QString inFile, QWidget* parent)
    : QWidget(parent)
{
    if(!inFile.isEmpty()){
        fileName = inFile;
        dr.setFileName(inFile.toStdString());

        dr.readFile();      //read the save file
        dr.initGenerals();  //create the generals array
        dr.setMonarch();    //find who the player's monarch is
        dr.initCastles();   //create the castles array
        dr.initDivisions(); //create the divisions array
        dr.initItemInv();   //create the item inventory from domestic affairs
        dr.initKingdoms();  //fill in the status of each kingdom
    }

    generalsTab  = new GeneralsTab();
    castlesTab   = new CastlesTab();
    divisionsTab = new DivisionsTab();
    massEditTab  = new MassEditTab();
    itemsTab     = new ItemsTab();
    kingdomsTab  = new KingdomsTab();

    dfTab = new QTabWidget;
    dfTab->addTab(generalsTab,  tr("Generals"));
    dfTab->addTab(castlesTab,   tr("Castles"));
    dfTab->addTab(divisionsTab, tr("Divisions"));
    dfTab->addTab(massEditTab,  tr("Mass Editing"));
    dfTab->addTab(itemsTab,     tr("Items"));
    dfTab->addTab(kingdomsTab,  tr("Kingdoms"));

    layout = new QGridLayout(this);
    layout->addWidget(dfTab);

    if(inFile.isEmpty()){
        generalsTab->setVisible(false);
        castlesTab->setVisible(false);
        divisionsTab->setVisible(false);
        massEditTab->setVisible(false);
        itemsTab->setVisible(false);
        kingdomsTab->setVisible(false);
    }

}

DFeditGUI::~DFeditGUI(void)
{
    
}

QString DFeditGUI::getPlayerName(void)
{
    return QString(QString::fromStdString(dr.getPlayerName()));
}
