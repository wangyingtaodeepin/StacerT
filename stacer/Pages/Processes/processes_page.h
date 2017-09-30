#ifndef PROCESSES_PAGE_H
#define PROCESSES_PAGE_H

#include <QWidget>
#include "processes_widget.h"

#include <QString>
#include <QStringList>
#include <QTimer>
#include <QDebug>
#include <QScrollBar>
#include <QMenu>
#include <QAction>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

class ProcessesPage : public QWidget
{
    Q_OBJECT
public:
    explicit ProcessesPage(QWidget *parent = nullptr);

signals:

public slots:

private:
    ProcessesWidget *m_processesWidget;
};

#endif // PROCESSES_PAGE_H
