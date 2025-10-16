print("=== Game Start ===")

-- Создаём объекты напрямую
local base = BaseClass.new()
base:BeginPlay()
print("Base value:", base.value)

local obj = MyClass.new(42)
obj:BeginPlay()
print("Initial value:", obj:getValue())

obj:setValue(100)
print("After set:", obj.value)

obj:reset()
print("After reset:", obj:getValue())

-- Глобальные функции
print("2 + 3 =", add(2, 3))
print("Pi =", pi)

print("=== Game End ===")