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
    else if (bytes < KIBI)
        return QString("%1 bytes").arg(bytes);
    else if (bytes < MEBI)
        return formatUnit(bytes, KIBI, "KiB");
    else if (bytes < GIBI)
        return formatUnit(bytes, MEBI, "MiB");
    else if (bytes < TEBI)
        return formatUnit(bytes, GIBI, "GiB");
    else if (bytes < PEBI)
        return formatUnit(bytes, TEBI, "TiB");
    else if (bytes < EXBI)
        return formatUnit(bytes, PEBI, "PiB");
    else
        return formatUnit(bytes, EXBI, "EiB");
}


