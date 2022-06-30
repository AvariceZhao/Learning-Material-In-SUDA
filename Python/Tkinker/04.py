"""button的使用方法"""

from tkinter import *
from tkinter import messagebox


class Application(Frame):
    """一个经典的GUI程序的类的写法，继承Frame"""

    # 子类继承了父类，但是不会自动的调用父类的构造器，所以需要手动调用
    def __init__(self,master=None):
        super().__init__(master)        # super()代表的是父类的定义，而不是父类的对象
        self.master = master            # self需要做绑定，
        self.pack()                     # 通过布局管理器，显示到窗口上

        self.createWidget()             # 调用下一个

    def createWidget(self):
        """创建组件"""
        self.btn01 = Button(root, text="登录", command=self.login,width=6,height=3,anchor=E)
        self.btn01.pack()

        global photo  #将图片设置为按钮
        photo = PhotoImage(file="./01.gif")
        self.btn02 = Button(root, image=photo, command=self.login)
        self.btn02.pack()
        # self.btn02.config(state="disabled")  # 设置按钮为禁用

    def login(self):
        messagebox.showinfo("按钮的学习","登陆成功")  # 第一个属性是弹窗的名称 后面的是弹窗的内容


if __name__ == '__main__':   # 运行的时候作为一个独立的去调用我们的方法

    root = Tk()
    root.geometry("600x600+200+300")  # 窗口大小和窗口位置
    root.title("label测试")
    app = Application(master=root)  # 定义一个他的父类
    root.mainloop()
