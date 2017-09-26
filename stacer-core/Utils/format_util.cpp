#include "format_util.h"

#include <QString>

#define formatUnit(v, u, t) QString().sprintf("%.1f %s", \
    ((double) v / (double) u), t)

FormatUtil::FormatUtil()
{

}

QString FormatUtil::formatBytes(const quint64 &bytes)
{
    if (1L == bytes)
        return QString("%1 byte").arg(bytes);
    else if (bytes < this->KIBI)
        return QStrint("%1 bytes").arg(bytes);
    else if (bytes < this->MEBI)
        return formatUnit(bytes, this->KIBI, "KiB");
    else if (bytes < this->GIBI)
        return formatUnit(bytes, this->MEBI, "MiB");
    else if (bytes < this->TEBI)
        return formatUnit(bytes, this->GIBI, "GiB");
    else if (bytes < this->PEBI)
        return formatUnit(bytes, this->TEBI, "TiB");
    else if (bytes < this->EXBI)
        return formatUnit(bytes, this->PEBI, "PiB");
    else
        return formatUnit(bytes, this->EXBI, "EiB");
}


