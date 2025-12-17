my sweet home project
23/11/2025

Contents

1.	Introduction	1
2.	System Specifications	1
2.1.	High Level Requirements	1
2.2.	The Menu	2
2.3.	Storage	3
2.4.	Devices	3
2.5.	Modes	3
2.6.	State	4
2.7.	Security System	4
2.8.	Detection System	4
3.	Scenario	4
4.	Tasks	4
4.1.	TODO Design Process	4
4.2.	TODO Implementation Process	5
4.3.	TODO Presentation	5


    1. Introduction 
• Project Name: My Sweet Home (MSH) 
• Project Definition: A smart home system has screen panel that manages the home in which  some IoT devices are included 
• Purpose: Learning implementation of design patterns with C++, strengthing integration and
collaboration abilities 
• Technologies: Design Patterns, C++98, VCS (git, svn or fossil), Class Diagram (UML), CMake or Replit
• Responsibilities: 7 people per team (one integrator role, six developer roles) Groups of 5-to-10 are accepted
• Tasks: 
    • Development of low-level requirements (LLR) 
    • Practice of class diagram development 
    • Integration of branch or different source tree stored in a VCS 
    • Getting knowlegde about CMake or Replit 
    • Integration of a whole system under an top project

    2. System Specifications
        2.1. High Level Requirements
REQ1: The MSH shall provide an operation menu. 
REQ2: The MSH shall provide a manual that display how to use the MSH. 
REQ3: The MSH shall use keyboard interaction to select menu item. 
REQ4: The MSH shall save operation log on a persistent memory. 
REQ5: The MSH shall include light, detector system (smoke and gas detection devices), camera and television devices. 
REQ6: The MSH shall provide function to power on and power off each device integrated. 
REQ7: The MSH shall provide normal mode, night mode, party mode and cinema mode. 
REQ8: The MSH shall provide an infrastructure to add a new device into the system and remove a device into system. 
REQ9: IF any device connected to the MSH fails, the MSH shall inform user with log message, alarm or SMS notification according to user option. 
REQ10: WHEN any device is configured statically, the configuration shall be transferred to next devices to be integrated into the MSH. 
REQ11: WHEN the MSH state is changed to another one, the MSH shall store the previous states into the state list. 
REQ12: WHEN the user changes current state to previous or next state into the state list, the 
MSH shall restore the previous or next state. 
REQ13: WHEN camera detects a motion after security system is actived, the MSH shall alarm, light on and call police respectively. 
• REQ14: WHEN the detector system (smoke and gas) detects anything, the MSH shall active
the alarm. 
• REQ15: WHEN the user does not close the alarm, the MSH shall perform lighting on/off with 1 second interval. 
• REQ16: WHEN the user does not acknowledge the lighting on/off, the MSH shall call fire station. 
        2.2. The Menu 
