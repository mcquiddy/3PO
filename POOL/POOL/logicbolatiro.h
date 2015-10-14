#ifndef LOGICBOLATIRO_H
#define LOGICBOLATIRO_H
#include <QObject>

#include "Poolconstants.h"
class LogicBolaTiro: public QObject
{
    Q_OBJECT
public:
    LogicBolaTiro();
    int getPosX();
    int getPosY();
private:
    int rangeNumberX;
    int rangeNumberY;
public slots:

};

#endif // LOGICBOLATIRO_H
