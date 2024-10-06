# The problem of getting 4 points into a triangle inscribed in a circle
### Problem
An equilateral triangle is inscribed in a circle of radius R. What is the probability that four randomly placed points in this circle will be inside the triangle?
## Implementation
First of all, you need to decide how to generate point coordinates. In this case, the Cartesian coordinate system is very inconvenient. I decided to choose the polar coordinate system because it is very convenient for working with a circle. To generate a point on it, it is enough to specify the distance from the center of the circle and the polar angle (azimuth).
