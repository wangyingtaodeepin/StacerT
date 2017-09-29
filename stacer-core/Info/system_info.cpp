#include "system_info.h"

SystemInfo::SystemInfo()
{
    QStringList lines = FileUtil::readListFromFile(PROC_CPUINFO)
            .filter(QRegExp("^model name"));

    if (!lines.isEmpty()) {
        QStringList model = lines.first().split(":").at(1).split("@");

        if (model.count() > 1) {
            QRegExp sepexp("\\s+");
            QString space(" ");

            this->cpuModel = model.at(0).trimmed().replace(sepexp, space);
            this->cpuSpeed = model.at(1).trimmed().replace(sepexp, space);
        }
    } else {
        QString unknown(QObject::tr("Unknown"));
        this->cpuModel = unknown;
        this->cpuSpeed = unknown;
    }

    CpuInfo ci;
    this->cpuCore = QString::number(ci.getCpuCoreCount());

    QString name = qgetenv("USER");

    if (name.isEmpty())
        name = qgetenv(("USERNAME"));

    try {
        if (name.isEmpty())
            name = CommandUtil::exec("whoami").trimmed();
    } catch (QString &ex) {
        qCritical() << ex;
    }

    username = name;

}

QString SystemInfo::getUsername() const
{
    return username;
}

QString SystemInfo::getHostname() const
{
    return QSysInfo::machineHostName();
}

QString SystemInfo::getPlatform() const
{
    return QString("%1 %2")
            .arg(QSysInfo::kernelType())
            .arg(QSysInfo::currentCpuArchitecture());
}

QString SystemInfo::getDistribution() const
{
    return QSysInfo::prettyProductName();
}

QString SystemInfo::getKernel() const
{
    return QSysInfo::kernelVersion();
}

QString SystemInfo::getCpuModel() const
{
    return this->cpuModel;
}

QString SystemInfo::getCpuSpeed() const
{
    return this->cpuSpeed;
}

QString SystemInfo::getCpuCore() const
{
    return this->cpuCore;
}

QFileInfoList SystemInfo::getCrashReports() const
{
    QDir reports("/var/crash");

    return reports.entryInfoList(QDir::Files);
}

QFileInfoList SystemInfo::getAppLogs() const
{
    QDir logs("/var/log");

    return logs.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
}

QFileInfoList SystemInfo::getAppCaches() const
{
    QString homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    QDir caches(homePath + "/.cache");

    return caches.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
}
