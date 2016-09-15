#ifndef MYTOOLBUTTON_H
#define MYTOOLBUTTON_H

#include <QToolButton>

class MyToolButton : public QToolButton
{
public:
    MyToolButton();
    int rownum;

public slots:
    void oncellclicked();

signals:
    void cellclicked(int rownum);

};

#endif // MYTOOLBUTTON_H
