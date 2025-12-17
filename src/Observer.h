#ifndef OBSERVER_H
#define OBSERVER_H

// REQ: Observer Pattern for Camera motion detection
// Student Part: Observer Pattern - Observer Interface
class Observer {
public:
    virtual ~Observer();
    virtual void onMotionDetected() = 0;
};

#endif // OBSERVER_H

