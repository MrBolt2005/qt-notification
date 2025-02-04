#ifndef QTDESKTOPNOTIFIER_H
#define QTDESKTOPNOTIFIER_H

#include "QtAbstractNotifier.h"

#include <memory>

#include <QAtomicInt>
#include <QReadWriteLock>
#include <QSystemTrayIcon>

class QtDesktopNotifier : public QtAbstractNotifier
{
public:
    QtDesktopNotifier(MessageIcon       icon = NoIcon,
                      const QString *caption = nullptr,
                      const QString   *title = nullptr,
                      const QVariant     *id = nullptr,
                      int              msecs = 10000,
                            QObject *parent  = nullptr);
    QtDesktopNotifier(const QVariant &notificationParameters,
                            QObject *parent = nullptr);

    MessageIcon icon() override;
    void setIcon(MessageIcon icon) override;
    QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasIcon() override { return true; }
    QString caption() override;
    void setCaption(const QString &caption) override;
    QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasCaption() override { return true; }
    QString title() override;
    void setTitle(const QString &title) override;
    QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasTitle() { return true; };
    QVariant id() override;
    void setId(const QVariant &id) override;
    QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasId() override { return true; }
    int msecs() override;
    void setMsecs(int msecs) override;
    QTABSTRACTNOTIFIER_CONSTEXPR_IF_CXX20 bool hasMsecs() override { return true; }

public slots:
    bool show() override;
    virtual bool setVisible(bool visible) = 0;
    virtual bool hide() = 0;

private:
    std::unique_ptr<QSystemTrayIcon> m_SystemTrayIcon;
    MessageIcon m_icon;
    QString m_caption, m_title;
    QVariant m_id;
    QAtomicInt m_msecs;
    QReadWriteLock m_lock;
};
#endif // QTDESKTOPNOTIFIER_H
