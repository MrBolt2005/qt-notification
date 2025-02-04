#include "QtDesktopNotifier.h"

#include <QVariant>
#include <QDebug>
#include <QRandomGenerator>

#define kDefaultNotificationIconPath            ":/qml/appicon.png"

//------------------------------------------------------------------------------

QtDesktopNotifier::QtDesktopNotifier(MessageIcon icon, const QString *caption = nullptr, const QString *title = nullptr, const QVariant *id = nullptr, int msecs, QObject *parent = nullptr)
{
    QWriteLocker locker(&m_lock);
    QObject::setParent(parent);
    m_icon = icon;
    m_caption = caption ? *caption : "";
    m_title = title ? *title : "";
    m_id = id ? *id : QVariant();
    m_msecs = msecs;
}

QtDesktopNotifier::QtDesktopNotifier(const QVariant &notificationParameters, QObject *parent)
{
    QWriteLocker locker(&m_lock);
    QObject::setParent(parent);
    QVariantMap parameters = notificationParameters.toMap();

    const auto itIcon = parameters.find("icon");
    if (itIcon != parameters.end())
    {
        bool OK;
        m_icon = static_cast<MessageIcon>(itIcon->toInt(&OK));
        if (!OK) m_icon = Information; // instead of NoIcon, for matching with the library's old(er) versions
    }
    else m_icon = Information;

    const auto itCaption = parameters.find("caption");
    m_caption = (itCaption != parameters.end()) ? itCaption->toString() : "";

    const auto itTitle = parameters.find("title");
    m_title = (itTitle != parameters.end()) ? itTitle->toString() : "";

    const auto itId = parameters.find("id");
    m_id = (itId != parameters.end()) ? *itId : QVariant(QRandomGenerator::global()->generate());
}

//------------------------------------------------------------------------------

bool QtDesktopNotifier::show()
{
    qDebug() << Q_FUNC_INFO << m_SystemTrayIcon->isSystemTrayAvailable();

#ifdef Q_OS_WIN
    m_SystemTrayIcon->setToolTip(m_title + "\n" + m_caption);
#endif
    m_SystemTrayIcon->showMessage(m_title, m_caption, m_icon, 1000);
    return true;
}

//------------------------------------------------------------------------------

MessageIcon QtDesktopNotifier::icon()
{
	QReadLocker locker(&m_lock);
    return m_icon;
}

void QtDesktopNotifier::setIcon(MessageIcon icon)
{
    QWriteLocker locker(&m_lock);
    m_icon = icon;
}

QString QtDesktopNotifier::caption()
{
	QReadLocker locker(&m_lock);
    return m_caption;
}

void QtDesktopNotifier::setCaption(const QString &caption)
{
    QWriteLocker locker(&m_lock);
    m_caption = caption;
}

QString QtDesktopNotifier::title()
{
	QReadLocker locker(&m_lock);
    return m_title;
}

void QtDesktopNotifier::setTitle(const QString &title)
{
    QWriteLocker locker(&m_lock);
    m_title = title;
}

QVariant QtDesktopNotifier::id()
{
	QReadLocker locker(&m_lock);
    return m_id;
}

void QtDesktopNotifier::setId(const QVariant &id)
{
    QWriteLocker locker(&m_lock);
    m_id = id;
}
