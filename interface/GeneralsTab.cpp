#include "DFeditGUI.h"

GeneralsTab::GeneralsTab(QWidget *parent)
    : QWidget(parent)
{
}

GeneralsTab::GeneralsTab(DragonForce* df, QWidget *parent)
        :QWidget(parent)
{
    dr = df;

    QGridLayout* mainLayout     = new QGridLayout(this);
    QGridLayout* topLayout      = new QGridLayout();
    QGridLayout* bottomLayout   = new QGridLayout();
    QGridLayout* basicsLayout   = new QGridLayout();
    QGridLayout* weaknessLayout = new QGridLayout();
    QGridLayout* statusLayout   = new QGridLayout();
    QGridLayout* troopsLayout   = new QGridLayout();
    QGridLayout* locationLayout = new QGridLayout();
    QGridLayout* unknownsLayout = new QGridLayout();

    mainLayout->addLayout(topLayout, 0, 0);
    mainLayout->addLayout(bottomLayout, 1, 0);

    basicsGroupBox     = new QGroupBox(tr("Basics"));
    troopsGroupBox     = new QGroupBox(tr("Troops"));
    weaknessesGroupBox = new QGroupBox(tr("Weakness Against"));
    locationGroupBox   = new QGroupBox(tr("Location Editing"));
    locFixedGroupBox   = new QGroupBox();
    divisionGroupBox   = new QGroupBox();
    statusGroupBox     = new QGroupBox(tr("Status"));
    unknownsGroupBox   = new QGroupBox(tr("Unknown Effects"));

//basics area
    genNamesComboBox       = new QComboBox();
    ownerNamesComboBox     = new QComboBox();
    levelEditBox           = new QLineEdit(), levelEditBox->setValidator(new QIntValidator(0, 50));
    expEditBox             = new QLineEdit(); expEditBox->setValidator(new QIntValidator(0, 65535));
    currHpEditBox          = new QLineEdit(); currHpEditBox->setValidator(new QIntValidator(1, 127));
    maxHpEditBox           = new QLineEdit(); maxHpEditBox->setValidator(new QIntValidator(1, 127));
    currMpEditBox          = new QLineEdit(); currMpEditBox->setValidator(new QIntValidator(1, 99));
    maxMpEditBox           = new QLineEdit(); maxMpEditBox->setValidator(new QIntValidator(1, 99));
    strEditBox             = new QLineEdit(); strEditBox->setValidator(new QIntValidator(1, 255));
    comEditBox             = new QLineEdit(); comEditBox->setValidator(new QIntValidator(1, 255));
    intEditBox             = new QLineEdit(); intEditBox->setValidator(new QIntValidator(1, 255));
    livesEditBox           = new QLineEdit(); livesEditBox->setValidator(new QIntValidator(1, 255));
    loyaltyEditBox         = new QLineEdit(); loyaltyEditBox->setValidator(new QIntValidator(0, 255));
    winsEditBox            = new QLineEdit(); winsEditBox->setValidator(new QIntValidator(0, 9999));
    lossesEditBox          = new QLineEdit(); lossesEditBox->setValidator(new QIntValidator(0, 9999));
    meritsEditBox          = new QLineEdit(); meritsEditBox->setValidator(new QIntValidator(0, 9999));
    escapeEditBox          = new QLineEdit(); escapeEditBox->setValidator(new QIntValidator(0, 255));
    spellTierComboBox      = new QComboBox();
    equippedItemComboBox   = new QComboBox();
    searchFortifyCheckBox  = new QCheckBox(tr("Searched/Fortified"));

    ownerSetButton         = new QPushButton(tr("Set"));
    levelSetButton         = new QPushButton(tr("Set"));
    expSetButton           = new QPushButton(tr("Set"));
    currHpSetButton        = new QPushButton(tr("Set"));
    maxHpSetButton         = new QPushButton(tr("Set"));
    currMpSetButton        = new QPushButton(tr("Set"));
    maxMpSetButton         = new QPushButton(tr("Set"));
    strSetButton           = new QPushButton(tr("Set"));
    comSetButton           = new QPushButton(tr("Set"));
    intSetButton           = new QPushButton(tr("Set"));
    livesSetButton         = new QPushButton(tr("Set"));
    loyaltySetButton       = new QPushButton(tr("Set"));
    winsSetButton          = new QPushButton(tr("Set"));
    lossesSetButton        = new QPushButton(tr("Set"));
    meritsSetButton        = new QPushButton(tr("Set"));
    escapeSetButton        = new QPushButton(tr("Set"));
    spellTierSetButton     = new QPushButton(tr("Set"));
    equippedItemSetButton  = new QPushButton(tr("Set"));
    searchFortifySetButton = new QPushButton(tr("Set"));

    basicsLayout->addWidget(new QLabel("General"), 0, 0);
    basicsLayout->addWidget(genNamesComboBox, 0, 1);
    basicsLayout->addWidget(new QLabel("Owner"), 1, 0);
    basicsLayout->addWidget(ownerNamesComboBox, 1, 1);
    basicsLayout->addWidget(ownerSetButton, 1, 2);
    basicsLayout->addWidget(new QLabel("Level"), 2, 0);
    basicsLayout->addWidget(levelEditBox, 2, 1);
    basicsLayout->addWidget(levelSetButton, 2, 2);
    basicsLayout->addWidget(new QLabel("Experience"), 3, 0);
    basicsLayout->addWidget(expEditBox, 3, 1);
    basicsLayout->addWidget(expSetButton, 3, 2);
    basicsLayout->addWidget(new QLabel("Current HP"), 4, 0);
    basicsLayout->addWidget(currHpEditBox, 4, 1);
    basicsLayout->addWidget(currHpSetButton, 4, 2);
    basicsLayout->addWidget(new QLabel("Max HP"), 5, 0);
    basicsLayout->addWidget(maxHpEditBox, 5, 1);
    basicsLayout->addWidget(maxHpSetButton, 5, 2);
    basicsLayout->addWidget(new QLabel("Current MP"), 6, 0);
    basicsLayout->addWidget(currMpEditBox, 6, 1);
    basicsLayout->addWidget(currMpSetButton, 6, 2);
    basicsLayout->addWidget(new QLabel("Max MP"), 7, 0);
    basicsLayout->addWidget(maxMpEditBox, 7, 1);
    basicsLayout->addWidget(maxMpSetButton, 7, 2);
    basicsLayout->addWidget(new QLabel("Strength"), 8, 0);
    basicsLayout->addWidget(strEditBox, 8, 1);
    basicsLayout->addWidget(strSetButton, 8, 2);
    basicsLayout->addWidget(new QLabel("Command"), 9, 0);
    basicsLayout->addWidget(comEditBox, 9, 1);
    basicsLayout->addWidget(comSetButton, 9, 2);
    basicsLayout->addWidget(new QLabel("Intelligence"), 10, 0);
    basicsLayout->addWidget(intEditBox, 10, 1);
    basicsLayout->addWidget(intSetButton, 10, 2);

    basicsLayout->addWidget(new QLabel("Lives"), 0, 4);
    basicsLayout->addWidget(livesEditBox, 0, 5);
    basicsLayout->addWidget(livesSetButton, 0, 6);
    basicsLayout->addWidget(new QLabel("Loyalty"), 1, 4);
    basicsLayout->addWidget(loyaltyEditBox, 1, 5);
    basicsLayout->addWidget(loyaltySetButton, 1, 6);
    basicsLayout->addWidget(new QLabel("Wins"), 2, 4);
    basicsLayout->addWidget(winsEditBox, 2, 5);
    basicsLayout->addWidget(winsSetButton, 2, 6);
    basicsLayout->addWidget(new QLabel("Losses"), 3, 4);
    basicsLayout->addWidget(lossesEditBox, 3, 5);
    basicsLayout->addWidget(lossesSetButton, 3, 6);
    basicsLayout->addWidget(new QLabel("Merits"), 4, 4);
    basicsLayout->addWidget(meritsEditBox, 4, 5);
    basicsLayout->addWidget(meritsSetButton, 4, 6);
    basicsLayout->addWidget(new QLabel("Escape"), 5, 4);
    basicsLayout->addWidget(escapeEditBox, 5, 5);
    basicsLayout->addWidget(escapeSetButton, 5, 6);
    basicsLayout->addWidget(new QLabel("Spell Tier"), 6, 4);
    basicsLayout->addWidget(spellTierComboBox, 6, 5);
    basicsLayout->addWidget(spellTierSetButton, 6, 6);
    basicsLayout->addWidget(new QLabel("Equipped Item"), 7, 4);
    basicsLayout->addWidget(equippedItemComboBox, 7, 5);
    basicsLayout->addWidget(equippedItemSetButton, 7, 6);
    basicsLayout->addWidget(searchFortifyCheckBox, 8, 4);
    basicsLayout->addWidget(searchFortifySetButton, 8, 6);

    basicsLayout->setRowStretch(1000, 1000);
    basicsLayout->setColumnStretch(1000, 1000);
    basicsLayout->setColumnMinimumWidth(3, 30);
    basicsGroupBox->setLayout(basicsLayout);
    topLayout->addWidget(basicsGroupBox, 0, 0);

//weaknesses area
    troopWeakEditBox = new QLineEdit(); troopWeakEditBox->setValidator(new QIntValidator(0, 255));
    swordWeakEditBox = new QLineEdit(); swordWeakEditBox->setValidator(new QIntValidator(0, 65535));
    iceWeakEditBox   = new QLineEdit(); iceWeakEditBox->setValidator(new QIntValidator(0, 65535));
    fireWeakEditBox  = new QLineEdit(); fireWeakEditBox->setValidator(new QIntValidator(0, 65535));
    lightWeakEditBox = new QLineEdit(); lightWeakEditBox->setValidator(new QIntValidator(0, 65535));
    darkWeakEditBox  = new QLineEdit(); darkWeakEditBox->setValidator(new QIntValidator(0, 65535));
    troopWeakEditBox->setMinimumWidth(50);

    troopAttackSetButton = new QPushButton(tr("Set"));
    swordMagicSetButton  = new QPushButton(tr("Set"));
    iceMagicSetButton    = new QPushButton(tr("Set"));
    fireMagicSetButton   = new QPushButton(tr("Set"));
    lightMagicSetButton  = new QPushButton(tr("Set"));
    darkMagicSetButton   = new QPushButton(tr("Set"));

    weaknessLayout->addWidget(new QLabel("Troop Attacks"), 0, 0);
    weaknessLayout->addWidget(troopWeakEditBox, 0, 1);
    weaknessLayout->addWidget(troopAttackSetButton, 0, 2);
    weaknessLayout->addWidget(new QLabel("Sword Magic"), 1, 0);
    weaknessLayout->addWidget(swordWeakEditBox, 1, 1);
    weaknessLayout->addWidget(swordMagicSetButton, 1, 2);
    weaknessLayout->addWidget(new QLabel("Ice Magic"), 2, 0);
    weaknessLayout->addWidget(iceWeakEditBox, 2, 1);
    weaknessLayout->addWidget(iceMagicSetButton, 2, 2);
    weaknessLayout->addWidget(new QLabel("Fire Magic"), 3, 0);
    weaknessLayout->addWidget(fireWeakEditBox, 3, 1);
    weaknessLayout->addWidget(fireMagicSetButton, 3, 2);
    weaknessLayout->addWidget(new QLabel("Light Magic"), 4, 0);
    weaknessLayout->addWidget(lightWeakEditBox, 4, 1);
    weaknessLayout->addWidget(lightMagicSetButton, 4, 2);
    weaknessLayout->addWidget(new QLabel("Dark Magic"), 5, 0);
    weaknessLayout->addWidget(darkWeakEditBox, 5, 1);
    weaknessLayout->addWidget(darkMagicSetButton, 5, 2);

    weaknessLayout->setRowStretch(1000, 1000);
    weaknessLayout->setColumnStretch(1000, 1000);
    weaknessesGroupBox->setLayout(weaknessLayout);
    topLayout->addWidget(weaknessesGroupBox, 0, 1);

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
    statusLayout->setColumnStretch(1000, 1000);
    statusGroupBox->setLayout(statusLayout);
    topLayout->addWidget(statusGroupBox, 0, 2);

//troops area
    troopTypeComboBox     = new QComboBox();
 //because the max value is variable, validator will be set in loadGeneralsTabData
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

    troopTypeSetButton     = new QPushButton(tr("Set"));
    troopAmountSetButton   = new QPushButton(tr("Set"));
    soldierMedalsSetButton = new QPushButton(tr("Set"));
    cavalryMedalsSetButton = new QPushButton(tr("Set"));
    mageMedalsSetButton    = new QPushButton(tr("Set"));
    samuraiMedalsSetButton = new QPushButton(tr("Set"));
    archerMedalsSetButton  = new QPushButton(tr("Set"));
    monkMedalsSetButton    = new QPushButton(tr("Set"));
    harpyMedalsSetButton   = new QPushButton(tr("Set"));
    beastMedalsSetButton   = new QPushButton(tr("Set"));
    dragonMedalsSetButton  = new QPushButton(tr("Set"));
    zombieMedalsSetButton  = new QPushButton(tr("Set"));

    troopsLayout->addWidget(new QLabel(tr("Troop Type")), 0, 0);
    troopsLayout->addWidget(troopTypeComboBox, 0, 1);
    troopsLayout->addWidget(troopTypeSetButton, 0, 2);
    troopsLayout->addWidget(new QLabel(tr("# of Troops")), 1, 0);
    troopsLayout->addWidget(troopAmountEditBox, 1, 1);
    troopsLayout->addWidget(troopAmountSetButton, 1, 2);
    troopsLayout->addWidget(new QLabel(tr("Soldier")), 3, 0);
    troopsLayout->addWidget(soldierMedalsComboBox, 3, 1);
    troopsLayout->addWidget(soldierMedalsSetButton, 3, 2);
    troopsLayout->addWidget(new QLabel(tr("Cavalry")), 4, 0);
    troopsLayout->addWidget(cavalryMedalsComboBox, 4, 1);
    troopsLayout->addWidget(cavalryMedalsSetButton, 4, 2);
    troopsLayout->addWidget(new QLabel(tr("Mage")), 5, 0);
    troopsLayout->addWidget(mageMedalsComboBox, 5, 1);
    troopsLayout->addWidget(mageMedalsSetButton, 5, 2);
    troopsLayout->addWidget(new QLabel(tr("Samurai")), 6, 0);
    troopsLayout->addWidget(samuraiMedalsComboBox, 6, 1);
    troopsLayout->addWidget(samuraiMedalsSetButton, 6, 2);
    troopsLayout->addWidget(new QLabel(tr("Archer")), 7, 0);
    troopsLayout->addWidget(archerMedalsComboBox, 7, 1);
    troopsLayout->addWidget(archerMedalsSetButton, 7, 2);
    troopsLayout->addWidget(new QLabel(tr("Monk")), 8, 0);
    troopsLayout->addWidget(monkMedalsComboBox, 8, 1);
    troopsLayout->addWidget(monkMedalsSetButton, 8, 2);
    troopsLayout->addWidget(new QLabel(tr("Harpy")), 9, 0);
    troopsLayout->addWidget(harpyMedalsComboBox, 9, 1);
    troopsLayout->addWidget(harpyMedalsSetButton, 9, 2);
    troopsLayout->addWidget(new QLabel(tr("Beast")), 10, 0);
    troopsLayout->addWidget(beastMedalsComboBox, 10, 1);
    troopsLayout->addWidget(beastMedalsSetButton, 10, 2);
    troopsLayout->addWidget(new QLabel(tr("Dragon")), 11, 0);
    troopsLayout->addWidget(dragonMedalsComboBox, 11, 1);
    troopsLayout->addWidget(dragonMedalsSetButton, 11, 2);
    troopsLayout->addWidget(new QLabel(tr("Zombie")), 12, 0);
    troopsLayout->addWidget(zombieMedalsComboBox, 12, 1);
    troopsLayout->addWidget(zombieMedalsSetButton, 12, 2);

    troopsLayout->setRowStretch(1000, 1000);
    troopsLayout->setColumnStretch(1000, 1000);
    troopsLayout->setRowMinimumHeight(2, 20);
    troopsGroupBox->setLayout(troopsLayout);
    bottomLayout->addWidget(troopsGroupBox, 0, 0);

//location editing area
    castleLocComboBox      = new QComboBox();
    hiddenLocComboBox      = new QComboBox();
    castleLocRadioButton   = new QRadioButton(tr("Castle"));
    hiddenLocRadioButton   = new QRadioButton(tr("Hidden"));;
    divisionLocRadioButton = new QRadioButton(tr("Division"));;

    castleLocSetButton = new QPushButton(tr("Set"));
    hiddenLocSetButton = new QPushButton(tr("Set"));


    QButtonGroup* locationRadioGroup = new QButtonGroup();
    locationRadioGroup->addButton(castleLocRadioButton);
    locationRadioGroup->addButton(hiddenLocRadioButton);
    locationRadioGroup->addButton(divisionLocRadioButton);

    QGridLayout* locFixedLayout = new QGridLayout();
    locFixedLayout->addWidget(castleLocRadioButton, 0, 0);
    locFixedLayout->addWidget(castleLocComboBox, 0, 1);
    locFixedLayout->addWidget(castleLocSetButton, 0, 2);
    locFixedLayout->addWidget(hiddenLocRadioButton, 1, 0);
    locFixedLayout->addWidget(hiddenLocComboBox, 1, 1);
    locFixedLayout->addWidget(hiddenLocSetButton, 1, 2);
    locFixedGroupBox->setLayout(locFixedLayout);

    divRulerLabel          = new QLabel(tr("Ruler:"));
    divRulerValue          = new QLabel(tr("Place Holder"));
    divLeaderLabel         = new QLabel(tr("Leader:"));
    divLeaderValue         = new QLabel(tr("Place Holder"));
    divXLabel              = new QLabel(tr("X:"));
    divXValue              = new QLabel(tr("Place Holder"));
    divYLabel              = new QLabel(tr("Y:"));
    divYValue              = new QLabel(tr("Place Holder"));
    divOriginLabel         = new QLabel(tr("Origin:"));
    divOriginValue         = new QLabel(tr("Place Holder"));
    divGoalLabel           = new QLabel(tr("Goal:"));
    divGoalValue           = new QLabel(tr("Place Holder"));
    divPrevLabel           = new QLabel(tr("Prev:"));
    divPrevValue           = new QLabel(tr("Place Holder"));
    divNextLabel           = new QLabel(tr("Next:"));
    divNextValue           = new QLabel(tr("Place Holder"));
    divNumberLabel         = new QLabel(tr("Division ID:"));
    divNumberValue         = new QLabel(tr("Place Holder"));
    divStatusLabel         = new QLabel(tr("Status:"));
    divStatusValue         = new QLabel(tr("Place Holder"));
    divTroopsLabel         = new QLabel(tr("Troops:"));
    divTroopsValue         = new QLabel(tr("Place Holder"));
    divMembersLabel        = new QLabel(tr("Members:"));
    divMembersValue        = new QLabel(tr("Place Holder"));
    divCaptivesLabel       = new QLabel(tr("Captives:"));
    divCaptivesValue       = new QLabel(tr("Place Holder"));

    divisionStatusLayout = new QGridLayout();
    divisionStatusLayout->addWidget(divisionLocRadioButton, 0, 0);
    
    divisionStatusLayout->addWidget(divRulerLabel, 1, 0);
    divisionStatusLayout->addWidget(divRulerValue, 1, 1);
    divisionStatusLayout->addWidget(divLeaderLabel, 2, 0);
    divisionStatusLayout->addWidget(divLeaderValue, 2, 1);
    divisionStatusLayout->addWidget(divXLabel, 3, 0);
    divisionStatusLayout->addWidget(divXValue, 3, 1);
    divisionStatusLayout->addWidget(divYLabel, 4, 0);
    divisionStatusLayout->addWidget(divYValue, 4, 1);
    divisionStatusLayout->addWidget(divOriginLabel, 5, 0);
    divisionStatusLayout->addWidget(divOriginValue, 5, 1);
    divisionStatusLayout->addWidget(divGoalLabel, 6, 0);
    divisionStatusLayout->addWidget(divGoalValue, 6, 1);
    divisionStatusLayout->addWidget(divPrevLabel, 7, 0);
    divisionStatusLayout->addWidget(divPrevValue, 7, 1);
    divisionStatusLayout->addWidget(divNextLabel, 8, 0);
    divisionStatusLayout->addWidget(divNextValue, 8, 1);

    divisionStatusLayout->addWidget(divNumberLabel, 1, 3);
    divisionStatusLayout->addWidget(divNumberValue, 1, 4);
    divisionStatusLayout->addWidget(divStatusLabel, 2, 3);
    divisionStatusLayout->addWidget(divStatusValue, 2, 4);
    divisionStatusLayout->addWidget(divTroopsLabel, 3, 3);
    divisionStatusLayout->addWidget(divTroopsValue, 3, 4);
    divisionStatusLayout->addWidget(divMembersLabel, 4, 3);
    divisionStatusLayout->addWidget(divMembersValue, 4, 4);
    divisionStatusLayout->addWidget(divCaptivesLabel, 5, 3);
    divisionStatusLayout->addWidget(divCaptivesValue, 5, 4);

    divisionStatusLayout->setColumnMinimumWidth(2, 30);
    divisionGroupBox->setLayout(divisionStatusLayout);

    locationLayout->addWidget(locFixedGroupBox, 0, 0);
    locationLayout->addWidget(divisionGroupBox, 1, 0);
    locationLayout->setVerticalSpacing(1);

    locationLayout->setRowStretch(1000, 1000);
    locationLayout->setColumnStretch(1000, 1000);
    locationGroupBox->setLayout(locationLayout);
    bottomLayout->addWidget(locationGroupBox, 0, 1);

//unknowns area
    nActionEditBox   = new QLineEdit(); nActionEditBox->setValidator(new QIntValidator(0, 255));
    bActionEditBox   = new QLineEdit(); bActionEditBox->setValidator(new QIntValidator(0, 255));
    btlActionEditBox = new QLineEdit(); btlActionEditBox->setValidator(new QIntValidator(0, 255));
    moralEditBox     = new QLineEdit(); moralEditBox->setValidator(new QIntValidator(0, 255));
    warlikeEditBox   = new QLineEdit(); warlikeEditBox->setValidator(new QIntValidator(0, 255));
    negoEditBox      = new QLineEdit(); negoEditBox->setValidator(new QIntValidator(0, 65535));
    atkPlusEditBox   = new QLineEdit(); atkPlusEditBox->setValidator(new QIntValidator(0, 170));
    defPlusEditBox   = new QLineEdit(); defPlusEditBox->setValidator(new QIntValidator(0, 255));

    nActionSetButton   = new QPushButton(tr("Set"));
    bActionSetButton   = new QPushButton(tr("Set"));
    btlActionSetButton = new QPushButton(tr("Set"));
    moralSetButton     = new QPushButton(tr("Set"));
    warlikeSetButton   = new QPushButton(tr("Set"));
    negoSetButton      = new QPushButton(tr("Set"));
    atkPlusSetButton   = new QPushButton(tr("Set"));
    defPlusSetButton   = new QPushButton(tr("Set"));

    unknownsLayout->addWidget(new QLabel("n_action"), 0, 0);
    unknownsLayout->addWidget(nActionEditBox, 0, 1);
    unknownsLayout->addWidget(nActionSetButton, 0, 2);
    unknownsLayout->addWidget(new QLabel(tr("b_action")), 1, 0);
    unknownsLayout->addWidget(bActionEditBox, 1, 1);
    unknownsLayout->addWidget(bActionSetButton, 1, 2);
    unknownsLayout->addWidget(new QLabel(tr("btl_action")), 2, 0);
    unknownsLayout->addWidget(btlActionEditBox, 2, 1);
    unknownsLayout->addWidget(btlActionSetButton, 2, 2);
    unknownsLayout->addWidget(new QLabel(tr("moral")), 3, 0);
    unknownsLayout->addWidget(moralEditBox, 3, 1);
    unknownsLayout->addWidget(moralSetButton, 3, 2);
    unknownsLayout->addWidget(new QLabel(tr("warlike")), 4, 0);
    unknownsLayout->addWidget(warlikeEditBox, 4, 1);
    unknownsLayout->addWidget(warlikeSetButton, 4, 2);
    unknownsLayout->addWidget(new QLabel(tr("nego")), 5, 0);
    unknownsLayout->addWidget(negoEditBox, 5, 1);
    unknownsLayout->addWidget(negoSetButton, 5, 2);
    unknownsLayout->addWidget(new QLabel(tr("atkplus")), 6, 0);
    unknownsLayout->addWidget(atkPlusEditBox, 6, 1);
    unknownsLayout->addWidget(atkPlusSetButton, 6, 2);
    unknownsLayout->addWidget(new QLabel(tr("defplus")), 7, 0);
    unknownsLayout->addWidget(defPlusEditBox, 7, 1);
    unknownsLayout->addWidget(defPlusSetButton, 7, 2);

    unknownsLayout->setRowStretch(1000, 1000);
    unknownsLayout->setColumnStretch(1000, 1000);
    unknownsGroupBox->setLayout(unknownsLayout);
    bottomLayout->addWidget(unknownsGroupBox, 0, 2);

    if(dr != NULL){
        initComboBoxes();
        loadGeneralsTabData(13);
        genNamesComboBox->setCurrentIndex(13);
    }
}

