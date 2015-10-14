#ifndef LOGICBOLABLANCA_H
#define LOGICBOLABLANCA_H
#include <QObject>

#include "Poolconstants.h"
class LogicBolaBlanca: public QObject
{
    Q_OBJECT
public:
    LogicBolaBlanca();
    int getPosX();
    int getPosY();
private:
    int rangeNumberX;
    int rangeNumberY;
public slots:

};

#endif // LOGICBOLABLANCA_H
