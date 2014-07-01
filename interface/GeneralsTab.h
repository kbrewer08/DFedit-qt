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
    QGroupBox* locFixedGroupBox;
    QGroupBox* divisionGroupBox;
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

//location edit
    QGridLayout*  divisionStatusLayout;
    QComboBox*    castleLocComboBox;
    QComboBox*    hiddenLocComboBox;
    QRadioButton* castleLocRadioButton;
    QRadioButton* hiddenLocRadioButton;
    QRadioButton* divisionLocRadioButton;
    QLabel*       divRulerLabel;
    QLabel*       divRulerValue;
    QLabel*       divLeaderLabel;
    QLabel*       divLeaderValue;
    QLabel*       divXLabel;
    QLabel*       divXValue;
    QLabel*       divYLabel;
    QLabel*       divYValue;
    QLabel*       divOriginLabel;
    QLabel*       divOriginValue;
    QLabel*       divGoalLabel;
    QLabel*       divGoalValue;
    QLabel*       divPrevLabel;
    QLabel*       divPrevValue;
    QLabel*       divNextLabel;
    QLabel*       divNextValue;
    QLabel*       divNumberLabel;
    QLabel*       divNumberValue;
    QLabel*       divStatusLabel;
    QLabel*       divStatusValue;
    QLabel*       divTroopsLabel;
    QLabel*       divTroopsValue;
    QLabel*       divMembersLabel;
    QLabel*       divMembersValue;
    QLabel*       divCaptivesLabel;
    QLabel*       divCaptivesValue;

//unknowns
    QLineEdit* nActionEditBox;
    QLineEdit* bActionEditBox;
    QLineEdit* btlActionEditBox;
    QLineEdit* moralEditBox;
    QLineEdit* warlikeEditBox;
    QLineEdit* negoEditBox;
    QLineEdit* atkPlusEditBox;
    QLineEdit* defPlusEditBox;
};

#endif