GeneralsTab::~GeneralsTab()
{
    
}

void GeneralsTab::initComboBoxes(void)
{
    for(int i = 0; i < 171; i++){
        genNamesComboBox->addItem(QString::fromStdString(dr->getGeneralName(i)));
        ownerNamesComboBox->addItem(QString::fromStdString(dr->getGeneralName(i)));
    }

    for(int i = 0; i < 4; i++){
        spellTierComboBox->addItem(QString::number(i));
    }

    for(int i = 0; i < 48; i++){
        equippedItemComboBox->addItem(QString(itemList[i]));
    }

    for(int i = 0; i < 11; i++){
        troopTypeComboBox->addItem(troopType[i]);
        soldierMedalsComboBox->addItem(QString::number(i));
        cavalryMedalsComboBox->addItem(QString::number(i));
        mageMedalsComboBox->addItem(QString::number(i));
        samuraiMedalsComboBox->addItem(QString::number(i));
        archerMedalsComboBox->addItem(QString::number(i));
        monkMedalsComboBox->addItem(QString::number(i));
        harpyMedalsComboBox->addItem(QString::number(i));
        beastMedalsComboBox->addItem(QString::number(i));
        dragonMedalsComboBox->addItem(QString::number(i));
        zombieMedalsComboBox->addItem(QString::number(i));
    }

    for(int i = 0; i < 35; i++){
        castleLocComboBox->addItem(QString(castlesNameList[i]));
    }

    hiddenLocComboBox->addItem(QString::fromStdString("No"));
    hiddenLocComboBox->addItem(QString::fromStdString("Site 62"));
    hiddenLocComboBox->addItem(QString::fromStdString("Site 127"));

    return;
}

