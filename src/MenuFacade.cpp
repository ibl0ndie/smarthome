#include "MenuFacade.h"
#include "MSHController.h"
#include "DeviceManager.h"
#include "Device.h"
#include "TVFactory.h"
#include "DetectorFactory.h"
#include "NormalMode.h"
#include "EveningMode.h"
#include "PartyMode.h"
#include "CinemaMode.h"
#include "NormalState.h"
#include "HighPerformanceState.h"
#include "LowPowerState.h"
#include "SleepState.h"
#include "PreviousState.h"
#include "Light.h"
#include "TV.h"
#include "SoundSystem.h"
#include "Camera.h"
#include "Alarm.h"
#include "SmokeDetector.h"
#include "GasDetector.h"
#include "Logger.h"
#include "Observer.h"
#include "SecurityObserver.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

MenuFacade::MenuFacade() {
    initializeSystem();
}

MenuFacade::~MenuFacade() {
}

void MenuFacade::initializeSystem() {
    MSHController& controller = MSHController::getInstance();
    DeviceManager* dm = controller.getDeviceManager();
    
    // Create devices using factories
    TVFactory* samsungFactory = TVFactory::getFactory("Samsung");
    if (samsungFactory) {
        dm->addDevice(samsungFactory->createTV("Living Room TV"));
        delete samsungFactory;
    }
    
    DetectorFactory* detectorFactory = DetectorFactory::getFactory();
    if (detectorFactory) {
        dm->addDevice(detectorFactory->createSmokeDetector("Kitchen Smoke Detector"));
        dm->addDevice(detectorFactory->createGasDetector("Kitchen Gas Detector"));
        delete detectorFactory;
    }
    
    // Create other devices
    dm->addDevice(new Light("Living Room Light"));
    dm->addDevice(new SoundSystem("Main Sound System"));
    dm->addDevice(new Camera("Front Door Camera"));
    dm->addDevice(new Alarm("Main Alarm"));
    
    // Attach security observer to camera
    Camera* camera = dm->getCamera("Front Door Camera");
    if (camera) {
        Observer* observer = controller.getSecurityObserver();
        if (observer) {
            camera->attach(observer);
        }
    }
    
    // Set initial state
    controller.setState(new NormalState());
    controller.setMode(new NormalMode());
    
    controller.log("System initialized with all devices");
}

void MenuFacade::displayMenu() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "   My Sweet Home (MSH) Control Panel" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1.  Get Home Status" << std::endl;
    std::cout << "2.  Add Device (L/D/C/T)" << std::endl;
    std::cout << "3.  Remove Device (L/D/C/T)" << std::endl;
    std::cout << "4.  Power on Device (L/D/C/T/S)" << std::endl;
    std::cout << "5.  Power off Device (L/D/C/T/S)" << std::endl;
    std::cout << "6.  Change Mode (Normal, Evening, Party, Cinema)" << std::endl;
    std::cout << "7.  Change State (Normal, High Performance, Low Power, Sleep, Previous one)" << std::endl;
    std::cout << "8.  Manual" << std::endl;
    std::cout << "9.  About" << std::endl;
    std::cout << "10. Shutdown" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Enter your choice (1-10): ";
}

void MenuFacade::processChoice(int choice) {
    switch (choice) {
        case 1:  MSHController::getInstance().printHomeStatus(); break;
        case 2:  option2_AddDevice(); break;
        case 3:  option3_RemoveDevice(); break;
        case 4:  option4_PowerOnDevice(); break;
        case 5:  option5_PowerOffDevice(); break;
        case 6:  option6_ChangeMode(); break;
        case 7:  option7_ChangeState(); break;
        case 8:  option8_Manual(); break;
        case 9:  option9_About(); break;
        case 10: option10_Shutdown(); break;
        default:
            std::cout << "Invalid choice! Please enter 1-10." << std::endl;
    }
}

void MenuFacade::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = 0;
        }
        processChoice(choice);
    } while (choice != 10);
}

