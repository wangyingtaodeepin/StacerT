#include "info_manager.h"

InfoManager::InfoManager()
{

}

InfoManager *InfoManager::_instance = NULL;

InfoManager *InfoManager::ins()
{
    if (NULL == _instance) {
        _instance = new InfoManager;
    }

    return _instance;
}

QString InfoManager::getUserName() const
{
    return si.getUsername();
}

/********************
 * CPU INFORMATION
 *******************/
quint8 InfoManager::getCpuCoreCount() const
{
    return ci.getCpuCoreCount();
}

QList<int> InfoManager::getCpuPercents() const
{
    return ci.getCpuPercents();
}

/********************
 * MEMORY INFORMATION
 *******************/
void InfoManager::updateMemoryInfo()
{
    mi.updateMemoryInfo();
}

quint64 InfoManager::getSwapUsed() const
{
    return mi.getSwapUsed();
}

quint64 InfoManager::getSwapTotal() const
{
    return mi.getMemTotal();
}

quint64 InfoManager::getMemUsed() const
{
    return mi.getMemUsed();
}

quint64 InfoManager::getMemTotal() const
{
    return mi.getMemTotal();
}

/********************
 * DISK INFORMATION
 *******************/
QList<Disk> InfoManager::getDisks() const
{
    return di.getDisks();
}

void InfoManager::updateDiskInfo()
{
    return di.updateDiskInfo();
}

/********************
 * NETWORK INFORMATION
 *******************/
quint64 InfoManager::getRxBytes() const
{
    return ni.getRXbytes();
}

quint64 InfoManager::getTxBytes() const
{
    return ni.getTXbytes();
}

/********************
 * CLEANER INFORMATION
 *******************/
QFileInfoList InfoManager::getCrashReports() const
{
    return si.getCrashReports();
}

QFileInfoList InfoManager::getAppLogs() const
{
    return si.getAppLogs();
}

QFileInfoList InfoManager::getAppCaches() const
{
    return si.getAppCaches();
}

/********************
 * PROCESSES INFORMATION
 *******************/
void InfoManager::updateProcesses()
{
    pi.updateProcesses();
}

QList<Process> InfoManager::getProcesses() const
{
    return pi.getProcessList();
}
