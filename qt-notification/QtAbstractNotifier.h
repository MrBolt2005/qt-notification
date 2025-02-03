#ifndef QTABSTRACTNOTIFIER_H
#define QTABSTRACTNOTIFIER_H

#include <QObject>

/**
 * @class QtAbstractNotifier The interface for generic notification
 * @brief The class which contains properties for notifications such as
 *        hide, show notifications
 *
 * Each method returns a boolean indicating whether the notifications are
 * supported or not
 */

class QtAbstractNotifier : public QObject
{
    Q_OBJECT

public slots:
    virtual bool show(const QVariant &notificationParameters) = 0;
    virtual bool setVisible(bool visible) = 0;
    virtual bool hide() = 0;

signals:
    void activated();
    void messageClicked();
};

#endif // QTABSTRACTNOTIFIER_H
