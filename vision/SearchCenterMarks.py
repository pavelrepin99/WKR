import cv2.cv2 as cv2
import numpy as np


class Search_Marks():
    """
    This class is designed to search for center road markings
    """
    def __init__(self,image:np.ndarray):
        """
        @param image
        """
        self.image = image

    def search_contours(self):
        """
        This method searches contours 

        @param image
        @return: image with found road markings
        """
        def convert(img:np.ndarray):
            """
            Сonverts the image to grayscale and applies blur and detector Canny

            @param img: image
            @return: processed image 
            """
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            blur = cv2.GaussianBlur(img,(15,15),0)
            canny = cv2.Canny(blur, 50, 150)
            return canny

        def region(img:np.ndarray):
            """
            an ROI is created and superimposed on the image

            @param img: image
            @return: image with region of interest
            """
            x1 = 100
            x2 = 500
            y1 = 200
            y2 = img.shape[0]
            polygons = np.array([[(x1,y2),(x2,y2),(x2,y1),(x1,y1)]])
            mask = np.zeros_like(img)
            cv2.fillPoly(mask,polygons,255)
            mask_pg = cv2.bitwise_and(img, mask)
            return mask_pg

        core = np.ones((3,3), np.uint8)
        frame_img = np.copy(self.image)
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
            # print(rect)
            if area != 0:
                if abs(area - (rect[2]*rect[3]))/area*100 < 180:
                    x_0 = rect[2] * 0.5
                    y_0 = rect[3] * 0.5
                    x_c = rect[0] + x_0
                    y_c = rect[1] + y_0
                    # print(x_c,y_c)
                    alpha = x_c * 0.078 - 24.96
                    alpha = round(alpha)
                    # print(alpha)
                    cv2.putText(self.image,str(alpha),(300,100),cv2.FONT_HERSHEY_SIMPLEX,3,(0,255,0),3)
                    cv2.drawContours(self.image,contour,ind[i],(0,0,255),3,cv2.LINE_AA)
        return self.image