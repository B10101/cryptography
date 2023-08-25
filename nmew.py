def point_double(x, y, p):
    s = (3 * x ** 2 + 4) * pow(2 * y, -1, p) % p
    x3 = (s ** 2 - 2 * x) % p
    y3 = (s * (x - x3) - y) % p
    return x3, y3

def point_add(x1, y1, x2, y2, p):
    s = (y2 - y1) * pow(x2 - x1, -1, p) % p
    x3 = (s ** 2 - x1 - x2) % p
    y3 = (s * (x1 - x3) - y1) % p
    return x3, y3

def generate_points(P, n, p):
    points = [P]
    current_point = P
    for _ in range(n - 1):
        current_point = point_add(current_point[0], current_point[1], P[0], P[1], p)
        points.append(current_point)
    return points

p = 19
P = (0, 1)
n = 8

points = generate_points(P, n, p)
for i, point in enumerate(points):
    print(f"{i+1}P: ({point[0]}, {point[1]})")