#ifndef DFEDITGUI_H
#define DFEDITGUI_H

#include <QtWidgets>
#include "GeneralsTab.h"
#include "CastlesTab.h"
#include "DivisionsTab.h"
#include "MassEditTab.h"
#include "KingdomsTab.h"
#include "ItemsTab.h"

class DFeditGUI : public QMainWindow
{
    Q_OBJECT

public:
    DFeditGUI(QWidget* parent = 0);
    ~DFeditGUI(void);

private:
    QTabWidget* parentTab;
    
    void createMenuBar(void);
};

#endif // DFEDITGUI_H

