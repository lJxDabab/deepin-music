#ifndef LYRICLABEL_H
#define LYRICLABEL_H

#include <DWidget>

DWIDGET_USE_NAMESPACE

class AbstractWheelWidget : public DWidget
{
    Q_OBJECT

public:
    AbstractWheelWidget(bool touch, QWidget *parent = 0);
    virtual ~AbstractWheelWidget();

    int currentIndex() const;
    void setCurrentIndex(int index);

    bool event(QEvent *);
    void paintEvent(QPaintEvent *e);
    virtual void paintItem(QPainter *painter, int index, const QRect &rect) = 0;

    virtual int itemHeight() const = 0;
    virtual int itemCount() const = 0;

public slots:
    void scrollTo(int index);

signals:
    void stopped(int index);
    void changeTo(int index);

protected:
    int m_currentItem;
    int m_itemOffset;
    qreal m_lastY;
    bool isScrolled;
    bool dosignal;
};

class MusicLyric;
class QFont;

class LyricLabel : public AbstractWheelWidget
{
    Q_OBJECT

public:
    LyricLabel(bool touch, QWidget *parent = 0);


    void getFromFile(QString dir);
    void paintItem(QPainter *painter, int index, const QRect &rect);

    int itemHeight() const;
    int itemCount() const;

signals:
    void changeTo(qint64 pos);
    void rightClicked();
    void mouseEnter();

public slots:
    void postionChanged(qint64 pos);
    void setPostion(qint64 pos);

protected slots:
    void changeToEvent(int index);
    void changeFont();
    void changeNormalColor();
    void changeHightLightColor();

protected:
    void contextMenuEvent(QContextMenuEvent *event);//右击事件
    void enterEvent(QEvent *e);

protected:
    MusicLyric *lyric;
    QFont *lyricFont;
    QColor *lyricNormal;
    QColor *lyricHighlight;
};

#endif // LYRICLABEL_H