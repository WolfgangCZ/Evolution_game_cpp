

class TestClass:
    def __init__(self, a: float) -> None:
        self.a = a

    def print_a(self) -> None:
        print(self.a)


printer = TestClass(0)
printer.print_a()