// Helper: List devices by type
void MenuFacade::listDevicesByType(char type) {
    MSHController& controller = MSHController::getInstance();
    DeviceManager* dm = controller.getDeviceManager();
    if (!dm) return;
    
    std::vector<Device*> devices = dm->getAllDevices();
    int index = 1;
    
    for (std::vector<Device*>::iterator it = devices.begin(); it != devices.end(); ++it) {
        Device* dev = *it;
        if (!dev) continue;
        
        bool match = false;
        switch (type) {
            case 'L': case 'l':
                if (dynamic_cast<Light*>(dev)) match = true;
                break;
            case 'T': case 't':
                if (dynamic_cast<TV*>(dev)) match = true;
                break;
            case 'S': case 's':
                if (dynamic_cast<SoundSystem*>(dev)) match = true;
                break;
            case 'C': case 'c':
                if (dynamic_cast<Camera*>(dev)) match = true;
                break;
            case 'D': case 'd':
                if (dynamic_cast<SmokeDetector*>(dev) || dynamic_cast<GasDetector*>(dev)) match = true;
                break;
        }
        
        if (match) {
            std::cout << "  " << index << ". " << dev->getName() << " - " << dev->getStatus() << std::endl;
            index++;
        }
    }
}

// Helper: Select device by type
Device* MenuFacade::selectDeviceByType(char type) {
    MSHController& controller = MSHController::getInstance();
    DeviceManager* dm = controller.getDeviceManager();
    if (!dm) return 0;
    
    std::vector<Device*> devices = dm->getAllDevices();
    std::vector<Device*> matchingDevices;
    
    for (std::vector<Device*>::iterator it = devices.begin(); it != devices.end(); ++it) {
        Device* dev = *it;
        if (!dev) continue;
        
        bool match = false;
        switch (type) {
            case 'L': case 'l':
                if (dynamic_cast<Light*>(dev)) match = true;
                break;
            case 'T': case 't':
                if (dynamic_cast<TV*>(dev)) match = true;
                break;
            case 'S': case 's':
                if (dynamic_cast<SoundSystem*>(dev)) match = true;
                break;
            case 'C': case 'c':
                if (dynamic_cast<Camera*>(dev)) match = true;
                break;
            case 'D': case 'd':
                if (dynamic_cast<SmokeDetector*>(dev) || dynamic_cast<GasDetector*>(dev)) match = true;
                break;
        }
        
        if (match) {
            matchingDevices.push_back(dev);
        }
    }
    
    if (matchingDevices.empty()) {
        std::cout << "No devices of this type found." << std::endl;
        return 0;
    }
    
    std::cout << "\nSelect device (1-" << matchingDevices.size() << "): ";
    int choice;
    std::cin >> choice;
    
    if (choice < 1 || choice > (int)matchingDevices.size()) {
        std::cout << "Invalid selection!" << std::endl;
        return 0;
    }
    
    return matchingDevices[choice - 1];
}

