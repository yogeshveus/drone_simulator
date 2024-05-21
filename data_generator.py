import numpy as np
from Prep import plot as c2c

np.set_printoptions(threshold=np.inf)

num_points = 20

def as_cpp_array(arr):
    arr_string = ", ".join([str(x) for x in arr])
    return f'{{ {arr_string} }}'

def generate_coords(image_path, topology_path, num_points):
    (x_pts, y_pts) = c2c.get_curve_points(image_path)
    (x_pts, y_pts) = c2c.interpolate_points(x_pts, y_pts, num_points=num_points)
    indices = np.argsort(x_pts)
    x_pts = x_pts[indices]
    y_pts = y_pts[indices]
    print(as_cpp_array(x_pts))
    print(y_pts)

    # Load the topology data
    topology = np.genfromtxt(topology_path, delimiter=',')
    indices = np.searchsorted(topology[:, 0], x_pts, side='right') - 1
    y_pts -= topology[indices, 1]

    print(topology)
    print(indices)
    print(y_pts)

    with open('data.cpp', 'w') as file:
        file.write(f'const int num_points = {num_points};\nconst double x[num_points] = {as_cpp_array(x_pts)};\nconst double y[num_points] = {as_cpp_array(y_pts)};' )

generate_coords('Data/Images/img1.png', 'Data/Topologies/city1.csv', num_points)