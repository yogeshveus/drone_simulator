import os
import errno

FIFO = 'american_maid'
data = []

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('fivethirtyeight')

x_vals = []
y_vals = []


def animate():
    # global data
    # x = [a[0] for a in data]
    # y1 = [a[1] for a in data]

    plt.cla()

    # plt.plot(x, y1, label='Channel 1')
    plt.plot(x_vals, y_vals, label='Channel 1')

    plt.legend(loc='upper left')
    plt.tight_layout()

    plt.draw()
    plt.pause(0.001)  # Pause for a short period to allow the plot to update

plt.tight_layout()

try:
    os.mkfifo(FIFO)
except OSError as oe:
    if oe.errno != errno.EEXIST:
        raise

print("Opening FIFO...")
with open(FIFO, 'r') as fifo:
    print("FIFO opened")
    while True:
        for data2 in fifo:
            if len(data2) == 0:
                print("Writer closed")
                break
            print('Read: "{0}"'.format(data2))
            x, y = [float(x) for x in data2.split(" ")]
            # data.append([x, y])
            x_vals.append(x)
            y_vals.append(y)
            animate()

# ani = FuncAnimation(plt.gcf(), animate, interval=1000)


