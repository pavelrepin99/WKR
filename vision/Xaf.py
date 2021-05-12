import cv2.cv2 as cv2
import time
import os
import logging
import inspect
from SearchCenterMarks import SearchMarks

if __name__ == "__main__":
    log = logging.getLogger(__name__)
    dirname=(os.path.dirname(inspect.getfile(inspect.currentframe())))
    name_1 = 'video\EV_zawrka_2_left_line.mp4'
    name_2 = 'video\EV_zawrka_1_right_line.mp4'
    name_3 = 'video\EV_zawrka_3_center.mp4'
    cap = cv2.VideoCapture(os.path.join(dirname,name_3))
    if not cap.isOpened():
        log.warning("Video doesn't open")
        exit()
    while(True):
        ret, frame = cap.read()
        if cv2.waitKey(1) & 0xFF == ord('q') or ret == False:
            break
        mark_road = SearchMarks(frame)
        result_img = mark_road.search_contours()
        cv2.imshow('frame',result_img)
        time.sleep(0.05)
    cap.release()
    cv2.destroyAllWindows()




