print("=== Boss Battle ===")

local Boss = dofile("Scripts/Boss.lua")
local boss = Boss.new(200)

boss:BeginPlay()        -- унаследовано от MyClass
boss:ultimate()         -- свой метод
boss:heal(50)           -- свой метод с глобальной функцией

print("Final HP:", boss._cpp:getValue())

print("=== Battle End ===")