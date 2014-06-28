#ifndef MAINCONTENTHOLDER_H
#define MAINCONTENTHOLDER_H

#include "DFeditGUI.h"
#include "implementation/DragonForce.h"

#define DFEDIT_VERSION "2.5"

class MainContentHolder : public QMainWindow
{
    Q_OBJECT
    
public:
    MainContentHolder(QWidget* parent = 0);
    ~MainContentHolder(void);

    void        addNewTab     (QStringList inFile);
    std::string getDfeVersion (void);
    
private slots:
    QStringList openFile    (void);
    void        aboutDFedit (void);
    void        closeTab    (int tabNumber);
    void        reloadTab   (void);

private:
    bool        isBlank;
    QTabWidget* mainTab;
    
    void createMenuBar(void);
};

#endif
