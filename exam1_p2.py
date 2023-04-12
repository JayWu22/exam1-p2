import matplotlib.pyplot as plt
import serial
import numpy as np

serdev = 'COM5'
s = serial.Serial(serdev)

num_samples = 1000

x_values = []
y_values = []

while len(y_values) < num_samples:
    line = s.readline()
    adc_value = float(line)
    y_values.append(adc_value)    
    x_values.append(len(y_values) - 1)

# Plot the waveform
plt.plot(x_values, y_values)
plt.show()
s.close()