void GeneralsTab::loadGeneralsTabData(const int index)
{
    const General gen = General(index);
    
    int maxTroops = gen.troopMedals[gen.getTroopIndex()] * 10;
    troopAmountEditBox->setValidator(new QIntValidator(0, maxTroops));

    ownerNamesComboBox->setCurrentIndex(gen.getOwnerId());
    levelEditBox->setText(QString::number(gen.getLevel()));
    expEditBox->setText(QString::number(gen.getCurrentExp()));
    currHpEditBox->setText(QString::number(gen.getCurrentHP()));
    maxHpEditBox->setText(QString::number(gen.getMaxHP()));
    currMpEditBox->setText(QString::number(gen.getCurrentMP()));
    maxMpEditBox->setText(QString::number(gen.getMaxMP()));
    strEditBox->setText(QString::number(gen.getStrength()));
    comEditBox->setText(QString::number(gen.getCommand()));
    intEditBox->setText(QString::number((gen.getIntelligence() * 6) + 10));
    livesEditBox->setText(QString::number(gen.getLivesLeft()));
    loyaltyEditBox->setText(QString::number(gen.getLoyalty()));
    winsEditBox->setText(QString::number(gen.getNewWins()));
    lossesEditBox->setText(QString::number(gen.getNewLosses()));
    meritsEditBox->setText(QString::number(gen.getNewMerits()));
    escapeEditBox->setText(QString::number(gen.getEscapeChance()));
    spellTierComboBox->setCurrentIndex(gen.getSpellTier());
    equippedItemComboBox->setCurrentIndex(gen.getEquippedItem());

    if(gen.getDomesticsSF()){
        searchFortifyCheckBox->setChecked(false);
    }
    else{
        searchFortifyCheckBox->setChecked(true);
    }

    troopWeakEditBox->setText(QString::number(gen.getDefp()));
    swordWeakEditBox->setText(QString::number(gen.getDefSword()));
    iceWeakEditBox->setText(QString::number(gen.getDefIce()));
    fireWeakEditBox->setText(QString::number(gen.getDefFire()));
    lightWeakEditBox->setText(QString::number(gen.getDefLight()));
    darkWeakEditBox->setText(QString::number(gen.getDefDark()));
    troopTypeComboBox->setCurrentIndex(gen.getTroopIndex());
    troopAmountEditBox->setText(QString::number(gen.getCurrTroopCount()));
    soldierMedalsComboBox->setCurrentIndex(gen.troopMedals[1]);
    cavalryMedalsComboBox->setCurrentIndex(gen.troopMedals[2]);
    mageMedalsComboBox->setCurrentIndex(gen.troopMedals[3]);
    samuraiMedalsComboBox->setCurrentIndex(gen.troopMedals[4]);
    archerMedalsComboBox->setCurrentIndex(gen.troopMedals[5]);
    monkMedalsComboBox->setCurrentIndex(gen.troopMedals[6]);
    harpyMedalsComboBox->setCurrentIndex(gen.troopMedals[7]);
    beastMedalsComboBox->setCurrentIndex(gen.troopMedals[8]);
    dragonMedalsComboBox->setCurrentIndex(gen.troopMedals[9]);
    zombieMedalsComboBox->setCurrentIndex(gen.troopMedals[10]);

    nActionEditBox->setText(QString::number(gen.getNAction()));
    bActionEditBox->setText(QString::number(gen.getBAction()));
    btlActionEditBox->setText(QString::number(gen.getBtlAction()));
    moralEditBox->setText(QString::number(gen.getMoral()));
    warlikeEditBox->setText(QString::number(gen.getWarlike()));
    negoEditBox->setText(QString::number(gen.getNego()));
    atkPlusEditBox->setText(QString::number(gen.getAtkPlus()));
    defPlusEditBox->setText(QString::number(gen.getDefPlus()));

    indexValue->setText(QString::number(gen.getListIndex()));
    portraitValue->setText(QString::number(gen.getPortrait()));
    classValue->setText(QString::fromStdString(gen.getClassName()));
    statusValue->setText(QString::fromStdString(gen.getStatus()));
    if(gen.getHospital()){
        hospitalValue->setText("Yes");
    }
    else{
        hospitalValue->setText("No");
    }

    setLocationControls(index);
    
    return;
}

