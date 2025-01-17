#include <FS5113R.h>

FS5113R::FS5113R(uint8_t pin) : fPin(pin)
{}

void FS5113R::begin()
{
    ledcSetup(0, 334, 8);
    ledcAttachPin(fPin, 0);
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

    Serial.println(duty);
    ledcWrite(0, duty);
}

void FS5113R::stop()
{
    write(0.0);
}