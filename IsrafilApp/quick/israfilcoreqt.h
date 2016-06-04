#ifndef ISRAFILCOREQT_H
#define ISRAFILCOREQT_H

/*
 * This class is a Qt Wrapper of IsrafilCore
 * Just to make qmlRegisterType work
 */

#include <QObject>
#include <IsrafilCore/IsrafilCore.h>

class IsrafilCoreQt : public QObject
{
    Q_OBJECT
public:
    explicit IsrafilCoreQt(QObject *parent = 0);
    Q_INVOKABLE SongList searchSong(QString Name);
private:
    Israfil::Core::IsrafilCore *pIC;
signals:

public slots:
};

#endif // ISRAFILCOREQT_H
