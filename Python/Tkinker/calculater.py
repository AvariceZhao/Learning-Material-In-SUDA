from tkinter import *
from tkinter import messagebox

class Application(Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.createWidget()
    def createWidget(self):
        btnText=(('MC','M+','M-','MR'),
             ('C','±','/','*'),
             ('7','8','9','-'),
             ('4','5','6','+'),
             ('1','2','3','='),
             ('0','.'))
        Entry(self).grid(row=0,column=0,columnspan=4,pady=10)

        for rindex,r in enumerate(btnText):
            for cindex,c in enumerate(r):
                if c == "=":
                    Button(self, text=c, width=2) \
                        .grid(row=rindex + 1, column=cindex, rowspan=2, sticky=NSEW)
                elif c == '0':
                    Button(self, text=c, width=2) \
                        .grid(row=rindex + 1, column=cindex, columnspan=2, sticky=NSEW)
                elif c == ".":
                    Button(self, text=c, width=2) \
                        .grid(row=rindex + 1, column=cindex + 1, sticky=NSEW)
                else:
                    Button(self, text=c, width=2) \
                        .grid(row=rindex + 1, column=cindex, sticky=NSEW)



if __name__ == '__main__':  # 运行的时候作为一个独立的去调用我们的方法

    root = Tk()
    root.geometry("220x220+20+300")  # 窗口大小和窗口位置
    root.title("grid测试")
    app = Application(master=root)  # 定义一个他的父类
    root.mainloop()