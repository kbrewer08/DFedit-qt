#ifndef DFEDITGUI_H
#define DFEDITGUI_H

#include <QtWidgets>
#include "implementation/DragonForce.h"
#include "GeneralsTab.h"
#include "CastlesTab.h"
#include "DivisionsTab.h"
#include "MassEditTab.h"
#include "KingdomsTab.h"
#include "ItemsTab.h"

class DFeditGUI : public QWidget
{
    Q_OBJECT

public:
    DFeditGUI(QString inFile, QWidget* parent = 0);
    ~DFeditGUI(void);

    QString getPlayerName(void);

private:
    DragonForce  dr;

    QTabWidget*  dfTab;
    QGridLayout* layout;
    QString      fileName;

    GeneralsTab*  generalsTab;
    CastlesTab*   castlesTab;
    DivisionsTab* divisionsTab;
    MassEditTab*  massEditTab;
    KingdomsTab*  kingdomsTab;
    ItemsTab*     itemsTab;
};

#endif // DFEDITGUI_H
