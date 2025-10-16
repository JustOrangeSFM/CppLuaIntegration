print("=== MyClass Test ===")

local e = MyClass.new(50)
e:BeginPlay()
e:takeDamage = function(self, dmg)  -- пример кастомной логики
    self:setValue(self:getValue() - dmg)
    print("Took", dmg, "damage. HP:", self:getValue())
end

e:takeDamage(e, 10)  -- HP = 40

print("=== Test End ===")