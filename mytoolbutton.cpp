#include "mytoolbutton.h"

MyToolButton::MyToolButton()
{

}

void MyToolButton::oncellclicked()
{
    emit cellclicked(rownum);
}
