from tkinter import *
from tkinter import messagebox
import webbrowser




class Application(Frame):
    """一个经典的GUI程序的类写法"""
    def __init__(self,master=None):
        super().__init__(master) #super代表父类的定义，不是父类对象

        self.master=master
        self.pack()

        self.createWidget()


    def fun(self,a):
        webbrowser.open(r'F:\Study\Computer Science\Informathion Retrieval\Final\data-1k\2011“地球一小时”行动倡议书373.txt')

    def createWidget(self):
        self.label01 = Label(self, text="标签测试01", width=10, height=2, bg="black", fg="white")

        self.label01.pack()

        #字体
        self.label02 = Label(self, text="标签测试02", width=10, height=2, bg="blue", fg="white",font=("黑体",30))
        self.label02.pack()
        self.label02.bind("<Button-1>",self.fun)
        #显示图片
        global photo
        photo=PhotoImage(file="./01.gif")
        self.lable03=Label(self,image=photo)
        self.lable03.pack()

        self.lable04=Label(self,text="这是第一行\n这是第二行\n这是第三行",borderwidth=1,relief='solid',justify='right')
        self.lable04.pack()
    def songhua(self):
        messagebox.showinfo("送花", "送你玫瑰花")
        print('送你一朵花')



if __name__ == '__main__':
    root = Tk()
    root.geometry("700x700+200+300")  # 窗口大小和窗口位置
    root.title("label测试")
    app = Application(master=root)  # 定义一个他的父类
    root.mainloop()