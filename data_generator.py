import numpy as np
from curve_to_coordinates_ import plot as c2c

np.set_printoptions(threshold=np.inf)

num_points = 20
total_length = 3000
total_height = 1000
lowest_height_of_path = 700
height_variation_of_path = 300
maximum_height_of_topology = 600

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

    x_pts -= x_pts[0]
    x_pts *= total_length / x_pts[-1]
    y_pts -= np.min(y_pts)
    y_pts *= height_variation_of_path / (np.max(y_pts) - np.min(y_pts))
    y_pts += lowest_height_of_path

    print(x_pts)
    print(y_pts)

    # Load the topology data
    topology = np.genfromtxt(topology_path, delimiter=',')

    topology[:, 0] -= topology[0, 0]
    topology[:, 0] *= total_length / topology[-1, 0]
    topology[:, 1] = topology[:, 1] / np.max(topology[:, 1]) * maximum_height_of_topology

    indices = np.searchsorted(topology[:, 0], x_pts, side='right') - 1
    y_pts -= topology[indices, 1]

    print(topology)
    print(indices)
    print(y_pts)

    with open('data.cpp', 'w') as file:
        file.write(f'const int num_points = {num_points};\nconst double x[num_points] = {as_cpp_array(x_pts)};\nconst double y[num_points] = {as_cpp_array(y_pts)};' )

generate_coords('Data/Images/img1.png', 'Data/Topologies/city1.csv', num_points)