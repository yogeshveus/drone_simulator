import os
import errno

FIFO = 'american_maid'

try:
    os.mkfifo(FIFO)
except OSError as oe:
    if oe.errno != errno.EEXIST:
        raise

print("Opening FIFO...")
with open(FIFO, 'r', 0) as fifo:
    print("FIFO opened")
    while True:
        for data in fifo:
            if len(data) == 0:
                print("Writer closed")
                break
            print('Read: "{0}"'.format(data))
            x, y, z = data.split(" ")
