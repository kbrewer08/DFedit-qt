#ifndef GENERALSTAB_H
#define GENERALSTAB_H

#include "DFeditGUI.h"

class GeneralsTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralsTab(QWidget* parent = 0);
             ~GeneralsTab();

private:
    QComboBox* genNamesComboBox;
    QComboBox* ownerNamesComboBox;
    
    
    QLineEdit* winsEditBox;
    QLineEdit* lossesEditBox;
    
};

#endif
