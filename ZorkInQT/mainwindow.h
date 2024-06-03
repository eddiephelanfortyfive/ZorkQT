#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Player.h"

class QTextEdit;
class QPushButton;
class QListWidget;
class WorldBuilder; // Forward declaration

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Player* player,QWidget *parent = nullptr);
    void pickUpItem();
    void updateItemsInRoom();
    void updateInventoryList();
    ~MainWindow();

    union MyUnion {
        int intValue;
    };

private slots:
    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();
    void updateDisplay();
    void updateProgressBar();

private:
    Ui::MainWindow *ui;
    Player* m_player;
    std::vector<Room*> m_rooms;
    QTextEdit* m_textEdit;
    QListWidget* m_inventoryList;

    friend class WorldBuilder;
};

#endif // MAINWINDOW_H
