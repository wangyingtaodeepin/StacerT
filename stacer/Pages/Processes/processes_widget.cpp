#include "processes_widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

ProcessesWidget::ProcessesWidget(QWidget *parent) :
    QWidget(parent),
    m_processTitleLbl(new QLabel(this)),
    m_allProcessesCheck(new QCheckBox(this)),
    m_processSearchBox(new QLineEdit(this)),
    m_processTable(new QTableView(this)),
    m_refreshLabel(new QLabel(this)),
    m_refreshSlider(new QSlider(this)),
    m_endProcessBtn(new QPushButton(this))
{
    m_processTitleLbl->setText(tr("Processes"));
    m_allProcessesCheck->setText(tr("All Processes"));
    m_processSearchBox->setPlaceholderText(tr("Search..."));

    m_processTable->setAutoScroll(true);
    m_processTable->setAutoScrollMargin(16);

    m_refreshLabel->setText(tr("Refresh (1)"));
    m_refreshSlider->setRange(1, 10);
    m_refreshSlider->setPageStep(1);
    m_refreshSlider->setSingleStep(1);
    m_endProcessBtn->setText(tr("End Process"));

    QVBoxLayout *mainVBoxLayout = new QVBoxLayout;
    mainVBoxLayout->setContentsMargins(20, 5, 20, 20);
    mainVBoxLayout->setSpacing(5);

    QHBoxLayout *topProcessesLayout = new QHBoxLayout;
    topProcessesLayout->setContentsMargins(5, 0, 10, 0);
    topProcessesLayout->setSpacing(10);

    QHBoxLayout *bottomProcessesLayout = new QHBoxLayout;
    bottomProcessesLayout->setContentsMargins(5, 0, 10, 0);
    bottomProcessesLayout->setSpacing(10);

    topProcessesLayout->addWidget(m_processTitleLbl);
    topProcessesLayout->addWidget(m_allProcessesCheck);
    topProcessesLayout->addStretch();
    topProcessesLayout->addWidget(m_processSearchBox);

    bottomProcessesLayout->addWidget(m_refreshLabel);
    bottomProcessesLayout->addWidget(m_refreshSlider);
    bottomProcessesLayout->addStretch();
    bottomProcessesLayout->addWidget(m_endProcessBtn);

    mainVBoxLayout->addLayout(topProcessesLayout);
    this->setLayout(mainVBoxLayout);

}
