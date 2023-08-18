#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QtWidgets/qgraphicsscene.h"
#include "game_engine/game.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    GameEngine engine;
private:
    void renderBoard(Ui::MainWindow* ui);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
