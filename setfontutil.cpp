#include "setfontutil.h"
#include<QFontDatabase>
SetFontUtil::SetFontUtil()
{

}

void SetFontUtil::setMyFont(QWidget *widget){
    int nIndex = QFontDatabase::addApplicationFont(":/font/SourceHanSansSC-Medium.ttf");
    if (nIndex != -1)
    {
        QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));
        if (strList.count() > 0)
        {
            QFont font(strList.at(0));
            widget->setFont(font);
        }
    }
}
