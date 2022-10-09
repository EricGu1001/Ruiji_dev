#include "playertool.h"
#include "ui_playertool.h"
#include "setfontutil.h"
#include <QImage>
PlayerTool::PlayerTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerTool)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    //添加资源图片
    ui->icon_play->setMode(PictureBox::FIXED_SIZE);
    ui->icon_backward->setMode(PictureBox::FIXED_SIZE);
    ui->icon_forward->setMode(PictureBox::FIXED_SIZE);
    ui->icon_sound->setMode(PictureBox::FIXED_SIZE);
    ui->icon_setting->setMode(PictureBox::FIXED_SIZE);
    ui->icon_fullscreen->setMode(PictureBox::FIXED_SIZE);
    QImage *playImg = new QImage(":/images/act.png");
    QImage *forwardImg = new QImage(":/images/forward.png");
    QImage *backwardImg = new QImage(":/images/backward.png");
    QImage *soundImg = new QImage(":/images/vol.png");
    QImage *settingImg = new QImage(":/images/setting.png");
    QImage *fullscreenImg = new QImage(":/images/fullscreen.png");
    ui->icon_play->setImage(*playImg);
    ui->icon_backward->setImage(*backwardImg);
    ui->icon_forward->setImage(*forwardImg);
    ui->icon_sound->setImage(*soundImg);
    ui->icon_setting->setImage(*settingImg);
    ui->icon_fullscreen->setImage(*fullscreenImg);
    SetFontUtil::setMyFont(ui->speed);
    SetFontUtil::setMyFont(ui->subtitle);
    SetFontUtil::setMyFont(ui->time);
    SetFontUtil::setMyFont(ui->duration);

}

PlayerTool::~PlayerTool()
{
    delete ui;
}