// Option 2: Add Device
void MenuFacade::option2_AddDevice() {
    MSHController& controller = MSHController::getInstance();
    DeviceManager* dm = controller.getDeviceManager();
    if (!dm) return;
    
    std::cout << "\n=== Add Device ===" << std::endl;
    std::cout << "Device types:" << std::endl;
    std::cout << "  L - Light" << std::endl;
    std::cout << "  D - Detector (Smoke/Gas)" << std::endl;
    std::cout << "  C - Camera" << std::endl;
    std::cout << "  T - TV" << std::endl;
    std::cout << "  S - Sound System" << std::endl;
    std::cout << "Select device type (L/D/C/T/S): ";
    
    char type;
    std::cin >> type;
    std::cin.ignore();
    
    std::cout << "Enter device name: ";
    std::string name;
    std::getline(std::cin, name);
    
    Device* newDevice = 0;
    
    switch (type) {
        case 'L': case 'l':
            newDevice = new Light(name);
            break;
        case 'T': case 't': {
            std::cout << "TV brand (Samsung/LG): ";
            std::string brand;
            std::getline(std::cin, brand);
            TVFactory* factory = TVFactory::getFactory(brand);
            if (factory) {
                newDevice = factory->createTV(name);
                delete factory;
            } else {
                std::cout << "Invalid brand! Using Samsung." << std::endl;
                factory = TVFactory::getFactory("Samsung");
                if (factory) {
                    newDevice = factory->createTV(name);
                    delete factory;
                }
            }
            break;
        }
        case 'S': case 's':
            newDevice = new SoundSystem(name);
            break;
        case 'C': case 'c': {
            newDevice = new Camera(name);
            // Attach security observer
            Camera* camera = dynamic_cast<Camera*>(newDevice);
            if (camera) {
                Observer* observer = controller.getSecurityObserver();
                if (observer) {
                    camera->attach(observer);
                }
            }
            break;
        }
        case 'D': case 'd': {
            std::cout << "Detector type (1=Smoke, 2=Gas): ";
            int detType;
            std::cin >> detType;
            DetectorFactory* factory = DetectorFactory::getFactory();
            if (factory) {
                if (detType == 1) {
                    newDevice = factory->createSmokeDetector(name);
                } else if (detType == 2) {
                    newDevice = factory->createGasDetector(name);
                } else {
                    std::cout << "Invalid type! Creating Smoke Detector." << std::endl;
                    newDevice = factory->createSmokeDetector(name);
                }
                delete factory;
            }
            break;
        }
        default:
            std::cout << "Invalid device type!" << std::endl;
            return;
    }
    
    if (newDevice) {
        dm->addDevice(newDevice);
        std::cout << "Device added successfully: " << name << std::endl;
        controller.log("Device added: " + name);
    } else {
        std::cout << "Failed to create device!" << std::endl;
    }
}

// Option 3: Remove Device
void MenuFacade::option3_RemoveDevice() {
    MSHController& controller = MSHController::getInstance();
    DeviceManager* dm = controller.getDeviceManager();
    if (!dm) return;
    
    std::cout << "\n=== Remove Device ===" << std::endl;
    std::cout << "Device types:" << std::endl;
    std::cout << "  L - Light" << std::endl;
    std::cout << "  D - Detector" << std::endl;
    std::cout << "  C - Camera" << std::endl;
    std::cout << "  T - TV" << std::endl;
    std::cout << "  S - Sound System" << std::endl;
    std::cout << "Select device type (L/D/C/T/S): ";
    
    char type;
    std::cin >> type;
    
    listDevicesByType(type);
    Device* dev = selectDeviceByType(type);
    
    if (dev) {
        std::string name = dev->getName();
        dm->removeDevice(name);
        std::cout << "Device removed: " << name << std::endl;
        controller.log("Device removed: " + name);
    }
}

// Option 4: Power On Device
void MenuFacade::option4_PowerOnDevice() {
    MSHController& controller = MSHController::getInstance();
    DeviceManager* dm = controller.getDeviceManager();
    if (!dm) return;
    
    std::cout << "\n=== Power On Device ===" << std::endl;
    std::cout << "Device types:" << std::endl;
    std::cout << "  L - Light" << std::endl;
    std::cout << "  D - Detector" << std::endl;
    std::cout << "  C - Camera" << std::endl;
    std::cout << "  T - TV" << std::endl;
    std::cout << "  S - Sound System" << std::endl;
    std::cout << "Select device type (L/D/C/T/S): ";
    
    char type;
    std::cin >> type;
    
    listDevicesByType(type);
    Device* dev = selectDeviceByType(type);
    
    if (dev) {
        dev->powerOn();
        std::cout << "Device powered on: " << dev->getName() << std::endl;
        std::cout << "Status: " << dev->getStatus() << std::endl;
        controller.log("Device powered on: " + dev->getName());
    }
}

