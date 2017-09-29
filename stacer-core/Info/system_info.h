#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include "Utils/file_util.h"
#include "Utils/format_util.h"
#include "Utils/command_util.h"
#include "Info/cpu_info.h"

#include "stacer-core_global.h"

class STACERCORESHARED_EXPORT SystemInfo
{
public:
    SystemInfo();

    QString getHostname() const;
    QString getPlatform() const;
    QString getDistribution() const;
    QString getKernel() const;
    QString getCpuModel() const;
    QString getCpuSpeed() const;
    QString getCpuCore() const;

    QFileInfoList getCrashReports() const;
    QFileInfoList getAppLogs() const;
    QFileInfoList getAppCaches() const;

    QString getUsername() const;

private:
    QString cpuCore;
    QString cpuModel;
    QString cpuSpeed;

    QString username;
};

#endif // SYSTEM_INFO_H
