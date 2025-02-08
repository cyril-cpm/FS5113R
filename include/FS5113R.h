#include <Arduino.h>

#define CW_MAX 218
#define CW_MIN 133

#define CCW_MIN 123
#define CCW_MAX 39

class FS5113R {

    public:

    static int channelIndex;

    FS5113R(uint8_t pin);
    void begin();
    void write(float power);
    void stop();

    private:
    uint8_t fPin = 0;
    int     fChannel = 0;
};
