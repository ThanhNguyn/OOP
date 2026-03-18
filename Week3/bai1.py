import math

class Point:
    """Represents a point in 2D space."""

    def __init__(self, x=0, y=0):  # Default values
        self.x = x
        self.y = y

    def __str__(self):
        return "(%d, %d)" % (self.x, self.y)

    def input(self):
        self.x = int(input("Enter x: "))
        self.y = int(input("Enter y: "))

    def symmetric_through_origin(self):
        return Point(-self.x, -self.y)

    def distance_to_origin(self):
        return math.sqrt(self.x ** 2 + self.y ** 2)

    def distance_to(self, other):
        return math.sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2)

# Create A(3,4) and print
A = Point(3, 4)
print("A:", A)

# Input B
B = Point()
print("print a point in 2D space:")
B.input()
print("B:", B)

# Symmetric of B through origin
C = B.symmetric_through_origin()
print("Symmetric of B through origin:", C)

# Distance from B to origin
print("Distance from B to origin:", B.distance_to_origin())

# Distance from A to B
print("Distance from A to B:", A.distance_to(B))
