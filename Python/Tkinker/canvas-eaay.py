"""canvas画布的使用方法"""

from tkinter import *
from tkinter import messagebox
import random


class Application(Frame):
    """一个经典的GUI程序的类的写法，继承Frame"""
    # 子类继承了父类，但是不会自动的调用父类的构造器，所以需要手动调用
    def __init__(self, master=None):
        super().__init__(master)        # super()代表的是父类的定义，而不是父类的对象
        self.master = master            # self需要做绑定，
        self.pack()                     # 通过布局管理器，显示到窗口上
        self.createWidget()             # 调用下一个
    def createWidget(self):
        self.canvas=Canvas(self,width=300,height=200,bg='green')
        self.canvas.pack()

        line=self.canvas.create_line(10,10,30,20,40,50) #每两位为一坐标

        rect=self.canvas.create_rectangle(50,50,100,100)

        oval=self.canvas.create_oval(50,50,100,100)

        global photo
        photo=PhotoImage(file="./01.gif")
        self.canvas.create_image(150,170,image=photo)

        Button(self,text='画10个矩形',command=self.draw50Recg).pack(side='left')

    def draw50Recg(self):
        for i in range(0, 10):
            x1 = random.randrange(int(self.canvas["width"]) / 2)
            y1 = random.randrange(int(self.canvas["height"]) / 2)
            x2 = x1 + random.randrange(int(self.canvas["width"]) / 2)
            y2 = y1 + random.randrange(int(self.canvas["height"]) / 2)
            self.canvas.create_rectangle(x1, y1, x2, y2)


if __name__ == '__main__':   # 运行的时候作为一个独立的去调用我们的方法

    root = Tk()
    root.geometry("600x600+200+300") #窗口大小和窗口位置
    root.title("canvas测试")
    app = Application(master=root) #定义一个他的父类
    root.mainloop()