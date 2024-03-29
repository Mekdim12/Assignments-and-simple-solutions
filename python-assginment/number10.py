import math
import calendar
import datetime


class MathematicalSubModules():

    def area_of_circle(self, radius):
        return 3.14 * radius ** 2
    
    def quadratic_equation(self, a, b, c):
        range_of_roots = b ** 2 - 4 * a * c

        range_from = (-b+(range_of_roots ** 0.5)) / 2 * a
        range_to = (-b - (range_of_roots ** 0.5)) / 2 * a

        return (range_from, range_to)    
    
    def current_month_days_in_calendar(self):
        now = datetime.datetime.now()
        year = now.year
        month = now.month
        print(calendar.month(year, month))
        return calendar.monthrange(now.year, now.month)[1]
    
    def display_trigonometric(self):
        #  define the small tolerance value for the trigonometric functions to avoid division by zero so that the value is not infinity value instead infinity is displayed as 'inf'
        epsilon = 1e-10  # small tolerance value

        angles_in_degrees = [0, 30, 45, 60, 90, 180, 270, 360]
        trig_functions = ['sin', 'cos', 'tan', 'cot', 'cosec', 'sec']
        trig_values = {func: [] for func in trig_functions}

        # display the degrees
        print(f"{'Angle':<10}", end='')
        for angle in angles_in_degrees:
            print(f"{angle:<10}", end='')
        print()

        for angle in angles_in_degrees:
            radian = math.radians(angle)
            sin = math.sin(radian)
            cos = math.cos(radian)
            tan = math.tan(radian if angle % 180 != 90 else 0)
            cot = 'inf' if abs(tan) < epsilon else 1/tan
            cosec = 'inf' if abs(sin) < epsilon else 1/sin
            sec = 'inf' if abs(cos) < epsilon else 1/cos
            # sec = 'inf' if cos == 0 else 1/cos

            trig_values['sin'].append(sin)
            trig_values['cos'].append(cos)
            trig_values['tan'].append(tan)
            trig_values['cot'].append(cot)
            trig_values['cosec'].append(cosec)
            trig_values['sec'].append(sec)

        for func, values in trig_values.items():
            print(f"{func:<10}", end='')
            for value in values:
                if value == 'inf':
                    print(f"{value:<10}", end='')
                else:
                    # Check if value is close to zero and make it positive
                    value = 0.00 if abs(value) < epsilon else value
                    print(f"{value:<10.2f}", end='')
            print()


if __name__ == "__main__":
    submodules_object = MathematicalSubModules()

    circle_radius = 5
    print(f"Area of Circle with radius {circle_radius}", submodules_object.area_of_circle(circle_radius) , end="\n\n")
    print("Quadratic equation", submodules_object.quadratic_equation(1, 2, 1), end="\n\n")
    print(submodules_object.current_month_days_in_calendar(), end="\n\n")
    submodules_object.display_trigonometric()
