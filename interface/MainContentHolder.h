#ifndef MAINCONTENTHOLDER_H
#define MAINCONTENTHOLDER_H

#include "DFeditGUI.h"

#define DFEDIT_VERSION "2.5"

class MainContentHolder : public QMainWindow
{
    Q_OBJECT
    
public:
    MainContentHolder(QWidget* parent = 0);
    ~MainContentHolder(void);

private:
    QTabWidget* mainTab;
    
    void createMenuBar(void);
};

#endif
