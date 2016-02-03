/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionSelect_event;
    QAction *actionNext_event;
    QAction *actionClose;
    QAction *actionRun_Reco;
    QAction *actionRecent_Files;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QSplitter *splitter_viz_processing;
    QSplitter *splitter_viz_tabs;
    QWidget *gridLayoutWidget;
    QGridLayout *viz_container_grid_layout;
    QScrollBar *viz_vertical_scrollbar;
    QGraphicsView *viz_graphic_view;
    QScrollBar *viz_horizontal_scrollbar;
    QSlider *viz_zoom_horizontal_slider;
    QTabWidget *algo_tabs_container;
    QWidget *algo_tab_total_counts;
    QGridLayout *gridLayout_2;
    QScrollArea *algo_tab_total_counts_scrollarea;
    QWidget *scrollAreaWidgetContents;
    QWidget *algo_tab_signal_counts;
    QWidget *algo_tab_twophasehough;
    QWidget *algo_tab_kehoughv2;
    QWidget *algo_tab_kehoughv3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *processing_horizontal_layout_2;
    QHBoxLayout *processing_horizontal_layout;
    QLabel *processing_title;
    QProgressBar *processing_statusbar;
    QPushButton *processing_toggle_btn;
    QTextBrowser *processing_console;
    QHBoxLayout *toolbar_container;
    QLabel *reco_file_title;
    QLineEdit *reco_file_path_rdonly_inp;
    QLabel *reco_event_num_title;
    QSpinBox *reco_event_num_spinner;
    QPushButton *reco_event_num_go_btn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEvent;
    QMenu *menuESAF;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSelect_event = new QAction(MainWindow);
        actionSelect_event->setObjectName(QStringLiteral("actionSelect_event"));
        actionNext_event = new QAction(MainWindow);
        actionNext_event->setObjectName(QStringLiteral("actionNext_event"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionRun_Reco = new QAction(MainWindow);
        actionRun_Reco->setObjectName(QStringLiteral("actionRun_Reco"));
        actionRecent_Files = new QAction(MainWindow);
        actionRecent_Files->setObjectName(QStringLiteral("actionRecent_Files"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 0, -1, -1);
        splitter_viz_processing = new QSplitter(centralWidget);
        splitter_viz_processing->setObjectName(QStringLiteral("splitter_viz_processing"));
        splitter_viz_processing->setOrientation(Qt::Vertical);
        splitter_viz_tabs = new QSplitter(splitter_viz_processing);
        splitter_viz_tabs->setObjectName(QStringLiteral("splitter_viz_tabs"));
        splitter_viz_tabs->setOrientation(Qt::Horizontal);
        gridLayoutWidget = new QWidget(splitter_viz_tabs);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        viz_container_grid_layout = new QGridLayout(gridLayoutWidget);
        viz_container_grid_layout->setSpacing(6);
        viz_container_grid_layout->setContentsMargins(11, 11, 11, 11);
        viz_container_grid_layout->setObjectName(QStringLiteral("viz_container_grid_layout"));
        viz_container_grid_layout->setContentsMargins(0, 0, 0, 0);
        viz_vertical_scrollbar = new QScrollBar(gridLayoutWidget);
        viz_vertical_scrollbar->setObjectName(QStringLiteral("viz_vertical_scrollbar"));
        viz_vertical_scrollbar->setOrientation(Qt::Vertical);

        viz_container_grid_layout->addWidget(viz_vertical_scrollbar, 0, 1, 1, 1);

        viz_graphic_view = new QGraphicsView(gridLayoutWidget);
        viz_graphic_view->setObjectName(QStringLiteral("viz_graphic_view"));

        viz_container_grid_layout->addWidget(viz_graphic_view, 0, 0, 1, 1);

        viz_horizontal_scrollbar = new QScrollBar(gridLayoutWidget);
        viz_horizontal_scrollbar->setObjectName(QStringLiteral("viz_horizontal_scrollbar"));
        viz_horizontal_scrollbar->setOrientation(Qt::Horizontal);

        viz_container_grid_layout->addWidget(viz_horizontal_scrollbar, 1, 0, 1, 1);

        viz_zoom_horizontal_slider = new QSlider(gridLayoutWidget);
        viz_zoom_horizontal_slider->setObjectName(QStringLiteral("viz_zoom_horizontal_slider"));
        viz_zoom_horizontal_slider->setOrientation(Qt::Horizontal);

        viz_container_grid_layout->addWidget(viz_zoom_horizontal_slider, 2, 0, 1, 2);

        splitter_viz_tabs->addWidget(gridLayoutWidget);
        algo_tabs_container = new QTabWidget(splitter_viz_tabs);
        algo_tabs_container->setObjectName(QStringLiteral("algo_tabs_container"));
        algo_tab_total_counts = new QWidget();
        algo_tab_total_counts->setObjectName(QStringLiteral("algo_tab_total_counts"));
        gridLayout_2 = new QGridLayout(algo_tab_total_counts);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        algo_tab_total_counts_scrollarea = new QScrollArea(algo_tab_total_counts);
        algo_tab_total_counts_scrollarea->setObjectName(QStringLiteral("algo_tab_total_counts_scrollarea"));
        algo_tab_total_counts_scrollarea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 323, 218));
        algo_tab_total_counts_scrollarea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(algo_tab_total_counts_scrollarea, 0, 0, 1, 1);

        algo_tabs_container->addTab(algo_tab_total_counts, QString());
        algo_tab_signal_counts = new QWidget();
        algo_tab_signal_counts->setObjectName(QStringLiteral("algo_tab_signal_counts"));
        algo_tabs_container->addTab(algo_tab_signal_counts, QString());
        algo_tab_twophasehough = new QWidget();
        algo_tab_twophasehough->setObjectName(QStringLiteral("algo_tab_twophasehough"));
        algo_tabs_container->addTab(algo_tab_twophasehough, QString());
        algo_tab_kehoughv2 = new QWidget();
        algo_tab_kehoughv2->setObjectName(QStringLiteral("algo_tab_kehoughv2"));
        algo_tabs_container->addTab(algo_tab_kehoughv2, QString());
        algo_tab_kehoughv3 = new QWidget();
        algo_tab_kehoughv3->setObjectName(QStringLiteral("algo_tab_kehoughv3"));
        algo_tabs_container->addTab(algo_tab_kehoughv3, QString());
        splitter_viz_tabs->addWidget(algo_tabs_container);
        splitter_viz_processing->addWidget(splitter_viz_tabs);
        verticalLayoutWidget = new QWidget(splitter_viz_processing);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        processing_horizontal_layout_2 = new QVBoxLayout(verticalLayoutWidget);
        processing_horizontal_layout_2->setSpacing(6);
        processing_horizontal_layout_2->setContentsMargins(11, 11, 11, 11);
        processing_horizontal_layout_2->setObjectName(QStringLiteral("processing_horizontal_layout_2"));
        processing_horizontal_layout_2->setContentsMargins(0, 0, 0, 0);
        processing_horizontal_layout = new QHBoxLayout();
        processing_horizontal_layout->setSpacing(6);
        processing_horizontal_layout->setObjectName(QStringLiteral("processing_horizontal_layout"));
        processing_title = new QLabel(verticalLayoutWidget);
        processing_title->setObjectName(QStringLiteral("processing_title"));

        processing_horizontal_layout->addWidget(processing_title);

        processing_statusbar = new QProgressBar(verticalLayoutWidget);
        processing_statusbar->setObjectName(QStringLiteral("processing_statusbar"));
        processing_statusbar->setValue(0);

        processing_horizontal_layout->addWidget(processing_statusbar);

        processing_toggle_btn = new QPushButton(verticalLayoutWidget);
        processing_toggle_btn->setObjectName(QStringLiteral("processing_toggle_btn"));

        processing_horizontal_layout->addWidget(processing_toggle_btn);


        processing_horizontal_layout_2->addLayout(processing_horizontal_layout);

        processing_console = new QTextBrowser(verticalLayoutWidget);
        processing_console->setObjectName(QStringLiteral("processing_console"));

        processing_horizontal_layout_2->addWidget(processing_console);

        splitter_viz_processing->addWidget(verticalLayoutWidget);

        gridLayout_5->addWidget(splitter_viz_processing, 1, 0, 1, 1);

        toolbar_container = new QHBoxLayout();
        toolbar_container->setSpacing(6);
        toolbar_container->setObjectName(QStringLiteral("toolbar_container"));
        reco_file_title = new QLabel(centralWidget);
        reco_file_title->setObjectName(QStringLiteral("reco_file_title"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(reco_file_title->sizePolicy().hasHeightForWidth());
        reco_file_title->setSizePolicy(sizePolicy);

        toolbar_container->addWidget(reco_file_title);

        reco_file_path_rdonly_inp = new QLineEdit(centralWidget);
        reco_file_path_rdonly_inp->setObjectName(QStringLiteral("reco_file_path_rdonly_inp"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(reco_file_path_rdonly_inp->sizePolicy().hasHeightForWidth());
        reco_file_path_rdonly_inp->setSizePolicy(sizePolicy1);
        reco_file_path_rdonly_inp->setReadOnly(true);

        toolbar_container->addWidget(reco_file_path_rdonly_inp);

        reco_event_num_title = new QLabel(centralWidget);
        reco_event_num_title->setObjectName(QStringLiteral("reco_event_num_title"));

        toolbar_container->addWidget(reco_event_num_title);

        reco_event_num_spinner = new QSpinBox(centralWidget);
        reco_event_num_spinner->setObjectName(QStringLiteral("reco_event_num_spinner"));

        toolbar_container->addWidget(reco_event_num_spinner);

        reco_event_num_go_btn = new QPushButton(centralWidget);
        reco_event_num_go_btn->setObjectName(QStringLiteral("reco_event_num_go_btn"));

        toolbar_container->addWidget(reco_event_num_go_btn);


        gridLayout_5->addLayout(toolbar_container, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEvent = new QMenu(menuBar);
        menuEvent->setObjectName(QStringLiteral("menuEvent"));
        menuESAF = new QMenu(menuBar);
        menuESAF->setObjectName(QStringLiteral("menuESAF"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEvent->menuAction());
        menuBar->addAction(menuESAF->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionRecent_Files);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEvent->addAction(actionSelect_event);
        menuEvent->addAction(actionNext_event);
        menuESAF->addAction(actionRun_Reco);

        retranslateUi(MainWindow);

        algo_tabs_container->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open File", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionSelect_event->setText(QApplication::translate("MainWindow", "Select event", 0));
        actionNext_event->setText(QApplication::translate("MainWindow", "Next event", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close File", 0));
        actionRun_Reco->setText(QApplication::translate("MainWindow", "Run Reco", 0));
        actionRecent_Files->setText(QApplication::translate("MainWindow", "Recent Files", 0));
        algo_tabs_container->setTabText(algo_tabs_container->indexOf(algo_tab_total_counts), QApplication::translate("MainWindow", "TotalCounts", 0));
        algo_tabs_container->setTabText(algo_tabs_container->indexOf(algo_tab_signal_counts), QApplication::translate("MainWindow", "SignalCounts", 0));
        algo_tabs_container->setTabText(algo_tabs_container->indexOf(algo_tab_twophasehough), QApplication::translate("MainWindow", "TwoPhaseHough", 0));
        algo_tabs_container->setTabText(algo_tabs_container->indexOf(algo_tab_kehoughv2), QApplication::translate("MainWindow", "KeHoughV2", 0));
        algo_tabs_container->setTabText(algo_tabs_container->indexOf(algo_tab_kehoughv3), QApplication::translate("MainWindow", "KeHoughV3", 0));
        processing_title->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        processing_toggle_btn->setText(QApplication::translate("MainWindow", "Start", 0));
        reco_file_title->setText(QApplication::translate("MainWindow", "Reco file", 0));
        reco_event_num_title->setText(QApplication::translate("MainWindow", "Event num", 0));
        reco_event_num_go_btn->setText(QApplication::translate("MainWindow", "Go", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEvent->setTitle(QApplication::translate("MainWindow", "Event", 0));
        menuESAF->setTitle(QApplication::translate("MainWindow", "ESAF", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
