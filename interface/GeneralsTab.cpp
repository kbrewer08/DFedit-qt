#include "DFeditGUI.h"

GeneralsTab::GeneralsTab(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* mainLayout = new QGridLayout(this);
    QGridLayout* column1    = new QGridLayout();
    QGridLayout* column2    = new QGridLayout();
    
    mainLayout->addLayout(column1, 0, 0);
    mainLayout->addLayout(column2, 0, 2);
    mainLayout->setColumnMinimumWidth(1, 20);
    mainLayout->setColumnMinimumWidth(3, 20);

    genNamesComboBox = new QComboBox();
    ownerNamesComboBox = new QComboBox();
    
    winsEditBox = new QLineEdit();
    lossesEditBox = new QLineEdit();
    
    for(int i = 0; i < 171; i++){
        genNamesComboBox->addItem(QString(dr.getGeneralName(i).c_str()));
        ownerNamesComboBox->addItem(QString(dr.getGeneralName(i).c_str()));
    }
    column1->addWidget(new QLabel("Current General"), 0, 0);
    column1->addWidget(genNamesComboBox, 0, 1);
    column1->addWidget(new QLabel("Owner"), 2, 0);
    column1->addWidget(ownerNamesComboBox, 2, 1);
    
    
    
    column2->addWidget(new QLabel("Wins"), 0, 0);
    column2->addWidget(winsEditBox, 0, 1);
    column2->addWidget(new QLabel("Losses"), 1, 0);
    column2->addWidget(lossesEditBox, 1, 1);
}

GeneralsTab::~GeneralsTab()
{
    
}
