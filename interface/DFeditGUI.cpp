#include "DFeditGUI.h"

DFeditGUI::DFeditGUI(QString inFile, QWidget* parent)
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

    if(!inFile.isEmpty()){
        dr.drFileName      = inFile.toStdString();
        dr.fr.savefileName = inFile.toStdString();
        dr.fw.savefileName = inFile.toStdString();

        dr.fr.readFile();   //read the save file
        dr.initGenerals();  //create the generals array
        dr.setMonarch();    //find who the player's monarch is
        dr.initCastles();   //create the castles array
        dr.initDivisions(); //create the divisions array
        dr.initItemInv();   //create the item inventory from domestic affairs
        dr.initKingdoms();  //fill in the status of each kingdom
    }
}

DFeditGUI::~DFeditGUI(void)
{
    
}

QString DFeditGUI::getPlayerName(void)
{
    return QString(dr.getPlayerName().c_str());
}
