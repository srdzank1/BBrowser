#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QListWidget>
#include <QWebEngineView>
#include <QSplitter>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QMenu>
#include "qhorizontalmenu.h"
#include "cmenuform.h"
#include "XMLParser/cparserxml.h"
#include <QScrollArea>
#include <QScrollBar>
#include <QWebEngineSettings>
#include "VideoFullScreen/fullscreenwindow.h"
#include <QWebEngineFullScreenRequest>
#include <QFuture>
#include <QtConcurrent>
#include <QTextStream>

#include "cheaderimageinfo.h"
#include "cbasewidget.h"
#include <QWebEngineHistory>
#include "cloaderwidget.h"
#include <QSound>
#include "ctopbarwidget.h"
#include "Admin/cadminsettingswidget.h"
#include "Admin/ceditwebsites.h"
#include "Admin/cschedule.h"
#include <QDesktopServices>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "XMLParser/qhelperc.h"
#include <QDir>
#include "ccategorylistitems.h"
#include <QMap>
#include <QStandardPaths>
#include "Admin/cpassworddialog.h"
#include "Admin/cregistrationdialog.h"
#include "Admin/cverifydialog.h"
#include "Admin/cmessagedialog.h"
#include "Admin/ccodedialog.h"

#include "SMTPClient/email.h"
#include "SMTPClient/smtpclient.h"
#include <QMessageBox>
#include <QGraphicsOpacityEffect>

#define SUBDIR "/images/"
//#define SUBDIR "/"

class QWebView;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initVideo();
    void LoadXMLFileFromURLInit();
    void CreateInitElement();
    void SaveSettingData();
    void ReadSettingData();
    void SaveFilteredData();
    void ReadFilteredData();
    void clearXMLData();
    void InitXMLGrabber();
    void SaveFilteredDataCategory();
    void ReadFilteredDataCategory();
    void SaveFilteredDataSchedule();
    void ReadFilteredDataSchedule();
//    void ZackClock();
    void InitPassUserProc();
    void ProcRegistrationDialog();
    void ProcValidateCodeDialog();
    void sendEmail(QString &emailAdd);
    Email createEmail(QString &emailAdd);


protected:
    void resizeEvent(QResizeEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event);
    void keyReleaseEvent(QKeyEvent *);
    void closeEvent(QCloseEvent* e);
private:
    Ui::MainWindow *ui;
    QHorizontalMenu *horizontalMenu;
    CMenuForm *centralMenu;
    QWebEngineView *view;
//    QWebEngineView *viewInit;
    QTimer *autoTimer;
    bool statSleep;
    bool statSleepPrevious;
    void createView();

    void CreateAdminWidget();
    void CreateHeaderImageInfoCategory(tgroup &xmlData);
    void CreateCloseOffWidget();
    void CreateHomeWidget();
    void CreateForwardWidget();
    void CreateBackArrowWidget();
    void CreateDownArrowWidget();
    void CreateUpArrowWidget();
    void CreateCentralMenuScrollArea(tgroup &xmlData);
    void CreateHorizontalMenu(tgroup &xmlData);
    void CreateHeaderImageInfo(tgroup &xmlData);
    void CreateTopBarWidget();
    void CreateLoader();
    QStringList GetAllImagesInFolder();
    bool ItemImageExist(QStringList &images, QString & item);
    QString ParseTransform(QString url);
    void ProcClickForSleep();
    void PlaySound(QString &soundName);
    void readSettings();
    void writeSettings();
    QString Hash(const QByteArray &s);
    QString randString(int len);
    QString randNumString(int len);
    bool validaEmail(QString email);
    void FadeinWidget(QWidget *w);
    void FadeOutWidget(QWidget *w);



    int height;
    int width;
    QScopedPointer<FullScreenWindow> m_fullScreenWindow;
    CParserXML *parser;
    QScrollArea *scroll;
    CHeaderImageInfo *headerImageInfo;
    CHeaderImageInfo *headerImageInfoCategory;

    CBaseWidget * upArrowWidget;
    CBaseWidget * downArrowWidget;
    QString cont;
    QString cont2;
    QTimer *timerSS;
    CBaseWidget * homeWidget;
    CBaseWidget * backWidget;
    CBaseWidget * forwardWidget;
    CBaseWidget * closeOffWidget;
    CBaseWidget * adminWidget;
    bool statusHistoryEnabled;
    QString m_url;
    int resizeCount;
    int catIndx;
    bool statScreenSaver;
    CLoaderWidget *loader;
    CTopBarWidget *topBarWidget;
    CAdminSettingsWidget * admin;
    CEditWebSites *editWebSites;
    CSchedule * editSchedule;

    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QTimer *t;
    QTimer *t2;
    QTimer *t5;
    bool checkProc;
    tgroup xmlData ;
    tgroup xmlDataOrig;
    tsettings mSettings;
    tfilterwebsite mFilteredWeb;
    tfiltercategory mFilteredCategory;
    tfilterschedule mFilteredSchedule;
    CPasswordDialog *passDialog;
    CRegistrationDialog *registrationDialog;
    CVerifyDialog *verifyDialog;
    CMessageDialog *msgDialog;
    CCodeDialog *codeDialog;

    QString userHash;
    QString passHash;
    QString emailReg;
    QString codeHash;
    QString validateCode;

    SMTPClient *client_;
    bool closeCond;

public slots:
    void processClick(int i);
    void processClickInit(int i);
    void ProcClickForUrl(QString &i, QString&t, QImage& image );
    void fullScreenRequested(QWebEngineFullScreenRequest request);
    void procLoadUrlFinished(bool s);
    void procLoadProgress(int);
    void ProcUpClick();
    void ProcDownClick();
    void ProcHomeClick();
    void ProcBackViewClick();
    void ProcCloseOffClick();
    void ProcCloseApplication();
    void ProcForwardViewClick();
    void procLoadUrlChanged(const QUrl&);
    void ProcShowHMenu(bool s);
    void procSelectionChanged();
    void ProcAdminClick();
    void procEditWebsites();
    void procEditSchedule();
    void ProcShowCloseButton(bool);
    void procWebSitesChangeCategory(int&i);
    void ProcCloseAdminMenu();
    void procCloseWebSites();
    void UpdateXMLFromWeb();
    void procupdateHorizMenu();
//    void updateTimer();
    void ProcChangeEnableRestriction();
    void ProcChangeEnableSchedule();
    void ProcPasswordDialog();
    void procOkPD();
    void procCancelPD();
    void procLoadInitVideoFinished(bool s);
    void procOkRegDialog();
    void procCancelRegDialog();
    void procMsgDialog(const QString&, const QString&);
    void procOkMsgDialog();
    void procRecoveryPD();
    void procOkValidateCodeDialog();
    void procCancelValidateCodeDialog();
    void procAskValidateCodeDialog();
    void updateTimerScreenShot();
    void ProcAlwaysInFront(bool stat);
};

#endif // MAINWINDOW_H