// Option 5: Power Off Device
void MenuFacade::option5_PowerOffDevice() {
    MSHController& controller = MSHController::getInstance();
    DeviceManager* dm = controller.getDeviceManager();
    if (!dm) return;
    
    std::cout << "\n=== Power Off Device ===" << std::endl;
    std::cout << "Device types:" << std::endl;
    std::cout << "  L - Light" << std::endl;
    std::cout << "  D - Detector" << std::endl;
    std::cout << "  C - Camera" << std::endl;
    std::cout << "  T - TV" << std::endl;
    std::cout << "  S - Sound System" << std::endl;
    std::cout << "Select device type (L/D/C/T/S): ";
    
    char type;
    std::cin >> type;
    
    listDevicesByType(type);
    Device* dev = selectDeviceByType(type);
    
    if (dev) {
        // Check if device is critical safety (detectors/alarm)
        SmokeDetector* smoke = dynamic_cast<SmokeDetector*>(dev);
        GasDetector* gas = dynamic_cast<GasDetector*>(dev);
        Alarm* alarm = dynamic_cast<Alarm*>(dev);

        if (smoke || gas || alarm) {
            std::cout << "This device is critical safety; you cannot turn it off." << std::endl;
            controller.log("Blocked power off for critical safety device: " + dev->getName());
            return;
        }

        dev->powerOff();
        std::cout << "Device powered off: " << dev->getName() << std::endl;
        std::cout << "Status: " << dev->getStatus() << std::endl;
        controller.log("Device powered off: " + dev->getName());
    }
}

// Option 6: Change Mode
void MenuFacade::option6_ChangeMode() {
    displayModes();
    int modeChoice;
    std::cin >> modeChoice;
    
    MSHController& controller = MSHController::getInstance();
    ModeStrategy* mode = 0;
    
    switch (modeChoice) {
        case 1: mode = new NormalMode(); break;
        case 2: mode = new EveningMode(); break;
        case 3: mode = new PartyMode(); break;
        case 4: mode = new CinemaMode(); break;
        default:
            std::cout << "Invalid mode choice!" << std::endl;
            return;
    }
    
    if (mode) {
        controller.setMode(mode);
        std::cout << "Mode set to: " << mode->getName() << std::endl;
    }
}

// Option 7: Change State
void MenuFacade::option7_ChangeState() {
    displayStates();
    int stateChoice;
    std::cin >> stateChoice;
    
    MSHController& controller = MSHController::getInstance();
    SystemState* state = 0;
    
    switch (stateChoice) {
        case 1: state = new NormalState(); break;
        case 2: state = new HighPerformanceState(); break;
        case 3: state = new LowPowerState(); break;
        case 4: state = new SleepState(); break;
        case 5:
            controller.restorePreviousState();
            std::cout << "Previous state restored." << std::endl;
            return;
        default:
            std::cout << "Invalid state choice!" << std::endl;
            return;
    }
    
    if (state) {
        controller.saveCurrentState();
        controller.setState(state);
        std::cout << "State changed to: " << state->getName() << std::endl;
    }
}

