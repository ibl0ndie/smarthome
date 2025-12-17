#include "MenuFacade.h"
#include "MSHController.h"
#include "Logger.h"
#include <iostream>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "   My Sweet Home (MSH) System" << std::endl;
    std::cout << "   C++98 Home Automation Project" << std::endl;
    std::cout << "========================================" << std::endl;
    
    try {
        MenuFacade menu;
        menu.run();
        
        // Cleanup
        MSHController::getInstance().shutdown();
        Logger::getInstance().close();
    } catch (...) {
        std::cerr << "Fatal error occurred!" << std::endl;
        return 1;
    }
    
    return 0;
}
