#ifndef PROCESSES_WIDGET_H
#define PROCESSES_WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QSpacerItem>
#include <QLineEdit>
#include <QSlider>
#include <QPushButton>
#include <QTableView>

class ProcessesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProcessesWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel          *m_processTitleLbl;
    QCheckBox       *m_allProcessesCheck;
    QLineEdit       *m_processSearchBox;

    QTableView      *m_processTable;

    QLabel          *m_refreshLabel;
    QSlider         *m_refreshSlider;
    QPushButton     *m_endProcessBtn;

};

#endif // PROCESSES_WIDGET_H
