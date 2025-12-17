# Faraz Azarmi (200201928) — Camera + Security System

## Low-Level Requirements (LLRs)
- LLR-C1: CameraDevice shall implement motionDetection().
- LLR-C2: Motion detection must notify observers (Observer pattern).
- LLR-C3: Security workflow: Camera → Alarm → Lights → Police.
- LLR-C4: Alarm must have trigger/stop functions.
- LLR-C5: All alerts must be logged.
- LLR-C6: Camera can be toggled ON/OFF.

## What I Implemented (Files)
- src/Camera.h / src/Camera.cpp
- src/SecurityObserver.h / src/SecurityObserver.cpp
- src/Alarm.h / src/Alarm.cpp
- Logging usage via src/Logger.* and controller integration

## Notes
The security scenario is triggered by camera motion detection and handled through
observer-style notification, resulting in alarm trigger, lights activation, and
police notification, with logging for all alerts.


Last updated: 2025-12-17
