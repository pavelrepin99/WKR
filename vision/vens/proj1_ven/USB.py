import serial
import struct

class  SerialUsb:
    """   
    This class is designed to work with Usb Serial
    """
    def __init__(self, com_port:str, baudrate:int):
        self.ser = serial.Serial(com_port,baudrate) 
        self.ser.isOpen()
    
    @staticmethod
    def confines(var:int,L:int,H:int):
        """
        This method limits the angle, H - high, L - low

        @param arc: angle of rotation of the servo
        @type arc: int
        @return: angle
        """
        if var > H:
            var = H
        elif var < L:
            var = L
        if(var < 0):
            var = 256 + var
        return var

    def send(self,cntr_byte:int,arc:int, speed:int): 
        """   
        This method sends the angle by usb serial
        @param arc: angle of rotation of the servo
        @type arc: int
        """
        arc = self.confines(arc,-25,25)
        speed = self.confines(speed,-20,20)
        self.ser.write(struct.pack('>3B',cntr_byte,arc,speed))

    def close_serial(self):
        """   
        This method closes usb serial
        """
        self.ser.close() 
