from PyQt5 import uic, QtWidgets 
import serial


# Valores padrão de ganho
kp = 0
ki = 0
kd = 0 

def sendSerial(value):
    ser = serial.Serial('/dev/ttyUSB0', baudrate=115200, timeout=1)
    ser.write(value.encode())
    ser.close()

# Buttons Functions 
def pushButton_iniciar(): 
    print("I")
    sendSerial("I")

def pushButton_parar(): 
    print("P")
    sendSerial("P")

def pushButton_ReturnHome(): 
    print("R")
    sendSerial("R")

def pushButton_CalibSensor(): 
    print("C")
    sendSerial("C")

def pushButton_Enviar(): 
    kp_str = str(screen1.lineEdit_kp.text())
    kd_str = str(screen1.lineEdit_kd.text())
    ki_str = str(screen1.lineEdit_ki.text())

    print("S" + ",kp" + kp_str + ",kd" + kd_str + ",ki" + ki_str + ",")
    sendSerial("S" + ",kp" + kp_str + ",kd" + kd_str + ",ki" + ki_str + ",")






# App Exec 
app = QtWidgets.QApplication([])
screen1 = uic.loadUi("/home/pedro/Documents/Controle/Interface/gui.ui")

# Pushbuttons 
screen1.pushButton_iniciar.clicked.connect(pushButton_iniciar)
screen1.pushButton_parar.clicked.connect(pushButton_parar)
screen1.pushButton_ReturnHome.clicked.connect(pushButton_ReturnHome)
screen1.pushButton_CalibSensor.clicked.connect(pushButton_CalibSensor)
screen1.pushButton_Enviar.clicked.connect(pushButton_Enviar)

screen1.show()
app.exec()