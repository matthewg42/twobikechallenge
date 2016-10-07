#pragma once

#include "Config.h"
#include "Mode.h"
#include <stdint.h>

class _GameMode : public Mode {
public:
    typedef enum eDifficulty {
        Easy,
        Medium,
        Hard
    } Difficulty;

    _GameMode();
    void begin();
    void start();
    void stop();
    void reset();
    void modeUpdate();
    void enterBrownout();
    void exitBrownout();
    bool isFinished();
    void saveToEEPROM();
    void restoreFromEEPROM();
    void writePixels();
    void writeClock();
    void setDifficulty(Difficulty d);
    Difficulty getDifficulty();

private:
    unsigned long _startMillis;
    unsigned long _lastUpdate;
    unsigned long _lastLEDUpdate;
    long _lastClock;
    float _energy1;
    float _energy2;
    Difficulty _difficulty;

    float goalEnergy();

};

extern _GameMode GameMode;

