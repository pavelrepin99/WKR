
import serial

class  SerialUsb:
    """   
    This class is designed to work with Usb Serial
    """
    def __init__(self):
        self.ser = serial.Serial('COM5',115200) 
        self.ser.isOpen()
    
    @staticmethod
    def confines(ang:int):
        """
        This method limits the angle, H - high, L - low

        @param arc: angle of rotation of the servo
        @type arc: int
        @return: angle
        """
        H = 25
        L = -25
        if ang > H:
            ang = H
        elif ang < L:
            ang = L
        return ang

    def send(self,arc:int): 
        """   
        This method sends the angle by usb serial
        @param arc: angle of rotation of the servo
        @type arc: int
        """
        arc = self.confines(arc)
        if(arc < 0):
            arc = 256 + arc
            self.ser.write(bytes([arc]))
        else:
            self.ser.write(bytes([arc]))

    def close_serial(self):
        """   
        This method closes usb serial
        """
        self.ser.close() 