#include "app_widget.h"

#define SIDEBAR_WIDTH 60

AppWidget::AppWidget(QWidget *parent) :
    QWidget(parent),
    m_dashBtn(new QPushButton),
    m_processesBtn(new QPushButton),
    m_resourcesBtn(new QPushButton),
    m_servicesBtn(new QPushButton),
    m_settingsBtn(new QPushButton),
    m_startupAppsBtn(new QPushButton),
    m_systemCleanerBtn(new QPushButton),
    m_uninstallerBtn(new QPushButton),

    m_pageTitle(new QLabel),
    m_pageStacked(new QStackedWidget(this))
{
    setFixedSize(850, 550);
    setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *sideBarLayout = new QVBoxLayout;
    QVBoxLayout *pageContentLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    sideBarLayout->setContentsMargins(0, 0, 0, 0);
    sideBarLayout->setSpacing(0);
    pageContentLayout->setContentsMargins(0, 0, 0, 0);
    pageContentLayout->setSpacing(5);

    QSpacerItem *spacer1 = new QSpacerItem(SIDEBAR_WIDTH, SIDEBAR_WIDTH, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem *spacer2 = new QSpacerItem(SIDEBAR_WIDTH, SIDEBAR_WIDTH, QSizePolicy::Minimum, QSizePolicy::Expanding);

    m_dashBtn->setFixedWidth(SIDEBAR_WIDTH);
    m_startupAppsBtn->setFixedWidth(SIDEBAR_WIDTH);
    m_systemCleanerBtn->setFixedWidth(SIDEBAR_WIDTH);
    m_servicesBtn->setFixedWidth(SIDEBAR_WIDTH);
    m_processesBtn->setFixedWidth(SIDEBAR_WIDTH);
    m_uninstallerBtn->setFixedWidth(SIDEBAR_WIDTH);
    m_resourcesBtn->setFixedWidth(SIDEBAR_WIDTH);
    m_settingsBtn->setFixedWidth(SIDEBAR_WIDTH);

    sideBarLayout->addSpacerItem(spacer1);
    sideBarLayout->addWidget(m_dashBtn);
    sideBarLayout->addWidget(m_startupAppsBtn);
    sideBarLayout->addWidget(m_systemCleanerBtn);
    sideBarLayout->addWidget(m_servicesBtn);
    sideBarLayout->addWidget(m_processesBtn);
    sideBarLayout->addWidget(m_uninstallerBtn);
    sideBarLayout->addWidget(m_resourcesBtn);
    sideBarLayout->addWidget(m_settingsBtn);
    sideBarLayout->addSpacerItem(spacer2);

    m_pageTitle->setText(tr("Title"));
    m_pageTitle->setAlignment(Qt::AlignCenter);
    m_pageStacked->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    pageContentLayout->addWidget(m_pageTitle);
    pageContentLayout->setAlignment(m_pageTitle, Qt::AlignTop);
    pageContentLayout->addWidget(m_pageStacked);

    mainLayout->addLayout(sideBarLayout);
    mainLayout->addLayout(pageContentLayout);

    this->setLayout(mainLayout);

}
