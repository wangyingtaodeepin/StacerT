#ifndef APP_WIDGET_H
#define APP_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>

class AppWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AppWidget(QWidget *parent = nullptr);

private:
    QPushButton *m_dashBtn;
    QPushButton *m_processesBtn;
    QPushButton *m_resourcesBtn;
    QPushButton *m_servicesBtn;
    QPushButton *m_settingsBtn;
    QPushButton *m_startupAppsBtn;
    QPushButton *m_systemCleanerBtn;
    QPushButton *m_uninstallerBtn;

    QLabel *m_pageTitle;
    QStackedWidget *m_pageStacked;
};

#endif // APP_WIDGET_H
