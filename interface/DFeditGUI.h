#ifndef DFEDITGUI_H
#define DFEDITGUI_H

#include <QtWidgets>
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
    DFeditGUI(QWidget* parent = 0);
    ~DFeditGUI(void);

private:
    QTabWidget*  dfTab;
    QGridLayout* layout;
};

#endif // DFEDITGUI_H