void GeneralsTab::setLocationControls(const int index)
{
    General gen   = General(index);
    bool fixedLoc = gen.getFixedLocation();
    int  location = gen.getLocation();

    bool castle   = fixedLoc && (location < 34);
    bool hidden   = fixedLoc && (location >= 34);
    bool division = !fixedLoc;

    if(castle){
        castleLocRadioButton->setChecked(true);
        castleLocComboBox->setCurrentIndex(location);
        castleLocComboBox->setEnabled(true);
        castleLocSetButton->setEnabled(true);

        hiddenLocComboBox->setCurrentIndex(0);
        hiddenLocComboBox->setEnabled(false);
        hiddenLocSetButton->setEnabled(false);
        showDivisionInfo(false, index);
    }

    if(hidden){
        hiddenLocRadioButton->setChecked(true);
        hiddenLocComboBox->setEnabled(true);
        hiddenLocSetButton->setEnabled(true);

        if(location == 62){
            hiddenLocComboBox->setCurrentIndex(1);
        }
        if(location == 127){
            hiddenLocComboBox->setCurrentIndex(2);
        }

        castleLocComboBox->setCurrentIndex(34);
        castleLocComboBox->setEnabled(false);
        castleLocSetButton->setEnabled(false);
        showDivisionInfo(false, index);
    }

    if(division){
        divisionLocRadioButton->setChecked(true);

        castleLocComboBox->setCurrentIndex(34);
        castleLocComboBox->setEnabled(false);
        castleLocSetButton->setEnabled(false);

        hiddenLocComboBox->setCurrentIndex(0);
        hiddenLocComboBox->setEnabled(false);
        hiddenLocSetButton->setEnabled(false);
        showDivisionInfo(true, index);
    }

    return;
}

