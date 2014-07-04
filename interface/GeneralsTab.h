#ifndef GENERALSTAB_H
#define GENERALSTAB_H

#include <QtWidgets>
#include "implementation/DragonForce.h"

class GeneralsTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralsTab(QWidget* parent = 0);
    explicit GeneralsTab(DragonForce* df, QWidget* parent = 0);
             ~GeneralsTab(void);

private slots:
    void loadGeneralsTabData(const int index = 0);

private:
    void initComboBoxes      (void);
    void setLocationControls (const int index = 0);
    void showDivisionInfo    (const bool show, const int index);

    DragonForce* dr;

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
    QCheckBox* searchFortifyCheckBox;

    QPushButton* ownerSetButton;
    QPushButton* levelSetButton;
    QPushButton* expSetButton;
    QPushButton* currHpSetButton;
    QPushButton* maxHpSetButton;
    QPushButton* currMpSetButton;
    QPushButton* maxMpSetButton;
    QPushButton* strSetButton;
    QPushButton* comSetButton;
    QPushButton* intSetButton;
    QPushButton* livesSetButton;
    QPushButton* loyaltySetButton;
    QPushButton* winsSetButton;
    QPushButton* lossesSetButton;
    QPushButton* meritsSetButton;
    QPushButton* escapeSetButton;
    QPushButton* spellTierSetButton;
    QPushButton* equippedItemSetButton;
    QPushButton* searchFortifySetButton;

//weaknesses
    QLineEdit* troopWeakEditBox;
    QLineEdit* swordWeakEditBox;
    QLineEdit* iceWeakEditBox;
    QLineEdit* fireWeakEditBox;
    QLineEdit* lightWeakEditBox;
    QLineEdit* darkWeakEditBox;

    QPushButton* troopAttackSetButton;
    QPushButton* swordMagicSetButton;
    QPushButton* iceMagicSetButton;
    QPushButton* fireMagicSetButton;
    QPushButton* lightMagicSetButton;
    QPushButton* darkMagicSetButton;

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

    QPushButton* troopTypeSetButton;
    QPushButton* troopAmountSetButton;
    QPushButton* soldierMedalsSetButton;
    QPushButton* cavalryMedalsSetButton;
    QPushButton* mageMedalsSetButton;
    QPushButton* samuraiMedalsSetButton;
    QPushButton* archerMedalsSetButton;
    QPushButton* monkMedalsSetButton;
    QPushButton* harpyMedalsSetButton;
    QPushButton* beastMedalsSetButton;
    QPushButton* dragonMedalsSetButton;
    QPushButton* zombieMedalsSetButton;

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

    QPushButton* castleLocSetButton;
    QPushButton* hiddenLocSetButton;

//unknowns
    QLineEdit* nActionEditBox;
    QLineEdit* bActionEditBox;
    QLineEdit* btlActionEditBox;
    QLineEdit* moralEditBox;
    QLineEdit* warlikeEditBox;
    QLineEdit* negoEditBox;
    QLineEdit* atkPlusEditBox;
    QLineEdit* defPlusEditBox;

    QPushButton* nActionSetButton;
    QPushButton* bActionSetButton;
    QPushButton* btlActionSetButton;
    QPushButton* moralSetButton;
    QPushButton* warlikeSetButton;
    QPushButton* negoSetButton;
    QPushButton* atkPlusSetButton;
    QPushButton* defPlusSetButton;
};

#endif
