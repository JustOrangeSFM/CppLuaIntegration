-- Boss.lua
local Boss = {}

function Boss.new(initialValue)
    local cppObj = MyClass.new(initialValue)
    local instance = { _cpp = cppObj }
    
    local mt = {
        __index = function(t, key)
            -- Сначала свои методы
            local method = Boss[key]
            if method then return method end
            -- Потом — унаследованные от MyClass
            return t._cpp[key]
        end
    }
    setmetatable(instance, mt)
    return instance
end

-- Новые методы Boss
function Boss:ultimate()
    print("[Boss] ULTIMATE ACTIVATED!")
    self._cpp:BeginPlay()  -- вызов C++ метода
end

function Boss:heal(amount)
    local newHP = add(self._cpp:getValue(), amount)  -- глобальная функция
    self._cpp.value = newHP
    print("[Boss] Healed to", self._cpp.value)
end

return Boss