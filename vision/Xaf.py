import cv2.cv2 as cv2
import numpy as np
import time

def convert(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(image,(15,15),0)
    canny = cv2.Canny(blur, 50, 150)
    return canny

def region(image):
    height = image.shape[0]
    x1 = 100
    x2 = 500
    y1 = 200
    y2 = height
    polygons = np.array([[(x1,height),(x2,height),(x2,y1),(x1,y1)]])
    mask = np.zeros_like(image)
    cv2.fillPoly(mask,polygons,255)
    mask_pg = cv2.bitwise_and(image, mask)
    return mask_pg

core = np.ones((3,3), np.uint8)
CAP = "C:\\Users\\User\\Desktop\\video\\EV_zawrka_2_left_line.mp4"
cap = cv2.VideoCapture(CAP)
if not cap.isOpened():
    print("Video doesn't open")
    exit()
while(True):
    ret, frame = cap.read()
    if cv2.waitKey(1) & 0xFF == ord('q') or ret == False:
        break
    frame_img = np.copy(frame)
    canny = convert(frame_img)
    reg = region(canny)
    img_dil = cv2.dilate(reg,core, iterations = 1)
    contour, hh = cv2.findContours(img_dil, cv2.RETR_TREE, cv2.CHAIN_APPROX_TC89_KCOS)
    ind = []
    for i in range(len(contour)):
        if hh[0][i][3] == -1 and hh[0][i][2] != -1 :
            ind.append(i)
    for i in range(len(ind)):
        area = cv2.contourArea(contour[ind[i]])
        rect = cv2.boundingRect(contour[ind[i]])
        print(rect)
        if area != 0:
            if abs(area - (rect[2]*rect[3]))/area*100 < 180:
                x_0 = rect[2] * 0.5
                y_0 = rect[3] * 0.5
                x_c = rect[0] + x_0
                y_c = rect[1] + y_0
                # print(x_c,y_c)
                alpha = x_c * 0.078 - 24.96
                alpha = round(alpha)
                print(alpha)
                cv2.putText(frame,str(alpha),(300,100),cv2.FONT_HERSHEY_SIMPLEX,3,(0,255,0),3)
                cv2.drawContours(frame,contour,ind[i],(0,0,255),3,cv2.LINE_AA)
    cv2.imshow('frame',frame)
    time.sleep(0.05)
cap.release()
cv2.destroyAllWindows()





