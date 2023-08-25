from finite_field_element import FiniteFieldElement


class ECPoint:
    """
    A point on an elliptic curve
    """
    def __init__(
        self, x: FiniteFieldElement, y: FiniteFieldElement, a: FiniteFieldElement,  b: FiniteFieldElement
    ) -> Self:
        """
        Instantiates a point on an elliptic curve in a finite field
        defined by y^2 = x^3 + ax + b
        Args:
            x : x-coordinate value
            y : y-coordinate value
            a : constant coefficient of x where y^2 = x^3 + ax + b
            b : constant where y^2 = x^3 + ax + b
        """
        self.a = a
        self.b = b
        self.x = x
        self.y = y

        # Point at Infinity
        if self.x is None and self.y is None:
            return

        if (self.y ** 2) != (self.x ** 3) + (a * x) + b:
            raise ValueError(f'({x}, {y}) is not on the curve')