void GeneralsTab::showDivisionInfo(const bool show, const int index)
{
    General  gen = General(index);
    Division div = dr->divArr[gen.getLocation()];

    if(show){
        divisionGroupBox->setVisible(true);
        divRulerValue->setText(QString::fromStdString(gen.getOwnerName()));
        divLeaderValue->setText(QString::fromStdString(div.getLeaderName()));
        divXValue->setText(QString::number(div.getXCoordinate()));
        divYValue->setText(QString::number(div.getYCoordinate()));
        divOriginValue->setText(QString::fromStdString(locationList[div.getOrigin()]));

        if(div.getGoal() == 255){
            divGoalValue->setText(QString::fromStdString(dr->getPlayerName()));
        }
        else{
            divGoalValue->setText(QString::fromStdString(locationList[div.getGoal()]));
        }

        divPrevValue->setText(QString::fromStdString(locationList[div.getPrev()]));
        divNextValue->setText(QString::fromStdString(locationList[div.getNext()]));
        divNumberValue->setText(QString::number(div.getDivNum()));
        divStatusValue->setText(QString::fromStdString(div.getStatusName()));
        divTroopsValue->setText(QString::number(div.getTroopCount()));
        divMembersValue->setText(QString::number(div.getNumMembers()));
        divCaptivesValue->setText(QString::number(div.getNumCaptives()));
    }

    if(!show){
        divisionGroupBox->setVisible(false);
    }

    return;
}
