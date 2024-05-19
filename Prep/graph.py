data = [[10, 90], [11, 42], [12, 63], [13, 81], [14, 56], [15, 78], [16, 90], [17, 92], [18, 79], [19, 81], [20, 82], [21, 84], [22, 85], [23, 86], [24, 87], [25, 88], [26, 89], [27, 90], [28, 91], [29, 92], [30, 93], [31, 94], [32, 95], [33, 96], [34, 97], [35, 98], [36, 99], [37, 100], [38, 101], [39, 102], [40, 103], [41, 104], [42, 105], [43, 106], [44, 107], [45, 108], [46, 109], [47, 110], [48, 111], [49, 112], [50, 113], [51, 114], [52, 115], [53, 116], [54, 117], [55, 118], [56, 119], [57, 120], [58, 121], [59, 122]]

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('fivethirtyeight')

x_vals = []
y_vals = []

i = 0


def animate(i):
    x = [a[0] for a in data[:i]]
    y1 = [a[1] for a in data[:i]]
    y2 = [a[1]*0.7 for a in data[:i]]

    plt.cla()

    plt.plot(x, y1, label='Channel 1')
    plt.plot(x, y2, label='Channel 2')

    plt.legend(loc='upper left')
    plt.tight_layout()

    i+=1


ani = FuncAnimation(plt.gcf(), animate, interval=1000)

plt.tight_layout()
plt.show()