// Option 8: Manual
void MenuFacade::option8_Manual() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         MSH USER MANUAL" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::cout << "\n[MENU OPTIONS]" << std::endl;
    std::cout << "1. Get Home Status - View current system state, mode, and device summary" << std::endl;
    std::cout << "2. Add Device - Add a new device (Light, Detector, Camera, TV, Sound System)" << std::endl;
    std::cout << "3. Remove Device - Remove an existing device from the system" << std::endl;
    std::cout << "4. Power On Device - Turn on a specific device" << std::endl;
    std::cout << "5. Power Off Device - Turn off a specific device" << std::endl;
    std::cout << "6. Change Mode - Switch between Normal, Evening, Party, or Cinema modes" << std::endl;
    std::cout << "7. Change State - Switch system state (Normal, High Performance, Low Power, Sleep)" << std::endl;
    std::cout << "8. Manual - Display this help manual" << std::endl;
    std::cout << "9. About - Show project information" << std::endl;
    std::cout << "10. Shutdown - Exit the system" << std::endl;
    
    std::cout << "\n[DEVICE TYPES]" << std::endl;
    std::cout << "L - Light: Controls room lighting with brightness adjustment" << std::endl;
    std::cout << "D - Detector: Smoke or Gas detector for safety monitoring" << std::endl;
    std::cout << "C - Camera: Security camera with motion detection" << std::endl;
    std::cout << "T - TV: Television (Samsung or LG brand)" << std::endl;
    std::cout << "S - Sound System: Audio system with volume and bass control" << std::endl;
    
    std::cout << "\n[SECURITY FEATURES]" << std::endl;
    std::cout << "- Camera Motion Detection: When a camera detects motion, the system" << std::endl;
    std::cout << "  automatically triggers the alarm, turns on lights, and calls police." << std::endl;
    std::cout << "- Smoke/Gas Detection: When smoke or gas is detected, the system" << std::endl;
    std::cout << "  triggers the alarm, flashes lights, and calls the fire station." << std::endl;
    
    std::cout << "\n[SYSTEM STATES]" << std::endl;
    std::cout << "- Normal: Standard operation mode" << std::endl;
    std::cout << "- High Performance: Optimized settings for maximum performance" << std::endl;
    std::cout << "- Low Power: Energy-saving mode with minimal device usage" << std::endl;
    std::cout << "- Sleep: Most devices off, security systems remain active" << std::endl;
    std::cout << "- Previous: Restore the previous system state" << std::endl;
    
    std::cout << "\n[MODES]" << std::endl;
    std::cout << "- Normal: Moderate settings for everyday use" << std::endl;
    std::cout << "- Evening: Dimmed lights, relaxed atmosphere" << std::endl;
    std::cout << "- Party: Bright lights, high volume for entertainment" << std::endl;
    std::cout << "- Cinema: Dimmed lights, enhanced audio for movie watching" << std::endl;
    
    std::cout << "\n========================================" << std::endl;
    
    MSHController::getInstance().log("User viewed manual");
}

// Option 9: About
void MenuFacade::option9_About() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         ABOUT MSH SYSTEM" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\nProject: My Sweet Home (MSH)" << std::endl;
    std::cout << "Subtitle: C++98 Design Patterns Term Project" << std::endl;
    std::cout << "\nThis project demonstrates the implementation of various" << std::endl;
    std::cout << "design patterns in C++98 for a home automation system." << std::endl;
    std::cout << "\nDesign Patterns Used:" << std::endl;
    std::cout << "- Factory Method: For creating TV devices (Samsung/LG)" << std::endl;
    std::cout << "- Abstract Factory: For creating detector devices" << std::endl;
    std::cout << "- Strategy Pattern: For system modes (Normal/Evening/Party/Cinema)" << std::endl;
    std::cout << "- State Pattern: For system states with history management" << std::endl;
    std::cout << "- Observer Pattern: For camera motion detection and security alerts" << std::endl;
    std::cout << "- Singleton Pattern: For the central MSHController" << std::endl;
    std::cout << "- Facade Pattern: For the menu system interface" << std::endl;
    std::cout << "\nAll operations are logged to msh.log file." << std::endl;
    std::cout << "\n========================================" << std::endl;
    
    MSHController::getInstance().log("User viewed about");
}

// Option 10: Shutdown
void MenuFacade::option10_Shutdown() {
    MSHController& controller = MSHController::getInstance();
    controller.log("System shutdown initiated by user");
    Logger::getInstance().close();
    std::cout << "\nShutting down My Sweet Home system..." << std::endl;
    std::cout << "Thank you for using MSH!" << std::endl;
}

void MenuFacade::displayModes() {
    std::cout << "\nAvailable Modes:" << std::endl;
    std::cout << "1. Normal" << std::endl;
    std::cout << "2. Evening" << std::endl;
    std::cout << "3. Party" << std::endl;
    std::cout << "4. Cinema" << std::endl;
    std::cout << "Select mode: ";
}

void MenuFacade::displayStates() {
    std::cout << "\nAvailable States:" << std::endl;
    std::cout << "1. Normal" << std::endl;
    std::cout << "2. High Performance" << std::endl;
    std::cout << "3. Low Power" << std::endl;
    std::cout << "4. Sleep" << std::endl;
    std::cout << "5. Previous" << std::endl;
    std::cout << "Select state: ";
}

