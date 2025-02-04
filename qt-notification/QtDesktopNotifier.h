#ifndef QTDESKTOPNOTIFIER_H
#define QTDESKTOPNOTIFIER_H

#include "QtAbstractNotifier.h"
#include "QtNotifierFactory.h"

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
    _CONSTEXPR_IF_VIRTUAL_SUPPORTED bool hasIcon() override { return true; }
    QString caption() override;
    void setCaption(const QString &caption) override;
    _CONSTEXPR_IF_VIRTUAL_SUPPORTED bool hasCaption() override { return true; }
    QString title() override;
    void setTitle(const QString &title) override;
    _CONSTEXPR_IF_VIRTUAL_SUPPORTED bool hasTitle() { return true; };
    QVariant id() override;
    void setId(const QVariant &id) override;
    _CONSTEXPR_IF_VIRTUAL_SUPPORTED bool hasId() override { return true; }
    int msecs() override;
    void setMsecs(int msecs) override;
    _CONSTEXPR_IF_VIRTUAL_SUPPORTED bool hasMsecs() override { return true; }
    bool isVisible() override;

public slots:
    bool show() override;
    bool setVisible(bool visible) override;
    bool hide() override;

private:
    QSystemTrayIcon *m_SystemTrayIcon;
    MessageIcon m_icon;
    QString m_caption, m_title;
    QVariant m_id;
    QAtomicInt m_msecs;
    QReadWriteLock m_lock;
};
#endif // QTDESKTOPNOTIFIER_H
