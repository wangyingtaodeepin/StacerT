#ifndef CPU_INFO_H
#define CPU_INFO_H

#include <QDebug>
#include <QVector>

#include "Utils/file_util.h"

#define PROC_CPUINFO "/proc/cpuinfo"
#define PROC_STAT    "/proc/stat"

#include "stacer-core_global.h"

class STACERCORESHARED_EXPORT CpuInfo
{
public:
    CpuInfo();

    quint8 getCpuCoreCount() const;
    QList<int> getCpuPercents() const;

private:
    int getCpuPercent(const QList<double> &cpuTimes, const int &processor=0) const;
};

#endif // CPU_INFO_H
