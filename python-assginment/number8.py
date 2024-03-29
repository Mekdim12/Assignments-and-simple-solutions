import cs1 as cg

# Create a canvas to represent the universe
universe = cg.Canvas(800, 600, bgColor='black')

# Create the sun (white circle)
sun = cg.Circle(40)
sun.setFillColor('white')
sun.moveTo(700, 100)
universe.add(sun)

# Create the earth (green circle)
earth = cg.Circle(60)
earth.setFillColor('green')
earth.moveTo(400, 400)
universe.add(earth)

# Create the moon (light white circle)
moon = cg.Circle(30)
moon.setFillColor('lightgray')
moon.moveTo(200, 200)
universe.add(moon)

# Create a house on the earth
house = cg.Rectangle(80, 60)
house.setFillColor('brown')
house.moveTo(350, 450)
universe.add(house)

# Create a flowing river on the earth
river = cg.Path(cg.Point(300, 500), cg.Point(400, 500))
river.setBorderColor('blue')
river.setBorderWidth(5)
universe.add(river)

# Create a moving car with a highway road
highway = cg.Path(cg.Point(100, 550), cg.Point(700, 550))
highway.setBorderColor('gray')
highway.setBorderWidth(10)
universe.add(highway)

car = cg.Rectangle(60, 30)
car.setFillColor('red')
car.moveTo(100, 550)
universe.add(car)

# Create a rocket between the earth and the moon
rocket = cg.Polygon(cg.Point(400, 400), cg.Point(410, 380), cg.Point(420, 400))
rocket.setFillColor('yellow')
universe.add(rocket)

# Add light rays from the sun to the earth and moon
sunray1 = cg.Path(cg.Point(700, 100), cg.Point(400, 400))
sunray1.setBorderColor('yellow')
sunray1.setBorderWidth(2)
universe.add(sunray1)

sunray2 = cg.Path(cg.Point(700, 100), cg.Point(200, 200))
sunray2.setBorderColor('yellow')
sunray2.setBorderWidth(2)
universe.add(sunray2)

# Display the universe
universe.wait()
