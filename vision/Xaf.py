import cv2.cv2 as cv2
import time
import os
from SearchCenterMarks import Search_Marks

dirname = 'C:/Users/User/Desktop/video'
name_1 = 'EV_zawrka_2_left_line.mp4'
name_2 = 'EV_zawrka_1_right_line.mp4'
name_3 = 'EV_zawrka_3_center.mp4'
cap = cv2.VideoCapture(os.path.join(dirname,name_1))
if not cap.isOpened():
    print("Video doesn't open")
    exit()
while(True):
    ret, frame = cap.read()
    if cv2.waitKey(1) & 0xFF == ord('q') or ret == False:
        break
    mark_road = Search_Marks(frame)
    result_img = mark_road.search_contours()
    cv2.imshow('frame',result_img)
    time.sleep(0.05)
cap.release()
cv2.destroyAllWindows()





