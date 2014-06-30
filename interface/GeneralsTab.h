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
    QGroupBox* basicsGroupBox;
    QGroupBox* troopsGroupBox;
    QGroupBox* weaknessesGroupBox;
    QGroupBox* statusGroupBox;
    QGroupBox* locationGroupBox;
    QGroupBox* unknownsGroupBox;

//basics
    QComboBox* genNamesComboBox;
    QComboBox* ownerNamesComboBox;
    QLineEdit* levelEditBox;
    QLineEdit* expEditBox;
    QLineEdit* currHpEditBox;
    QLineEdit* maxHpEditBox;
    QLineEdit* currMpEditBox;
    QLineEdit* maxMpEditBox;
    QLineEdit* strEditBox;
    QLineEdit* comEditBox;
    QLineEdit* intEditBox;
    QLineEdit* livesEditBox;
    QLineEdit* loyaltyEditBox;
    QLineEdit* winsEditBox;
    QLineEdit* lossesEditBox;
    QLineEdit* meritsEditBox;
    QLineEdit* escapeEditBox;
    QComboBox* spellTierComboBox;
    QComboBox* equippedItemComboBox;
    QCheckBox* SearchFortifyCheckBox;

//weaknesses
    QLineEdit* troopWeakEditBox;
    QLineEdit* swordWeakEditBox;
    QLineEdit* iceWeakEditBox;
    QLineEdit* fireWeakEditBox;
    QLineEdit* lightWeakEditBox;
    QLineEdit* darkWeakEditBox;
    
//status
    QLabel* indexValue;
    QLabel* portraitValue;
    QLabel* classValue;
    QLabel* statusValue;
    QLabel* hospitalValue;

//troops
    QComboBox* troopTypeComboBox;
    QLineEdit* troopAmountEditBox;
    QComboBox* soldierMedalsComboBox;
    QComboBox* cavalryMedalsComboBox;
    QComboBox* mageMedalsComboBox;
    QComboBox* samuraiMedalsComboBox;
    QComboBox* archerMedalsComboBox;
    QComboBox* monkMedalsComboBox;
    QComboBox* harpyMedalsComboBox;
    QComboBox* beastMedalsComboBox;
    QComboBox* dragonMedalsComboBox;
    QComboBox* zombieMedalsComboBox;
};

#endif
