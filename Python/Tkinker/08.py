from tkinter import *
from tkinter import messagebox


class Application(Frame):
    """一个经典的GUI程序的类的写法，继承Frame"""
    # 子类继承了父类，但是不会自动的调用父类的构造器，所以需要手动调用
    def __init__(self, master=None):
        super().__init__(master)        # super()代表的是父类的定义，而不是父类的对象
        self.master = master            # self需要做绑定，
        self.pack()                     # 通过布局管理器，显示到窗口上
        self.createWidget()             # 调用下一个
    def createWidget(self):
        self.codeHobby=IntVar()
        self.vedioHobby=IntVar()

        self.c1=Checkbutton(self,text="code",variable=self.codeHobby,onvalue=1,offvalue=0)
        self.c2 = Checkbutton(self, text="video", variable=self.vedioHobby, onvalue=1, offvalue=0)
        self.c1.pack(side='left');self.c2.pack(side='left')
        Button(self,text='确定',command=self.confirm).pack(side='left')
    def confirm(self):
        if self.vedioHobby.get():
            messagebox.showinfo('msg','video')
        if self.codeHobby.get():
            messagebox.showinfo('msg','code')

if __name__ == '__main__':   # 运行的时候作为一个独立的去调用我们的方法

    root = Tk()
    root.geometry("600x600+200+300") #窗口大小和窗口位置
    root.title("复选框测试")
    app = Application(master=root) #定义一个他的父类
    root.mainloop()
