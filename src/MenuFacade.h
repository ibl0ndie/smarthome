#ifndef MENUFACADE_H
#define MENUFACADE_H


class Device;

// REQ: Facade Pattern for menu system
// Student Part: Facade Pattern - Simplified Interface
class MenuFacade {
public:
    MenuFacade();
    ~MenuFacade();
    
    void displayMenu();
    void processChoice(int choice);
    void run();
    
private:
    void initializeSystem();
    
    // New menu options
    void option2_AddDevice();
    void option3_RemoveDevice();
    void option4_PowerOnDevice();
    void option5_PowerOffDevice();
    void option6_ChangeMode();
    void option7_ChangeState();
    void option8_Manual();
    void option9_About();
    void option10_Shutdown();
    
    // Helper methods
    void displayModes();
    void displayStates();
    void listDevicesByType(char type);
    Device* selectDeviceByType(char type);
};

#endif // MENUFACADE_H

