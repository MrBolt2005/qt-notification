#ifndef QTABSTRACTNOTIFIER_H
#define QTABSTRACTNOTIFIER_H

#include <QObject>
#include <QString>
#include <QVariant>

#if __cplusplus >= 202002L
#define QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 constexpr
#else
#define QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20
#endif

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

public:
    // from QtDesktopNotifier
    enum MessageIcon { NoIcon, Information, Warning, Critical };
    
    virtual MessageIcon icon() = 0;
    virtual void setIcon(MessageIcon icon) = 0;
    virtual QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasIcon() = 0;
    virtual QString caption() = 0;
    virtual void setCaption(const QString &caption) = 0;
    virtual QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasCaption() = 0;
    virtual QString title() = 0;
    virtual void setTitle(const QString &title) = 0;
    virtual QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasTitle() = 0;
    virtual QVariant id() = 0;
    virtual void setId(const QVariant &id) = 0;
    virtual QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasId() = 0;
    virtual int msecs() = 0;
    virtual void setMsecs(int msecs) = 0;
    virtual QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasMsecs() = 0;

public slots:
    virtual bool show() = 0;
    virtual bool setVisible(bool visible) = 0;
    virtual bool hide() = 0;

signals:
    void activated();
    void messageClicked();
};

#endif // QTABSTRACTNOTIFIER_H
