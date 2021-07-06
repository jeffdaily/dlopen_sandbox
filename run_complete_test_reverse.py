import two_caller
import one_caller

two = two_caller.init()
one = one_caller.init()
print(two_caller.counter())
print(one_caller.counter())
