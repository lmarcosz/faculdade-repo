from abc import ABC, abstractmethod

class Switchable(ABC):
    @abstractmethod
    def turn_on:
        pass
    
    @abstractmethod
    def turn_off:
        pass

class Fan(Switchable):
    def turn_on(self):
        print("Fan: turned on")

    def turn_off(self):
        print("Fan: turned off")


class LightBulb(Switchable):
    def turn_on(self):
        print("LightBulb: turned on")
    

    def turn_off(self):
        print("LightBulb: turned off")
    
class PowerSwitch:
    def __init__(self, s: Switchable):
        self.switchable = s
        self.on = False
    
    def press(self):
        if self.on:
            self.switchable.turn_off()
            self.on = False
        else:
            self.switchable.turn_on()
            self.on = True


hueBulb = LightBulb()
switch = PowerSwitch(hueBulb)
switch.press()
switch.press()
switch.press()
switch.press()

bedroomFan = Fan()
switch = PowerSwitch(bedroomFan)
