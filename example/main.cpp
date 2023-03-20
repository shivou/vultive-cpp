#include "../include/vultive.h"

int main()
{

    Vultive::INIReader* file = new Vultive::INIReader("test.ini");

    file->open();
    if (!file->isOpen()) {
        std::cout << "Can't open file.\n";
        file->create();
    }
    else {
        file->load();
        file->parse();
    }

    std::cout << "Has: " << file->has("client", "windowWidth") << "\n";

    file->set("client", "windowWidth", "1280");

    std::cout << "Window width: " << file->get("client", "windowWidth") << "\n";

    file->save();
    file->close();
    
}