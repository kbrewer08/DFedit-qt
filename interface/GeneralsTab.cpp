#include "DFeditGUI.h"

GeneralsTab::GeneralsTab(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* mainLayout     = new QGridLayout(this);
    QGridLayout* basicsLayout   = new QGridLayout();
    QGridLayout* weaknessLayout = new QGridLayout();
    QGridLayout* statusLayout   = new QGridLayout();
    QGridLayout* troopsLayout   = new QGridLayout();
    QGridLayout* locationLayout = new QGridLayout();
    QGridLayout* unknownsLayout = new QGridLayout();

    basicsGroupBox     = new QGroupBox(tr("Basics"), this);
    troopsGroupBox     = new QGroupBox(tr("Medals"));
    weaknessesGroupBox = new QGroupBox(tr("Weakness Against"));
    locationGroupBox   = new QGroupBox(tr("Location Editing"));
    statusGroupBox     = new QGroupBox(tr("Status"));
    unknownsGroupBox   = new QGroupBox(tr("Unknown Effects"));

//basics area
    genNamesComboBox       = new QComboBox();
    ownerNamesComboBox     = new QComboBox();
    levelEditBox           = new QLineEdit();
    expEditBox             = new QLineEdit();
    currHpEditBox          = new QLineEdit();
    maxHpEditBox           = new QLineEdit();
    currMpEditBox          = new QLineEdit();
    maxMpEditBox           = new QLineEdit();
    strEditBox             = new QLineEdit();
    comEditBox             = new QLineEdit();
    intEditBox             = new QLineEdit();
    livesEditBox           = new QLineEdit();
    loyaltyEditBox         = new QLineEdit();
    winsEditBox            = new QLineEdit();
    lossesEditBox          = new QLineEdit();
    meritsEditBox          = new QLineEdit();
    escapeEditBox          = new QLineEdit();
    spellTierComboBox      = new QComboBox();
    equippedItemComboBox   = new QComboBox();
    SearchFortifyCheckBox  = new QCheckBox(tr("Searched/Fortified"));

    for(int i = 0; i < 171; i++){
        genNamesComboBox->addItem(QString(dr.getGeneralName(i).c_str()));
        ownerNamesComboBox->addItem(QString(dr.getGeneralName(i).c_str()));
    }
    basicsLayout->addWidget(new QLabel("Current General"), 0, 0);
    basicsLayout->addWidget(genNamesComboBox, 0, 1);
    basicsLayout->addWidget(new QLabel("Owner"), 1, 0);
    basicsLayout->addWidget(ownerNamesComboBox, 1, 1);
    basicsLayout->addWidget(new QLabel("Level"), 2, 0);
    basicsLayout->addWidget(levelEditBox, 2, 1);
    basicsLayout->addWidget(new QLabel("Experience"), 3, 0);
    basicsLayout->addWidget(expEditBox, 3, 1);
    basicsLayout->addWidget(new QLabel("HP"), 4, 0);
    basicsLayout->addWidget(currHpEditBox, 4, 1);
    basicsLayout->addWidget(new QLabel("MP"), 5, 0);
    basicsLayout->addWidget(currMpEditBox, 5, 1);
    basicsLayout->addWidget(new QLabel("Strength"), 6, 0);
    basicsLayout->addWidget(strEditBox, 6, 1);
    basicsLayout->addWidget(new QLabel("Command"), 7, 0);
    basicsLayout->addWidget(comEditBox, 7, 1);
    basicsLayout->addWidget(new QLabel("Intelligence"), 8, 0);
    basicsLayout->addWidget(intEditBox, 8, 1);

    basicsLayout->addWidget(new QLabel("Lives"), 0, 3);
    basicsLayout->addWidget(livesEditBox, 0, 4);
    basicsLayout->addWidget(new QLabel("Loyalty"), 1, 3);
    basicsLayout->addWidget(loyaltyEditBox, 1, 4);
    basicsLayout->addWidget(new QLabel("Wins"), 2, 3);
    basicsLayout->addWidget(winsEditBox, 2, 4);
    basicsLayout->addWidget(new QLabel("Losses"), 3, 3);
    basicsLayout->addWidget(lossesEditBox, 3, 4);
    basicsLayout->addWidget(new QLabel("Merits"), 4, 3);
    basicsLayout->addWidget(meritsEditBox, 4, 4);
    basicsLayout->addWidget(new QLabel("Escape"), 5, 3);
    basicsLayout->addWidget(escapeEditBox, 5, 4);
    basicsLayout->addWidget(new QLabel("Spell Tier"), 6, 3);
    basicsLayout->addWidget(spellTierComboBox, 6, 4);
    basicsLayout->addWidget(new QLabel("Equipped Item"), 7, 3);
    basicsLayout->addWidget(equippedItemComboBox, 7, 4);
    basicsLayout->addWidget(SearchFortifyCheckBox, 8, 3);

    basicsLayout->setRowStretch(1000, 1000);
    basicsLayout->setColumnMinimumWidth(2, 30);
    basicsGroupBox->setLayout(basicsLayout);
    mainLayout->addWidget(basicsGroupBox, 0, 0);

//weaknesses area
    troopWeakEditBox = new QLineEdit();
    swordWeakEditBox = new QLineEdit();
    iceWeakEditBox   = new QLineEdit();
    fireWeakEditBox  = new QLineEdit();
    lightWeakEditBox = new QLineEdit();
    darkWeakEditBox  = new QLineEdit();

    weaknessLayout->addWidget(new QLabel("Troop Attacks"), 0, 0);
    weaknessLayout->addWidget(troopWeakEditBox, 0, 1);
    weaknessLayout->addWidget(new QLabel("Sword Magic"), 1, 0);
    weaknessLayout->addWidget(swordWeakEditBox, 1, 1);
    weaknessLayout->addWidget(new QLabel("Ice Magic"), 2, 0);
    weaknessLayout->addWidget(iceWeakEditBox, 2, 1);
    weaknessLayout->addWidget(new QLabel("Fire Magic"), 3, 0);
    weaknessLayout->addWidget(fireWeakEditBox, 3, 1);
    weaknessLayout->addWidget(new QLabel("Light Magic"), 4, 0);
    weaknessLayout->addWidget(lightWeakEditBox, 4, 1);
    weaknessLayout->addWidget(new QLabel("Dark Magic"), 5, 0);
    weaknessLayout->addWidget(darkWeakEditBox, 5, 1);

    weaknessLayout->setRowStretch(1000, 1000);
    weaknessesGroupBox->setLayout(weaknessLayout);
    mainLayout->addWidget(weaknessesGroupBox, 0, 1);

//status area
    indexValue    = new QLabel(tr("place holder"));
    portraitValue = new QLabel(tr("place holder"));
    classValue    = new QLabel(tr("place holder"));
    statusValue   = new QLabel(tr("place holder"));
    hospitalValue = new QLabel(tr("place holder"));

    statusLayout->addWidget(new QLabel(tr("Index: ")), 0, 0);
    statusLayout->addWidget(indexValue, 0, 1);
    statusLayout->addWidget(new QLabel(tr("Portrait: ")), 1, 0);
    statusLayout->addWidget(portraitValue, 1, 1);
    statusLayout->addWidget(new QLabel(tr("Class: ")), 2, 0);
    statusLayout->addWidget(classValue, 2, 1);
    statusLayout->addWidget(new QLabel(tr("Status: ")), 3, 0);
    statusLayout->addWidget(statusValue, 3, 1);
    statusLayout->addWidget(new QLabel(tr("Hospital: ")), 4, 0);
    statusLayout->addWidget(hospitalValue, 4, 1);

    statusLayout->setRowStretch(1000, 1000);
    statusGroupBox->setLayout(statusLayout);
    mainLayout->addWidget(statusGroupBox, 0, 2);

//troops area
    troopTypeComboBox     = new QComboBox();
    troopAmountEditBox    = new QLineEdit();
    soldierMedalsComboBox = new QComboBox();
    cavalryMedalsComboBox = new QComboBox();
    mageMedalsComboBox    = new QComboBox();
    samuraiMedalsComboBox = new QComboBox();
    archerMedalsComboBox  = new QComboBox();
    monkMedalsComboBox    = new QComboBox();
    harpyMedalsComboBox   = new QComboBox();
    beastMedalsComboBox   = new QComboBox();
    dragonMedalsComboBox  = new QComboBox();
    zombieMedalsComboBox  = new QComboBox();

    troopsLayout->addWidget(new QLabel(tr("Troop Type")), 0, 0);
    troopsLayout->addWidget(troopTypeComboBox, 0, 1);
    troopsLayout->addWidget(new QLabel(tr("# of Troops")), 1, 0);
    troopsLayout->addWidget(troopAmountEditBox, 1, 1);
    troopsLayout->addWidget(new QLabel(tr("Soldier")), 2, 0);
    troopsLayout->addWidget(soldierMedalsComboBox, 2, 1);
    troopsLayout->addWidget(new QLabel(tr("Cavalry")), 3, 0);
    troopsLayout->addWidget(cavalryMedalsComboBox, 3, 1);
    troopsLayout->addWidget(new QLabel(tr("Mage")), 4, 0);
    troopsLayout->addWidget(mageMedalsComboBox, 4, 1);
    troopsLayout->addWidget(new QLabel(tr("Samurai")), 5, 0);
    troopsLayout->addWidget(samuraiMedalsComboBox, 5, 1);
    troopsLayout->addWidget(new QLabel(tr("Archer")), 6, 0);
    troopsLayout->addWidget(archerMedalsComboBox, 6, 1);
    troopsLayout->addWidget(new QLabel(tr("Monk")), 7, 0);
    troopsLayout->addWidget(monkMedalsComboBox, 7, 1);
    troopsLayout->addWidget(new QLabel(tr("Harpy")), 8, 0);
    troopsLayout->addWidget(harpyMedalsComboBox, 8, 1);
    troopsLayout->addWidget(new QLabel(tr("Beast")), 9, 0);
    troopsLayout->addWidget(beastMedalsComboBox, 9, 1);
    troopsLayout->addWidget(new QLabel(tr("Dragon")), 10, 0);
    troopsLayout->addWidget(dragonMedalsComboBox, 10, 1);
    troopsLayout->addWidget(new QLabel(tr("Zombie")), 11, 0);
    troopsLayout->addWidget(zombieMedalsComboBox, 11, 1);

    troopsLayout->setRowStretch(1000, 1000);
    troopsGroupBox->setLayout(troopsLayout);
    mainLayout->addWidget(troopsGroupBox, 1, 0);
}

GeneralsTab::~GeneralsTab()
{
    
}
