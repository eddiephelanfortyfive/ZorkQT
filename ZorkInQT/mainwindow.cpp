#include "mainwindow.h"
#include "exit.h"
#include "invalidMoveExeption.h"
#include "room.h"
#include "ui_mainwindow.h"
#include "player.h"
#include "worldBuilder.h"
#include "globals.h"
#include "item.h"

MainWindow::MainWindow(Player* player, QWidget *parent)
    : QMainWindow(parent), m_player(player), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->PickUp, &QPushButton::clicked, this, &MainWindow::pickUpItem);
    connect(ui->North, &QPushButton::clicked, this, &MainWindow::moveNorth);
    connect(ui->South, &QPushButton::clicked, this, &MainWindow::moveSouth);
    connect(ui->East, &QPushButton::clicked, this, &MainWindow::moveEast);
    connect(ui->West, &QPushButton::clicked, this, &MainWindow::moveWest);


    connect(m_player, &Player::moved, this, &MainWindow::updateDisplay);

    updateDisplay();
    updateProgressBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveNorth()
{
    Room* currentRoom = m_player->getCurrentRoom();
    const std::vector<Exit*>& exits = currentRoom->getExits();
    for (const Exit* exit : exits) {
        if (exit->getDirection() == "North") {
            m_player->moveTo(*exit->getDestination());
            emit m_player->moved();
            updateProgressBar();
            playerMoves++;
            qDebug() << "Player moves: " << playerMoves;
            break;
        }
    }
    try {
        throw InvalidMoveException("North");
    } catch (const InvalidMoveException& e) {
        ui->MainConsole->append("Error: " + QString::fromStdString(e.what()));
    }
}

void MainWindow::moveSouth()
{
    Room* currentRoom = m_player->getCurrentRoom();
    const std::vector<Exit*>& exits = currentRoom->getExits();
    for (const Exit* exit : exits) {
        if (exit->getDirection() == "South") {
            m_player->moveTo(*exit->getDestination());
            emit m_player->moved();
            updateProgressBar();

            playerMoves++;
            qDebug() << "Player moves: " << playerMoves;
            break;
        }
    }
    try {
        throw InvalidMoveException("South");
    } catch (const InvalidMoveException& e) {
        ui->MainConsole->append("Error: " + QString::fromStdString(e.what()));
    }

}

void MainWindow::moveEast()
{
    Room* currentRoom = m_player->getCurrentRoom();
    const std::vector<Exit*>& exits = currentRoom->getExits();
    for (const Exit* exit : exits) {
        if (exit->getDirection() == "East") {
            m_player->moveTo(*exit->getDestination());
            emit m_player->moved();
            updateProgressBar();

            playerMoves++;
            qDebug() << "Player moves: " << playerMoves;
            break;
        }
    }
    try {
        throw InvalidMoveException("East");
    } catch (const InvalidMoveException& e) {
        ui->MainConsole->append("Error: " + QString::fromStdString(e.what()));
    }

}

void MainWindow::moveWest()
{
    Room* currentRoom = m_player->getCurrentRoom();
    const std::vector<Exit*>& exits = currentRoom->getExits();
    for (const Exit* exit : exits) {
        if (exit->getDirection() == "West") {
            m_player->moveTo(*exit->getDestination());
            emit m_player->moved();
            updateProgressBar();

            playerMoves++;
            qDebug() << "Player moves: " << playerMoves;
            break;
        }
    }

    try {
        throw InvalidMoveException("West");
    } catch (const InvalidMoveException& e) {
        ui->MainConsole->append("Error: " + QString::fromStdString(e.what()));
    }

}

void MainWindow::updateDisplay()
{
    ui->MainConsole->clear();

    Room* currentRoom = m_player->getCurrentRoom();
    if (currentRoom) {
        QString roomDescription = QString::fromStdString(currentRoom->getDescription());
        ui->MainConsole->append("===\n" + roomDescription + "\n===\n");


        const std::vector<Item*>& items = currentRoom->getItems();
        if (!items.empty()) {
            ui->MainConsole->append("Items in the room:");
            for (const auto& item : items) {
                QString itemName = item->getName();
                ui->MainConsole->append("- " + itemName+"\n");
            }
        }

        const std::vector<Exit*>& exits = currentRoom->getExits();
        ui->MainConsole->append("Exits:");
        for (const auto& exit : exits) {
            QString direction = exit->getDirection();
            QString description = exit->getDescription();

            ui->MainConsole->append("- " + direction + ": "+"\n" + description+"\n");
        }
    }
}

void MainWindow::updateItemsInRoom() {
    Room* currentRoom = m_player->getCurrentRoom();
    if (currentRoom) {
        const std::vector<Item*>& items = currentRoom->getItems();

        if (!items.empty()) {
            ui->MainConsole->append("Items in the room:");
            for (const auto& item : items) {
                ui->MainConsole->append("- " + item->getDescription());
            }
        }
    }
}

void MainWindow::pickUpItem() {
    Room* currentRoom = m_player->getCurrentRoom();
    if (currentRoom) {
        const std::vector<Item*>& items = currentRoom->getItems();
        qDebug() << "Trying to pick up item";
        if (!items.empty()) {
            Item* itemToPickUp = items.front();
            Item itemCopy(*itemToPickUp);

            m_player->addItemToInventory(new Item(itemCopy));

            ui->MainConsole->append("You picked up: " + itemCopy.getDescription());
            qDebug() << "You picked up: " + itemCopy.getDescription();

            currentRoom->removeItem(itemToPickUp);
            delete itemToPickUp;
            updateItemsInRoom();
            updateInventoryList();
        }
    }
}


struct ProgressBar {
    unsigned int value : 7;
    //progress bar will always be 0-100 so 7 bits is enough to deal with this range
};

ProgressBar progressBar; // Global instance of ProgressBar

void MainWindow::updateProgressBar() {
    MyUnion u;

    int currentRoomNumber = m_player->getCurrentRoom()->getId();

    if (m_rooms.empty()) {
        u.intValue = 10;
    } else {
        u.intValue= m_rooms.size();
    }

    progressBar.value = (currentRoomNumber * 100) / u.intValue;
    ui->ProgressBar->setValue(progressBar.value);
}

void MainWindow::updateInventoryList() {
    ui->InventoryConsole->clear();
    qDebug() << "Updating inventory list...";

    if (!m_player) {
        qDebug() << "Error: Player is null!";
        return;
    }

    const std::vector<Item*>& inventory = m_player->getInventory();
    if (inventory.empty()) {
        qDebug() << "Player inventory is empty!";
        return;
    }

    qDebug() << "Number of items in player inventory:" << inventory.size();

    QString inventoryMessage = "Inventory:\n";
    for (const Item* item : inventory) {
        QString itemDescription = item->getName() + ": " + item->getDescription() + "\n";
        qDebug() << "Adding item to the list:" << itemDescription;
        inventoryMessage += itemDescription;
    }

    // Append the inventory message to the inventory console
    ui->InventoryConsole->append(inventoryMessage);

    qDebug() << "Finished updating inventory list";
}




