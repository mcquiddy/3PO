#ifndef LOGICBOLANEGRA_H
#define LOGICBOLANEGRA_H
#include <QObject>

#include "Poolconstants.h"
class LogicBolaNegra: public QObject
{
    Q_OBJECT
public:
    LogicBolaNegra();
    void setId(int pId);
    int getId();
    int getPosX();
    void setPosX(int pX);
    void setPosY(int pY);
    int getPosY();
private:
    int posX;
    int posY;
    int id;
public slots:

};


#endif // LOGICBOLANEGRA_H