• The MSH menu is display below. It's expected that the user can interact with the system over menu. 
MY SWEET HOME (MSH)
[1] Get Home Status (Show state and mode, information about sensors and actuators)
[2] Add Device - (L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V
[3] Remove Device - (L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V
[4] Power on Device - (L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V, (S)ound System
[5] Power off Device - (L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V, (S)ound System
[6] Change Mode - (N)ormal, (E)vening, (P)arty, (C)inema
[7] Change State - (N)ormal, (H)igh Performance, (L)ow Power, (S)leep, (P)revious one
[8] Manual (Display manual)
[9] About (information about product and developers)
[10] Shutdown (shut down the system)
• The menu items are selected with key press of the keyboard. 
• When the user want to display manual, key 8 is pressed. Firstly, the manual is display, then menu again. 
• When the user want to add one or more camera into the MSH, key 2 (two) is pressed firstly. Then, number of camera is entered, and key C is pressed from submenu. An information is printed out, then menu is displayed again. 
• The MSH always display the menu after any operation is completed. 
        2.3. Storage 
• The menu operation logs are stored into a file that might be any format such as yaml, json,  xml, html or free format. 
• The file is created when the MSH starts, and closed when the MSH shutdowns. 
        2.4. Devices 
• Each sensor device like light, camera, etc. should be implemented as a base class. 
• At least two sensor classes are supposed that inherited from base classes. Each concerete device is referred via Device pointer. 
• For instance, if TV is base class, Samsung and LG are derived class. 
• Smoke detection and gas detection are sold together, therefore you should implement them as separate classes, but creation is done as product family. 
• Alarm is an actuator that is integrated into the MSH, so it is single device that can not be updated. 
• Each sensor and actuator device has a name like combination of brand and model, data field that shows its output or state. 
• Notifying user about device failure is optional, and it is selected by user. 
• Regardless of notification type, all of them are performed printing out a message on 
screen such as 'A SMS is send'. 
• The user can add one or more devices with an addition request over menu. 
• When user wants to add more than one device, it is accepted to copy configuration of present one for next devices. 
• For instance, the configuration might be internal state of a light like color, illumination or camera like resolution, FPS, etc. 
• All devices might be inherited a base class called Device, and it might have a power state that has on and off data. 
• User can power off all devices except the detectors and alarm. They are critical device that can not be powered off. 
• Any sensor device might be broken, or failed. Therefore, the sensor devices should have function to change its operation mode to active and inactive. 
        2.5. Modes 
• Normal mode (light on, TV off, music off), evening mode (light off, TV off, music off), party mode (light on, TV off, music on), cinema mode (light off, TV on, music off)
• The default mode is Normal mode, you should initialize the system with Normal mode configuration. 
• The user can select any mode from menu, and travel between the modes. 
• Each mode selection is display to user after the selection is done. 
• Camera, smoke & gas detectors are always on all modes. 
        2.6. State 
• The MSH has several states to execute the system under different conditions. 
• The default state is Normal, you should initialize the system with Normal state 
configuration. 
• The user can select any state from the state list via the menu, and then may want to select 
previous or next states according to current one. 
        2.7. Security System 
• Any threat or motion is detected by the MSH, it performs a few sequencial operations: alarm, light on and calling police. 
• All operations are performed during a few seconds, then next one is actived. 
• For instance, alarm is triggered during three seconds, then lighting up is executed during two or three seconds, and so on. 
        2.8. Detection System 
• Detection system executes a sequencial operations that are performed during a few seconds similar to the security system. 
• However, the detection operations can be interrupted by the user before time is expired, so the sequence is cut there. 
    3. Scenario 
See the scenario description at “The Scenario.pdf”
    4. Tasks 
        4.1. Forming of the Groups and Requirements Validation
    • Make sure you are starting to design the correct thing!
    • Send me back this WORD with your questions on the text, using WORD review pane -> comment feature murat.yilmaz@ostimteknik.edu.tr
    • Include the group members names list at the end of file
    • Each group only one email, 3 questions at most
    • DEADLINE: <2025-11-27 Thursday>
        4.2. TODO Design Process 
• You should write 40 low-level requirements at least, and establish link or trace between high-level requirements and low-level requirements. 
• You may write high-level requirement id numbers at end of low-level requirements or vice versa to depict link or trace. For instance, 
• REQ1: The MSH shall provide an operation menu. (LLR7)
• You should draw class diagram(s) to explain your design data, and deliver output in any image format (might be snapshot from a tool or drawing on a paper) 
• The class diagrams may include basic data members and member functions, we do not need utility members and functions. 
• We care relationship between classes into the diagrams, so you should set the relationships correctly. 
• You are thoroughly free to add any data members and member functions in your classes not mentioned here. 
• You should create an assignment table that lists developer-software component matching, so we may review individual developer responsibility. 
• The components may be classes, modules or concepts. We expect to see the assignment list including design patterns you plan to use. 
• If developer responsibilities are not assigned fairly, we may reset and assign them. 
• All design process artifacts will be send as a report in Word, PDF or another well-known file format. 
• DEADLINE: <2025-12-04 Thursday>
        4.3. TODO Implementation Process 
• You should implement your design, and we expect to see classes designed at previous stage inside your source code. Any inconsistency means negative score. 
• Each developer should create individual build system for own project, and the integrator should create a build system for entire project. 
• The integration brings bonus score to all team members. 
• If your final project somehow fails such as lack of modules or integration issue, your individual projects are evaluated to get point. 
• We expect you develop the project using any version control system, in particular git. 
Another delivery is your screenshots that depict commit history of your projects. 
• If you do not send commit history, it means negative score for you. 
• DEADLINE: <2025-12-18 Thursday>
• Note that if you need to change your design after implementation, please send the first report again. The changes should be minor. 
        4.4. TODO Presentation 
• DEADLINE: <2025-12-18 Thursday> until the finals
• Each team has 10 minutes to explain the project. 
• The presentation should have 3-4 pages, maximum. 
• The presentation must include the assignment list detailed firstly, then commit history and your integration plan such as branching on git if any. 
• The presentation should include your roadmap, challenges you faced when developing project. 
• If integration and VCS screenshots are completed, each team member gets a base score before own presentation. 

