# Nazanin Haghdoust Talebinejad  
Student ID: 200201929  
Module: Light + TV + Sound System  

## Low-Level Requirements (LLRs)

- LLR-L1: LightDevice must have brightness settings.
- LLR-L2: LightDevice must support flashing mode for alerts.
- LLR-T1: TVDevice must support channel and volume.
- LLR-T2: TVs must be created using Factory Method (Samsung, LG).
- LLR-S1: SoundSystem must support volume/bass.
- LLR-S2: Devices must be addable and removable via menu.
- LLR-S3: All actions must be logged.

## Design Summary

The Light device supports adjustable brightness levels and a flashing mode used for alert notifications.
The TV device supports channel switching and volume control, and is instantiated using the Factory Method
pattern to allow creation of different TV brands such as SamsungTV and LGTV.
The SoundSystem supports volume and bass adjustment.
All device actions are logged through a central logging mechanism, and devices can be added to or removed
from the system using a menu-based interface.

## Key Classes / Files

- src/Light.*
- src/TV.*
- src/SamsungTV.*
- src/LGTV.*
- src/TVFactory.*
- src/SoundSystem.*
- src/MenuFacade.*
- src/Logger.*
