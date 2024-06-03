#include "worldBuilder.h"
#include "exit.h"
#include "room.h"
#include <QString> // Include QString for conversion


WorldBuilder::WorldBuilder()
    : m_player(nullptr)
{
}

WorldBuilder::~WorldBuilder()
{
    delete m_player;

    for (Room* room : m_rooms) {
        delete room;
    }
    m_rooms.clear();
}

void WorldBuilder::buildWorld()
{
    Room* room0 = new Room(0, "You awaken in a dimly lit dungeon cell, the cold stone floor sending shivers up your spine. The sound of dripping water echoes off the walls, and the faint scent of mildew fills the air.");
    Room* room1 = new Room(1, "You push open a heavy iron door, revealing a winding stone staircase that leads upward into darkness. Faint torchlight flickers in the distance, casting long shadows on the walls.");
    Room* room2 = new Room(2, "You emerge from the staircase into a grand hall, the walls lined with dusty tapestries and faded portraits. A chandelier hangs from the ceiling, its crystals catching the dim light.");
    Room* room3 = new Room(3, "You step into a vast library, rows upon rows of dusty tomes stretching out before you. The air is thick with the scent of old parchment, and the sound of fluttering pages fills the silence.");
    Room* room4 = new Room(4, "You find yourself in a lush garden, its flowers in full bloom and the air alive with the buzz of bees. A fountain gurgles in the center of the garden, its water sparkling in the sunlight.");
    Room* room5 = new Room(5, "You enter a dark forest, the trees looming overhead and casting eerie shadows on the forest floor. The sound of rustling leaves fills the air, and you feel as though you're being watched.");
    Room* room6 = new Room(6, "You stumble upon a quaint village, its cobblestone streets lined with cozy cottages and bustling market stalls. Villagers go about their daily business, casting curious glances in your direction.");
    Room* room7 = new Room(7, "You find yourself at the entrance of a forbidding castle, its towering walls draped in ivy and moss. A chill runs down your spine as you gaze up at its dark, looming silhouette.");
    Room* room8 = new Room(8, "You enter a majestic throne room, its marble floors polished to a mirror-like sheen. A throne sits at the far end of the room, its velvet cushions worn with age.");
    Room* room9 = new Room(9, "You step into a chamber filled with treasure, gold coins glittering in the dim light. Jewels and precious artifacts line the walls, their beauty almost blinding.");
    Room* room10 = new Room(10, "You finally reach the end of your journey, standing atop a cliff overlooking the vast expanse of the ocean. The salty sea breeze fills your lungs, and the crash of waves against the rocks below soothes your weary soul.");

    Exit* exit0East = new Exit("East", room2, "You spot a line of straight steps leading up into darkness");
    Exit* exit0South = new Exit("South", room1, "You see a heavy iron door leading to a winding stone staircase.");

    Exit* exit1North = new Exit("North", room0, "You can go back through the heavy iron door.");
    Exit* exit1East = new Exit("East", room3, "You notice a passage leading to a vast library.");

    Exit* exit2West = new Exit("West", room0, "You can go back down the winding stone staircase.");
    Exit* exit2South = new Exit("South", room3, "You see a passage leading to a vast library.");

    Exit* exit3West = new Exit("West", room1, "You notice a heavy iron door.");
    Exit* exit3North = new Exit("North", room2, "You spot a door leading to a grand hall.");
    Exit* exit3East = new Exit("East", room4, "You see an exit leading to a lush garden.");

    Exit* exit4West = new Exit("West", room3, "You notice a passage leading to a vast library.");
    Exit* exit4South = new Exit("South", room5, "You see a path leading into a dark forest.");

    Exit* exit5West = new Exit("West", room7, "You notice a path leading to a forbidding castle.");
    Exit* exit5South = new Exit("South", room6, "You see a path leading to a quaint village.");

    Exit* exit6West = new Exit("West", room8, "You see a path leading to a majestic throne room.");
    Exit* exit6North = new Exit("North", room5, "You see a path leading back into the dark forest.");

    Exit* exit7East = new Exit("East", room5, "You see a path leading back into the dark forest.");
    Exit* exit7South = new Exit("South", room8, "You see a path leading to a majestic throne room.");

    Exit* exit8North = new Exit("North", room8, "You see a path leading to a majestic throne room.");
    Exit* exit8East = new Exit("East", room5, "You see a path leading back into the dark forest.");
    Exit* exit8South = new Exit("South", room9, "You see a chamber, it may hold riches.");

    Exit* exit9South = new Exit("South", room10, "You notice a passage leading to a cliff overlooking the ocean.");

    Exit* exit10North = new Exit("North", room9, "You can go back to the treasure chamber.");

    room0->addExit(exit0South);
    room0->addExit(exit0East);
    room1->addExit(exit1North);
    room1->addExit(exit1East);
    room2->addExit(exit2West);
    room2->addExit(exit2South);
    room3->addExit(exit3West);
    room3->addExit(exit3North);
    room3->addExit(exit3East);
    room4->addExit(exit4West);
    room4->addExit(exit4South);
    room5->addExit(exit5West);
    room5->addExit(exit5South);
    room6->addExit(exit6West);
    room6->addExit(exit6North);
    room7->addExit(exit7East);
    room7->addExit(exit7South);
    room8->addExit(exit8North);
    room8->addExit(exit8East);
    room8->addExit(exit8South);
    room9->addExit(exit9South);
    room10->addExit(exit10North);

    Item* Note = new Item("Note", "The Note reads: Find the book and you will know all.");
    room0->addItem(Note);
    Item* book = new Item("Book", "A book masterfully crafted book writen in ancient language.");
    room3->addItem(book);
    Item* GoldenSword = new Item("Golden Sword", "A golden sword likely woned by whoever ruled these lands");
    room8->addItem(GoldenSword);
    Item* Medal = new Item("Medal", "congradulations you beat my Zork story.");
    room10->addItem(Medal);

    m_player = new Player(room0);
    m_rooms.push_back(room0);
    m_rooms.push_back(room1);
    m_rooms.push_back(room2);
    m_rooms.push_back(room3);
    m_rooms.push_back(room4);
    m_rooms.push_back(room5);
    m_rooms.push_back(room6);
    m_rooms.push_back(room7);
    m_rooms.push_back(room8);
    m_rooms.push_back(room9);
    m_rooms.push_back(room10);
};

Player* WorldBuilder::getPlayer() const
{
    return m_player;
}
