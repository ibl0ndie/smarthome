cmake_minimum_required(VERSION 3.10)
project(MySweetHome CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(msh
    src/main.cpp
    src/Device.cpp
    src/Light.cpp
    src/TV.cpp
    src/SamsungTV.cpp
    src/LGTV.cpp
    src/SoundSystem.cpp
    src/Camera.cpp
    src/Alarm.cpp
    src/SmokeDetector.cpp
    src/GasDetector.cpp
    src/TVFactory.cpp
    src/DetectorFactory.cpp
    src/ModeStrategy.cpp
    src/NormalMode.cpp
    src/EveningMode.cpp
    src/PartyMode.cpp
    src/CinemaMode.cpp
    src/SystemState.cpp
    src/NormalState.cpp
    src/HighPerformanceState.cpp
    src/LowPowerState.cpp
    src/SleepState.cpp
    src/PreviousState.cpp
    src/Observer.cpp
    src/SecurityObserver.cpp
    src/Logger.cpp
    src/DeviceManager.cpp
    src/MSHController.cpp
    src/MenuFacade.cpp
)
