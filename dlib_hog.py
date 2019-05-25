import dlib
import cv2
import os

def detect_face(img):
    detector = dlib.get_frontal_face_detector()
    return detector(img,1)

def get_img_list(root,img_list):
    """
    功能：递归获得给定路径下的所有文件
    参数：
        root:根目录
        img_list:存放文件路径
    返回值：img_list
    """
    if root == None:
        return
    for f in os.listdir(root):
        abs_path = os.path.join(root,f).replace('\\','/')
        print(abs_path)
        if os.path.isfile(abs_path):
            img_list.append(abs_path)
        else:
            get_img_list(abs_path,img_list)
    return img_list

if __name__ == '__main__':
    container = []
    files = get_img_list('g:/test/',container)
    print(files)
    for i in files:
        img = cv2.imread(i)
        faces = detect_face(img)
        print('图片中共检测到{}张人脸'.format(len(faces)))
        for i,face in enumerate(faces):
            print('第{}张人脸边框坐标，left: {},right: {},top: {},bottom: {}'.format(i+1,face.left(),face.right(),
                                        face.top(),face.bottom()))
            cv2.rectangle(img,tuple([face.left(),face.top()]),tuple([face.right(),face.bottom()]),(0,0,255),2)
    cv2.namedWindow("capture-face-detection")
    cv2.imshow("capture-face-detection",img)
    cv2.waitKey(0)

            

