#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "application.h"

#include <QTest>
#include <QDebug>
#include <QPoint>
#include <QTimer>
#include <infodialog.h>
#include <DApplication>

#include "ac-desktop-define.h"

#include "mainframe.h"
#include "musicbaselistview.h"
#include "playlistview.h"
#include "musicsonglistview.h"


#include "databaseservice.h"


TEST(Application, playListView)
{
    TEST_CASE_NAME("playListView")

    MainFrame *w = Application::getInstance()->getMainWindow();

    QTest::qWait(500);
    QPoint pos = QPoint(20, 120);
    QTestEventList event;

    // 双击list
    pos = QPoint(20, 120);
    PlayListView *plv = w->findChild<PlayListView *>(AC_PlayListView);
    event.addMouseMove(pos);
    event.addMouseClick(Qt::MouseButton::LeftButton, Qt::NoModifier, pos, 100);
    event.addMousePress(Qt::MouseButton::LeftButton, Qt::NoModifier, pos, 100);
    event.addMouseDClick(Qt::MouseButton::LeftButton, Qt::NoModifier, pos, 100);
    event.simulate(plv->viewport());
    event.clear();


    QTest::qWait(500);
    // 双击list
    event.addMouseMove(pos);
    event.addMouseClick(Qt::MouseButton::LeftButton, Qt::NoModifier, pos, 100);
    event.addMousePress(Qt::MouseButton::LeftButton, Qt::NoModifier, pos, 100);
    event.addMouseDClick(Qt::MouseButton::LeftButton, Qt::NoModifier, pos, 100);
    event.simulate(plv->viewport());
    event.clear();


    QTest::qWait(1000);
}



