#include "mbed.h"

PwmOut PWM1(D6);
AnalogIn Ain(A0);
Thread thread1;
Thread thread2;

int sample = 1000;
int i;

float ADCdata[1000];

void PWM_generator() {
    while (1)
  {
    PWM1.period_us(10);
    for (int i = 10; i < 90; i = i + 10) {
        PWM1.pulsewidth_us(i * 10 / 100);
        //printf("%f\n\r", PWM1.read());
        ThisThread::sleep_for(50ms);
    }
  }
}

void Sample() {
    for (i = 0; i < sample; i++)
    {
        ADCdata[i] = Ain;
        ThisThread::sleep_for(1ms);
    }
  for (i = 0; i < sample; i++)
    {
        printf("%f\n", ADCdata[i]);
        ThisThread::sleep_for(1ms);
    }
}

// main() runs in its own thread in the OS
int main()
{
    thread1.start(PWM_generator);
    thread2.start(Sample);
}

