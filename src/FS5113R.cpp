#include <FS5113R.h>

int FS5113R::channelIndex = 0;

FS5113R::FS5113R(uint8_t pin) : fPin(pin)
{}

void FS5113R::begin()
{
    fChannel = channelIndex;

    ledcSetup(fChannel, 334, 8);
    ledcAttachPin(fPin, fChannel);

    channelIndex++;
}

void FS5113R::write(float power)
{
    uint8_t duty = 0;

    if (!power)
        duty = 128;
    else if (power > 0.0)
        duty = power * (CW_MAX - CW_MIN) + CW_MIN;
    else
        duty = power * (CCW_MIN - CCW_MAX) + CCW_MIN;

    ledcWrite(fChannel, duty);
}

void FS5113R::stop()
{
    write(0.0);
}